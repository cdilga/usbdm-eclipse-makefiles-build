/**
 * @file     pn532.cpp
 * @brief    Interface for PN532 NFC Chip
 *
 * @version  V4.11.1.70
 * @date     28 Dec 2015
 */
#include <string.h>
#include "pn532.h"

namespace USBDM {

/**
 * Wait for PN532 ready
 *
 * @param  timeout Timeout value to use in milliseconds
 *
 * @return true => NFC is ready, false => timeout waiting for ready
 */
bool PN532Base::waitReady(int timeout) {
   USBDM::gpio_D0::set();

   // Convert duration to DWT ticks
   int64_t delayct = ((uint64_t)timeout * SystemCoreClock) / 1000;

   // Get current tick
   uint32_t last = DWT->CYCCNT;
   bool ready;
   do {
      enable();
      uint8_t data[] = {STATUS_READ, 0x00};
      spi->txRxBytes(sizeof(data), data, data);
      disable();

      // Should test bit 0 only but PN532 often returns 0xFF on error!
      ready = (data[1] == 0x01);
      if (ready) {
         break;
      }
      // Decrement time elapsed
      // Note: This relies on the loop executing in less than the roll-over time
      // of the counter i.e. (2^32)/SystemCoreClock
      uint32_t now = DWT->CYCCNT;
      delayct -= (uint32_t)(now-last);
      // Save for next increment
      last = now;
   } while (delayct > 0);

   USBDM::gpio_D0::clear();
   return ready;
}
/**
 * Transmit command to PN532.
 * The command is wrapped in the required pre/post-amble
 *
 * @code
 * Format of data sent:
 *        0     1     2     3     4     5     6    7                    L-3   L-2   L-1
 *       00    00    FF   LEN   LCS   TFI   cmd  (data[0]...data[length-1])]  DCS    00
 *
 * bytes 0..7, L-3..L-1 are determined by routine
 * @endcode
 *
 * @param command    Command byte to transmit
 * @param length     Length of data (data[0]...data[length-1])
 * @param dataOut    Data to transmit
 */
void PN532Base::txCommand(uint8_t command, unsigned length, const uint8_t dataOut[]) {
   enable();
   USBDM::waitUS(1000);
   spi->txRx(DATA_WRITE);
   spi->txRx(IDLE);
   spi->txRx(IDLE);
   spi->txRx(PREAMBLE);
   spi->txRx(length+2);
   spi->txRx((uint8_t)(0-(length+2)));
   spi->txRx(HOST_TO_NFC);
   uint8_t checksum = HOST_TO_NFC;
   spi->txRx(command);
   checksum += command;
   for (unsigned index=0; index < length; index++) {
      spi->txRx(dataOut[index]);
      checksum += dataOut[index];
   }
   spi->txRx((uint8_t)(0x00 - checksum));
   spi->txRx(IDLE);
   disable();
}
/**
 * Get data from NFC
 *
 * @param length     Length of data
 * @param dataIn     Buffer for data received
 * @param timeout    Timeout value to use in milliseconds
 *
 * @return true => data received, false => Reception failed
 */
bool PN532Base::rxData(unsigned length, uint8_t dataIn[], int timeout) {
   bool isComplete = false;
   if (!waitReady()) {
      return false;
   }
   enable();
   do {
      USBDM::waitUS(1000);
      spi->txRx(DATA_READ);
      bool preamble1Found = false;
      unsigned index;
      for (index=0; index < 5; index++) {
         uint8_t data = spi->txRx(0);
         if (preamble1Found && (data == 0xFF)) {
            break;
         }
         preamble1Found = (data == 0x00);
      }
      if (index >= 5) {
         continue;
      }
      for (unsigned index=0; index < length; index++) {
         dataIn[index] = spi->txRx(0);
      }
      isComplete = true;
   } while (false);
   disable();
   return isComplete;
}
/**
 * Get response from NFC
 *
 * @param expectedCmd  Expected command value in response
 * @param length       Length of data
 * @param dataIn       Buffer for data received
 * @param timeout      Timeout value to use in milliseconds
 *
 * @return true => data received, false => Reception failed
 */
bool PN532Base::rxResponse(uint8_t expectedCmd, int length, uint8_t dataIn[], int timeout) {
   bool isComplete = false;
   if (!waitReady(timeout)) {
      return false;
   }
   enable();
   do {
      USBDM::waitUS(1000);
      spi->txRx(DATA_READ);
      bool preamble1Found = false;
      unsigned index;
      for (index=0; index < 5; index++) {
         uint8_t data = spi->txRx(0);
         if (preamble1Found && (data == 0xFF)) {
            break;
         }
         preamble1Found = (data == 0x00);
      }
      if (index >= 5) {
         continue;
      }
      uint8_t rxLength = spi->txRx(0);
      if ((uint8_t)(rxLength + spi->txRx(0)) != 0) {
         continue;
      }
      if (length > (rxLength-2)) {
         // Truncate to useful data
         length = rxLength-2;
      }
      if (spi->txRx(0) != NFC_TO_HOST) {
         continue;
      }
      if (spi->txRx(0) != expectedCmd) {
         continue;
      }
      uint8_t checksum = NFC_TO_HOST + expectedCmd;
      for (int index=0; index < (rxLength-1); index++) {
         uint8_t data = spi->txRx(0);
         if (index<length) {
            dataIn[index] = data;
         }
         checksum += data;
      }
      if ((checksum) != 0) {
         continue;
      }
      isComplete = true;
   } while (false);
   disable();
   return isComplete;
}
/**
 * Gets ACK message from NFC
 *
 * @return true => ACK received, false => No ACK
 */
bool PN532Base::getAck() {
   uint8_t dataIn[2] = {};
   rxData(sizeof(dataIn), dataIn);
   return (dataIn[0] == 0x00) && (dataIn[1] == 0xFF);
}

/**
 * Internal Struct for getGeneralStatus()
 *
 * Having a variable length response with a fixed field at the end is really stupid!
 */
struct _GeneralStatus1Target {
   uint8_t err;   //!< Error code
   uint8_t field; //!< RF field indicator
   uint8_t nbTg;  //!< Number of targets currently controlled (<= 2)
   struct {
      uint8_t tg;
      uint8_t brRx;
      uint8_t brTx;
      uint8_t type;
   } targetStatus[1];
   uint8_t samStatus; // SAM status if 1 targets
};

/**
 * Internal Struct for getGeneralStatus()
 *
 * Having a variable length response with a fixed field at the end is really stupid!
 */
struct _GeneralStatus2Target {
   uint8_t err;   //!< Error code
   uint8_t field; //!< RF field indicator
   uint8_t nbTg;  //!< Number of targets currently controlled (<= 2)
   struct {
      uint8_t tg;
      uint8_t brRx;
      uint8_t brTx;
      uint8_t type;
   } targetStatus[2];
   uint8_t samStatus; // SAM status if 2 targets
};

