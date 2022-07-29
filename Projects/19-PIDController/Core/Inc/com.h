/*
 * com.h
 *
 *  Created on: 29 Tem 2022
 *      Author: engin
 */

#ifndef INC_COM_H_
#define INC_COM_H_

#include <stdint.h>

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define BUFFERSIZE	256

typedef struct
{
	uint32_t rxIndex;
	uint32_t txIndex;

	uint8_t rxReady;

	uint32_t rxTimeoutCounter;

	uint8_t rxBuffer[ BUFFERSIZE ];
	uint8_t txBuffer[ BUFFERSIZE ];

	uint32_t timeout;

} com_t;

void comInit ( com_t* driver, uint32_t timeout );
void comGetData ( com_t* driver, uint8_t data );
void comTimeoutCounter ( com_t* driver );
uint8_t comIsRxBufferReady ( com_t* driver );
void comRxBufferProcessed ( com_t* driver );
uint32_t comGetTxBufferIndex ( com_t* driver );
void comSetTxBufferIndex ( com_t* driver, uint32_t index );

#endif /* INC_COM_H_ */
