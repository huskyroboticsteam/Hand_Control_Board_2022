/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
uint16_t ReadCAN(CANPacket *receivedPacket){
    volatile int error = PollAndReceiveCANPacket(receivedPacket);
    if(!error){
        #ifdef CAN_LED
        CAN_LED_Write(LED_ON);
        #endif
        CAN_time_LED = 0;
        return receivedPacket->data[0];
    }
    return NO_NEW_CAN_PACKET; //Means no Packet
}

int16_t GetPWM (CANPacket* recPacket) {
    if (ReadCAN(recPacket) == ERROR_NONE) {
        int32_t PWMVal = GetPWMFromPacket(recPacket);
    }
}
/* [] END OF FILE */
