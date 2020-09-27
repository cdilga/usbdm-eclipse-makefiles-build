/*! \file
    \brief Low-level USB interface to BDM module .

*/

#include <stdint.h>

#include "USBDM_API.h"

#define DEFAULT_USB_TIMEOUT_VALUE (500) // ms

typedef struct {
   uint16_t vid;
   uint16_t pid;
} UsbId;

USBDM_ErrorCode bdm_usb_init(void);
USBDM_ErrorCode bdm_usb_exit(void);
USBDM_ErrorCode bdm_usb_findDevices(unsigned *devCount, const UsbId usbIds[]);
USBDM_ErrorCode bdm_usb_getStringDescriptor(int index, char *deviceDescription, unsigned maxLength);
USBDM_ErrorCode bdm_usb_releaseDevices(void);
USBDM_ErrorCode bdm_usb_getDeviceCount(unsigned int *deviceCount);
USBDM_ErrorCode bdm_usb_open(unsigned int device_no);
USBDM_ErrorCode bdm_usb_close(void);
USBDM_ErrorCode bdm_usb_send_ep0(const unsigned char * data);
USBDM_ErrorCode bdm_usb_recv_ep0(unsigned char *data, unsigned *actualRxSize=0);
USBDM_ErrorCode bdm_usb_raw_send_ep0(unsigned int  request,
                                     unsigned int  wValue,
                                     unsigned int  wIndex,
                                     unsigned int  size,
                                     const unsigned char *data,
									 unsigned int  timeout=DEFAULT_USB_TIMEOUT_VALUE);
USBDM_ErrorCode bdm_usb_raw_recv_ep0(unsigned int  request,
                                     unsigned int  wValue,
                                     unsigned int  wIndex,
                                     unsigned int  size,
                                     unsigned char *data,
									 unsigned int  timeout=DEFAULT_USB_TIMEOUT_VALUE);
USBDM_ErrorCode bdm_usb_recv_epIn(unsigned int count,
                                  unsigned char *data);
USBDM_ErrorCode bdm_usb_send_epOut(unsigned int count,
                                   const unsigned char *data);
USBDM_ErrorCode bdm_usb_transaction(unsigned int   txSize,
                                    unsigned int   rxSize,
                                    unsigned char *data,
                                    unsigned int   timeout=DEFAULT_USB_TIMEOUT_VALUE /* ms */,
                                    unsigned int  *actualRxSize = 0);
// Used if actual rxSize is needed
CPP_DLL_LOCAL
inline USBDM_ErrorCode bdm_usb_transaction(unsigned int   txSize,
                                           unsigned int  *rxSize,
                                           unsigned char *data,
                                           unsigned int   timeout=DEFAULT_USB_TIMEOUT_VALUE /* ms */) {
   return bdm_usb_transaction(txSize,
                              *rxSize,
                              data,
                              timeout,
                              rxSize);
}
USBDM_ErrorCode bdm_usb_getversion(uint8_t usb_data[10], unsigned *rxSize=0);

//**********************************************************
//!
//! Sleep for given number of milliseconds (or longer!)
//!
//! @param milliSeconds - number of milliseconds to sleep
//!
void milliSleep(int milliSeconds);

