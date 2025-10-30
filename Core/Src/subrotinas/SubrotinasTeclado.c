///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasTeclado
//AUTOR:      Fábio Almeida
//CIRADO:     21/10/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
/*=============================================================================
SUBROTINAS TECLADO
==============================================================================*/
void comandosTeclado() {
	static uint8_t whileBotaoPontoA = false, whileBotao2PontosA = false, whileBotao3PontosA = false, whileBotaoRemovePontoA = false,
			whileBotaoFaltaA = false, whileBotaoRemoveFaltaA = false, whileBotaoTempoA = false;
	static uint8_t whileBotaoPontoB = false, whileBotao2PontosB = false, whileBotao3PontosB = false, whileBotaoRemovePontoB = false,
				whileBotaoFaltaB = false, whileBotaoRemoveFaltaB = false, whileBotaoTempoB = false;
	static uint8_t whileBotaoSoltaCronometro = false, whileBotaoParaCronometro = false, whileBotaoCampainha = false;
	static uint8_t whileBotaoZeraFaltas = false, whileBotaoZeraCronometro = false, whileBotaoZeraTudo = false;
	static uint8_t whileBotaoPeriodo = false;


	if(whileBotaoPontoA) {
		if(!flagBotaoPontoA) {
			whileBotaoPontoA = false;
		}
	}
	else {
		if(flagBotaoPontoA) {
			whileBotaoPontoA = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,02,\r\n", 7, 200);
		}
	}

	if(whileBotao2PontosA) {
		if(!flagBotao2PontosA) {
			whileBotao2PontosA = false;
		}
	}
	else {
		if(flagBotao2PontosA) {
			whileBotao2PontosA = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,03,\r\n", 7, 200);
		}
	}

	if(whileBotao3PontosA) {
		if(!flagBotao3PontosA) {
			whileBotao3PontosA = false;
		}
	}
	else {
		if(flagBotao3PontosA) {
			whileBotao3PontosA = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,04,\r\n", 7, 200);
		}
	}

	if(whileBotaoRemovePontoA) {
		if(!flagBotaoRemovePontoA) {
			whileBotaoRemovePontoA = false;
		}
	}
	else {
		if(flagBotaoRemovePontoA) {
			whileBotaoRemovePontoA = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,05,\r\n", 7, 200);
		}
	}

	if(whileBotaoFaltaA) {
		if(!flagBotaoFaltaA) {
			whileBotaoFaltaA = false;
		}
	}
	else {
		if(flagBotaoFaltaA) {
			whileBotaoFaltaA = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,06,\r\n", 7, 200);
		}
	}

	if(whileBotaoRemoveFaltaA) {
		if(!flagBotaoRemoveFaltaA) {
			whileBotaoRemoveFaltaA = false;
		}
	}
	else {
		if(flagBotaoRemoveFaltaA) {
			whileBotaoRemoveFaltaA = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,07,\r\n", 7, 200);
		}
	}

	if(whileBotaoTempoA) {
		if(!flagBotaoTempoA) {
			whileBotaoTempoA = false;
		}
	}
	else {
		if(flagBotaoTempoA) {
			whileBotaoTempoA = true;
			if(!flagCronometro) {
				flagBuzzer = true;
				HAL_UART_Transmit(&huart2, "$,08,\r\n", 7, 200);
			}
		}
	}

	if(whileBotaoPontoB) {
		if(!flagBotaoPontoB) {
			whileBotaoPontoB = false;
		}
	}
	else {
		if(flagBotaoPontoB) {
			whileBotaoPontoB = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,09,\r\n", 7, 200);
		}
	}

	if(whileBotao2PontosB) {
		if(!flagBotao2PontosB) {
			whileBotao2PontosB = false;
		}
	}
	else {
		if(flagBotao2PontosB) {
			whileBotao2PontosB = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,10,\r\n", 7, 200);
		}
	}

	if(whileBotao3PontosB) {
		if(!flagBotao3PontosB) {
			whileBotao3PontosB = false;
		}
	}
	else {
		if(flagBotao3PontosB) {
			whileBotao3PontosB = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,11,\r\n", 7, 200);
		}
	}

	if(whileBotaoRemovePontoB) {
		if(!flagBotaoRemovePontoB) {
			whileBotaoRemovePontoB = false;
		}
	}
	else {
		if(flagBotaoRemovePontoB) {
			whileBotaoRemovePontoB = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,12,\r\n", 7, 200);
		}
	}

	if(whileBotaoFaltaB) {
		if(!flagBotaoFaltaB) {
			whileBotaoFaltaB = false;
		}
	}
	else {
		if(flagBotaoFaltaB) {
			whileBotaoFaltaB = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,13,\r\n", 7, 200);
		}
	}

	if(whileBotaoRemoveFaltaB) {
		if(!flagBotaoRemoveFaltaB) {
			whileBotaoRemoveFaltaB = false;
		}
	}
	else {
		if(flagBotaoRemoveFaltaB) {
			whileBotaoRemoveFaltaB = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,14,\r\n", 7, 200);
		}
	}

	if(whileBotaoTempoB) {
		if(!flagBotaoTempoB) {
			whileBotaoTempoB = false;
		}
	}
	else {
		if(flagBotaoTempoB) {
			whileBotaoTempoB = true;
			if(!flagCronometro) {
				flagBuzzer = true;
				HAL_UART_Transmit(&huart2, "$,15,\r\n", 7, 200);
			}
		}
	}

	if(whileBotaoSoltaCronometro) {
		if(!flagBotaoSoltaCronometro) {
			whileBotaoSoltaCronometro = false;
		}
	}
	else {
		if(flagBotaoSoltaCronometro) {
			whileBotaoSoltaCronometro = true;
			flagCronometro = true;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,16,\r\n", 7, 200);
			telaOperacao();
		}
	}

	if(whileBotaoParaCronometro) {
		if(!flagBotaoParaCronometro) {
			whileBotaoParaCronometro = false;
		}
	}
	else {
		if(flagBotaoParaCronometro) {
			whileBotaoParaCronometro = true;
			flagCronometro = false;
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,17,\r\n", 7, 200);
			telaOperacao();
		}
	}

	if(whileBotaoCampainha) {
		if(!flagBotaoCampainha) {
			whileBotaoCampainha = false;
		}
	}
	else {
		if(flagBotaoCampainha) {
			whileBotaoCampainha = true;
			if(!flagCronometro) {
				flagBuzzer = true;
				HAL_UART_Transmit(&huart2, "$,18,\r\n", 7, 200);
			}
		}
	}

	if(whileBotaoZeraFaltas) {
		if(!flagBotaoZeraFalta) {
			whileBotaoZeraFaltas = false;
			pressAndHoldZeraFaltas = 0;
		}
	}
	else {
		if(pressAndHoldZeraFaltas >= TEMPO_PRESS_AND_WAIT) {
			whileBotaoZeraFaltas = true;
			if(!flagCronometro) {
				flagBuzzer = true;
				HAL_UART_Transmit(&huart2, "$,19,\r\n", 7, 200);
			}
		}
	}

	if(whileBotaoZeraCronometro) {
		if(!flagBotaoZeraCronometro) {
			whileBotaoZeraCronometro = false;
			pressAndHoldZeraCronometro = 0;
		}
	}
	else {
		if(pressAndHoldZeraCronometro >= TEMPO_PRESS_AND_WAIT) {
			whileBotaoZeraCronometro = true;
			if(!flagCronometro) {
				flagBuzzer = true;
				HAL_UART_Transmit(&huart2, "$,20,\r\n", 7, 200);
			}
		}
	}

	if(whileBotaoZeraTudo) {
		if(!flagBotaoZeraTudo) {
			whileBotaoZeraTudo = false;
			pressAndHoldZeraTudo = 0;
		}
	}
	else {
		if(pressAndHoldZeraTudo >= TEMPO_PRESS_AND_WAIT) {
			whileBotaoZeraTudo = true;
			if(!flagCronometro) {
				flagBuzzer = true;
				HAL_UART_Transmit(&huart2, "$,21,\r\n", 7, 200);
			}
		}
	}

	if(whileBotaoPeriodo) {
		if(!flagBotaoPeriodo) {
			whileBotaoPeriodo = false;
			pressAndHoldPeriodo = 0;
		}
	}
	else {
		if(flagBotaoPeriodo && !pressAndHoldPeriodo) {
			flagBuzzer = true;
			pressAndHoldPeriodo = 1;
		}
		if(pressAndHoldPeriodo >= TEMPO_PRESS_AND_HOLD) { //Hold
			flagBuzzer = true;
			HAL_UART_Transmit(&huart2, "$,23,\r\n", 7, 200);
			whileBotaoPeriodo = true;
		}
		if(!flagBotaoPeriodo && pressAndHoldPeriodo) {
			if(pressAndHoldPeriodo < TEMPO_PRESS_AND_HOLD) { //Press
				HAL_UART_Transmit(&huart2, "$,22,\r\n", 7, 200);
			}
			whileBotaoPeriodo = false;
			pressAndHoldPeriodo = 0;
		}
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
