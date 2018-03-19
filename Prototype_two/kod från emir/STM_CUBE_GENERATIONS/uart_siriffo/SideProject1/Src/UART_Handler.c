#include "string.h"
#include "UART_Handler.h"
#include "main.h"
#include "stm32l4xx_hal.h"

//Private functions

inline void loadMsTimer (uint16_t mS);

extern g Globals;
extern UART_HandleTypeDef huart2;
extern uint8_t txBuffer[10];
extern uint8_t rxBuffer[10];
const uint8_t _ON[4] = 		{"ON\r\n"};
const uint8_t _OFF[4] = 	{"OF\r\n"};



HAL_StatusTypeDef rxUartState;

void uartCommsHandler(void)
{

		switch(uart2machine.uart2State)
		{
			case UART2_SEND:

				clearString(txBuffer);

					copyString2(_ON, txBuffer);
					HAL_NVIC_EnableIRQ(USART2_IRQn);
					HAL_UART_Transmit_IT(&huart2, txBuffer, 4);


				loadMsTimer(10000);
				uart2machine.uart2State = UART2_RECIEVE;
				break;

			case UART2_RECIEVE:
				HAL_NVIC_DisableIRQ(USART2_IRQn);
				//
				HAL_NVIC_EnableIRQ(USART2_IRQn);
				rxUartState = HAL_UART_Receive_IT(&huart2, rxBuffer, 4);
				if(rxUartState == HAL_OK)
				{
					HAL_NVIC_DisableIRQ(USART2_IRQn);

					//echo
					if(txBuffer != rxBuffer){
						copyString( *txBuffer, *rxBuffer);
						clearString(rxBuffer);
						uart2machine.uart2State = UART2_SEND;
					}

					HAL_NVIC_EnableIRQ(USART2_IRQn);
				}

				break;

			default:
				break;

		}
	}


inline void loadMsTimer (uint16_t mS)
{
	Globals.msTimer = mS;
}
