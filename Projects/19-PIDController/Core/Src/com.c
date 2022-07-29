/*
 * com.c
 *
 *  Created on: 29 Tem 2022
 *      Author: engin
 */

#include "com.h"

void comInit ( com_t* driver, uint32_t timeout )
{
	uint32_t i = 0;

	driver->rxIndex = 0;
	driver->txIndex = 0;

	driver->rxReady = FALSE;

	driver->timeout = timeout;
	driver->rxTimeoutCounter = 0;

	for ( i = 0; i < BUFFERSIZE; ++i )
	{
		driver->rxBuffer[ i ] = 0;
		driver->txBuffer[ i ] = 0;
	}
}

void comGetData ( com_t* driver, uint8_t data )
{
	if ( driver->rxReady == FALSE )
	{
		if ( driver->rxIndex == 0 )
		{
			if ( data == 'A' )
			{
				driver->rxBuffer[ driver->rxIndex ] = data;
				++driver->rxIndex;
			}
			else
			{
				driver->rxIndex = 0;
				driver->rxTimeoutCounter = 0;
			}
		}
		else if ( driver->rxIndex == 1 )
		{
			if ( data == 'T' )
			{
				driver->rxBuffer[ driver->rxIndex ] = data;
				++driver->rxIndex;
			}
			else
			{
				driver->rxIndex = 0;
				driver->rxTimeoutCounter = 0;
			}
		}
		else
		{
			driver->rxBuffer[ driver->rxIndex ] = data;
			++driver->rxIndex;

			if ( ( driver->rxBuffer[ driver->rxIndex - 2 ] == '\r' ) && ( driver->rxBuffer[ driver->rxIndex - 1 ] == '\n' ) )
			{
				driver->rxReady = TRUE;
				driver->rxTimeoutCounter = 0;
				driver->rxBuffer[ driver->rxIndex ] = 0;
			}
		}
	}
}

void comTimeoutCounter ( com_t* driver )
{
	if ( ( driver->rxIndex != 0 ) && ( driver->rxReady == FALSE ) )
	{
		++driver->rxTimeoutCounter;

		if ( driver->rxTimeoutCounter > driver->timeout )
		{
			driver->rxIndex = 0;
			driver->rxTimeoutCounter = 0;
		}
	}
}

uint8_t comIsRxBufferReady ( com_t* driver )
{
	return ( driver->rxReady );
}

void comRxBufferProcessed ( com_t* driver )
{
	driver->rxReady = FALSE;
	driver->rxIndex = 0;
}

uint32_t comGetTxBufferIndex ( com_t* driver )
{
	return ( driver->txIndex );
}

void comSetTxBufferIndex ( com_t* driver, uint32_t index )
{
	driver->txIndex = index;
}
