/*
 * LIS3DSH.c
 *
 *  Created on: Jan 26, 2021
 *      Author: Engin
 */

#include "LIS3DSH.h"
#include "main.h"
#include "spi.h"


#define SPI1CSLOW                HAL_GPIO_WritePin(ACC_CS_GPIO_Port,ACC_CS_Pin,GPIO_PIN_RESET)
#define SPI1CSHIGH               HAL_GPIO_WritePin(ACC_CS_GPIO_Port,ACC_CS_Pin,GPIO_PIN_SET)

uint8_t transmitBuffer[16];
uint8_t transmitBufLen;

/*
 * @about: LIS3DSH Read 8 bit data from register
 */
 uint8_t LIS3DSH_HAL_ReadReg8(uint8_t reg)
 {
    transmitBuffer[0] = 0x80 | reg;
    transmitBufLen = 1;
    SPI1CSLOW;

    HAL_SPI_Transmit(&hspi1,transmitBuffer,transmitBufLen,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_TX) {}

    HAL_SPI_Receive(&hspi1,transmitBuffer,transmitBufLen,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_RX){}

    SPI1CSHIGH;

    return(transmitBuffer[0]);
}

 /*
 * @about: LIS3DSH Read 8 bit data from register
 */
 uint16_t LIS3DSH_HAL_ReadReg16(uint8_t reg)
 {
    transmitBuffer[0] = 0x80 | reg;
    static uint8_t r1,r2;
    SPI1CSLOW;

    HAL_SPI_Transmit(&hspi1,transmitBuffer,1,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_TX) {}

    HAL_SPI_Receive(&hspi1,&r1,1,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_RX){}

    HAL_SPI_Receive(&hspi1,&r2,1,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_RX){}

    SPI1CSHIGH;

    return(r1|(r2<<8));
}

/*
 * @about: LIS3DSH Read 8 bit data from register
 */
uint8_t LIS3DSH_HAL_WriteReg8(uint8_t reg,uint8_t val)
{
    transmitBuffer[0] = ( ~0x80 & reg );
    transmitBuffer[1] = ( val );
    transmitBufLen = 1;
    SPI1CSLOW;
    HAL_SPI_Transmit(&hspi1,transmitBuffer,transmitBufLen,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_TX) {}
    transmitBuffer[0] = transmitBuffer[1];
    HAL_SPI_Transmit(&hspi1,transmitBuffer,transmitBufLen,5000);
    while(HAL_SPI_GetState(&hspi1)== HAL_SPI_STATE_BUSY_TX) {}
    SPI1CSHIGH;

    return(transmitBuffer[0]);
}

/*
 * @about: Read 12Bit Temperature value
 */
uint8_t LIS3DSH_HAL_ReadTemp(void)
{
    return(LIS3DSH_HAL_ReadReg8(LIS3DSH_REG_OUTT));
}