 /**
  * Get General Status
  *
  * @param status Status from PN532
  *
  * @return true => success, false => fail
  */
 bool PN532Base::getGeneralStatus(GeneralStatus &status) {
    if (!txCommandWithAck(CMD_GET_GENERAL_STATUS)) {
       return false;
    }
    memset(&status, 0, sizeof(status));
    bool rc = rxResponse(CMD_GET_GENERAL_STATUS+1, sizeof(status), (uint8_t *)&status);

    // Having a variable length response with a fixed field at the end is really stupid!
    uint8_t samStatus;
    if (rc) {
       switch (status.nbTg) {
       case 1:
          samStatus       = ((_GeneralStatus1Target*)&status)->samStatus;
          memcpy(status.targetStatus, ((_GeneralStatus1Target*)&status)->targetStatus, 4);
          status.samStatus = samStatus;
          break;
       case 2:
          samStatus       = ((_GeneralStatus2Target*)&status)->samStatus;
          memcpy(status.targetStatus, ((_GeneralStatus2Target*)&status)->targetStatus, 8);
          status.samStatus = samStatus;
          break;
       default:
          break;
       }
    }
    return rc;
 }

 const uint8_t PN532Base::ACK_MSG[]  = {0x00, 0xFF, 0x00, 0xFF, 0x00, };
 const uint8_t PN532Base::NACK_MSG[] = {0x00, 0xFF, 0xFF, 0x00, 0x00, };

 /**
  * @}
  */

} // End namespace USBDM