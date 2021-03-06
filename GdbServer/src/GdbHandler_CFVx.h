/*
 * GdbHandlerCFV1.h
 *
 *  Created on: 27 Mar 2015
 *      Author: podonoghue
 */

#ifndef SRC_GDBHANDLER_CFVx_H_
#define SRC_GDBHANDLER_CFVx_H_

#include "GdbHandlerCommon.h"

class GdbHandler_CFVx: public GdbHandlerCommon {
public:
   GdbHandler_CFVx(
         GdbInOut            *gdbInOut,
         BdmInterfacePtr      bdmInterface,
         DeviceInterfacePtr   deviceInterface,
         GdbCallback          gdbCallBackPtr,
         IGdbTty              *tty);
   virtual ~GdbHandler_CFVx();


protected:
   virtual USBDM_ErrorCode   resetTarget(DeviceData::ResetMethod resetMethod=DeviceData::resetTargetDefault) override;
   virtual void              maskInterrupts(bool disableInterrupts) override;
   virtual USBDM_ErrorCode   continueTarget(void) override;
   virtual void              writeReg(unsigned regNo, unsigned long regValue) override;

   virtual USBDM_ErrorCode   initialise() override;
   bool                      atMemoryBreakpoint();
   virtual bool              initRegisterDescription(void) override;
   virtual void              reportLocation(char mode, int reason) override;
   virtual GdbTargetStatus   pollTarget(void) override;
   GdbTargetStatus           handleHalted();
   GdbTargetStatus           handleHostedBreak();
   bool                      checkHostedBreak(uint32_t currentPC);

   virtual uint32_t          getCachedPC() override;
   virtual bool              isValidRegister(unsigned regNo) override;
   USBDM_ErrorCode           readReg(unsigned regNo, char *&buffPtr);

   GdbTargetStatus           getTargetStatus();

   virtual uint16_t          targetToNative16(uint16_t data) override;
   virtual uint32_t          targetToNative32(uint32_t data) override;
   virtual uint16_t          targetToBE16(uint16_t data) override;
   virtual uint32_t          targetToBE32(uint32_t data) override;
   virtual uint32_t          getTarget32Bits(uint8_t buff[], int offset) override;

   virtual USBDM_ErrorCode   writePC(unsigned long value) override;
   virtual USBDM_ErrorCode   readPC(unsigned long *value) override;
   virtual USBDM_ErrorCode   writeSP(unsigned long value) override;
   virtual USBDM_ErrorCode   updateTarget() override;

   virtual void debug_print_regs() override;
};

GdbHandler *createCFVxGdbHandler(GdbInOut *gdbInOut, BdmInterfacePtr bdmInterface, DeviceInterfacePtr deviceInterface, GdbHandler::GdbCallback gdbCallBackPtr, IGdbTty *tty) ;

#endif /* SRC_GDBHANDLER_CFVx_H_ */
