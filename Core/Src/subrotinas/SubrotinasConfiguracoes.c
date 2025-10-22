///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasConfiguracoes
//AUTOR:      Fábio Almeida
//CIRADO:     22/10/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
#include "string.h"
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
#define DEBOUNCE_HOLD 400
/*=============================================================================
MENU CONFIGURAÇÃO VALOR ATUAL CRONOMETRO
==============================================================================*/
void menuConfiguracaoValorAtualCronometro() {
	uint8_t flagMenu = true;
	telaAjustaValorAtualCronometro();

	while(flagMenu) {
		if(flagBotao1Min) {
			cronometro.minutos ++;
			if(cronometro.minutos > 99) {
				cronometro.minutos = 0;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao5Min) {
			cronometro.minutos += 5;
			if(cronometro.minutos > 99) {
				cronometro.minutos = 0;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao10Min) {
			cronometro.minutos += 10;
			if(cronometro.minutos > 99) {
				cronometro.minutos = 0;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao20Min) {
			cronometro.minutos += 20;
			if(cronometro.minutos > 99) {
				cronometro.minutos = 0;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoRemove1Min) {
			cronometro.minutos --;
			if(cronometro.minutos > 99) {
				cronometro.minutos = 99;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao1Seg) {
			cronometro.segundos ++;
			if(cronometro.segundos > 59) {
				cronometro.segundos = 0;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoRemove1Seg) {
			cronometro.segundos --;
			if(cronometro.segundos > 59) {
				cronometro.segundos = 59;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoPontoA || flagBotaoPontoB) {
			cronometro.decimais ++;
			if(cronometro.decimais > 9) {
				cronometro.decimais = 0;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoRemovePontoA || flagBotaoRemovePontoB) {
			cronometro.decimais --;
			if(cronometro.decimais > 9) {
				cronometro.decimais = 9;
			}
			telaAjustaValorAtualCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoProgramacao) {
			memset(rs485EnviaBuffer, TAMANHO_RS485_BUFFER, 0x00);
			strcat(rs485EnviaBuffer, "$,01,");
			sprintfRs485(setpointCronometro.minutos, 3);
			sprintfRs485(setpointCronometro.segundos, 3);
			sprintfRs485(setpointCronometro.decimais, 1);
			strcat(rs485EnviaBuffer, ",");
			sprintfRs485(cronometro.minutos, 3);
			sprintfRs485(cronometro.segundos, 3);
			sprintfRs485(cronometro.decimais, 1);
			strcat(rs485EnviaBuffer, ",");
			sprintfRs485(tipoCronometro, 1);
			strcat(rs485EnviaBuffer, ",\r\n");

			HAL_UART_Transmit(&huart2, rs485EnviaBuffer, strlen(rs485EnviaBuffer), 300);
			flagMenu = false;
		}
	}
}
/*=============================================================================
MENU CONFIGURAÇÃO CRONOMETRO
==============================================================================*/
void menuConfiguracaoCronometro() {
	uint8_t flagMenu = true;
	telaAjustaCronometro();
	setpointCronometro.decimais = 0;

	while(flagMenu) {
		if(flagBotao1Min) {
			setpointCronometro.minutos ++;
			if(setpointCronometro.minutos > 99) {
				setpointCronometro.minutos = 0;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao5Min) {
			setpointCronometro.minutos += 5;
			if(setpointCronometro.minutos > 99) {
				setpointCronometro.minutos = 0;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao10Min) {
			setpointCronometro.minutos += 10;
			if(setpointCronometro.minutos > 99) {
				setpointCronometro.minutos = 0;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao20Min) {
			setpointCronometro.minutos += 20;
			if(setpointCronometro.minutos > 99) {
				setpointCronometro.minutos = 0;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoRemove1Min) {
			setpointCronometro.minutos --;
			if(setpointCronometro.minutos > 99) {
				setpointCronometro.minutos = 99;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotao1Seg) {
			setpointCronometro.segundos ++;
			if(setpointCronometro.segundos > 59) {
				setpointCronometro.segundos = 0;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoRemove1Seg) {
			setpointCronometro.segundos --;
			if(setpointCronometro.segundos > 59) {
				setpointCronometro.segundos = 59;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(flagBotaoProgrRegr) {
			if(tipoCronometro == REGRESSIVO) {
				tipoCronometro = PROGRESSIVO;
			}
			else {
				tipoCronometro = REGRESSIVO;
			}
			telaAjustaCronometro();
			HAL_Delay(DEBOUNCE_HOLD);
		}

		if(pressAndHoldProgramacao) {
			if(pressAndHoldProgramacao >= TEMPO_PRESS_AND_HOLD) {
				pressAndHoldProgramacao = 0;
				menuConfiguracaoValorAtualCronometro();
				flagMenu = false;
			}
			else if(!flagBotaoProgramacao) {
				flagMenu = false;
				pressAndHoldProgramacao = 0;
			}
		}
		else {
			if(flagBotaoProgramacao) {
				pressAndHoldProgramacao = 1;
			}
		}
	}
}
/*=============================================================================
MENU CONFIGURAÇÃO PONTOS
==============================================================================*/
void menuConfiguracaoPontos() {
	uint8_t flagMenu = true, pressAndHoldPontosA = 0, pressAndHoldPontosB = 0;
	telaAjustaPontos();

	while(flagMenu) {
		if(flagBotaoPontoA) {
			if(pressAndHoldPontosA < 10) {
				pontosEquipeA ++;
			}
			else if(pressAndHoldPontosA < 20) {
				pontosEquipeA += 10;
			}
			else {
				pontosEquipeA += 50;
			}

			if(pontosEquipeA > 999) {
				pontosEquipeA = 0;
			}

			if(pressAndHoldPontosA < 20) {
				pressAndHoldPontosA ++;
			}

			telaAjustaPontos();
			HAL_Delay(DEBOUNCE_HOLD);
		}
		else {
			pressAndHoldPontosA = 0;
		}

		if(flagBotaoPontoB) {
			if(pressAndHoldPontosB < 10) {
				pontosEquipeB ++;
			}
			else if(pressAndHoldPontosB < 20) {
				pontosEquipeB += 10;
			}
			else {
				pontosEquipeB += 50;
			}

			if(pontosEquipeB > 999) {
				pontosEquipeB = 0;
			}

			if(pressAndHoldPontosB < 20) {
				pressAndHoldPontosB ++;
			}

			telaAjustaPontos();
			HAL_Delay(DEBOUNCE_HOLD);
		}
		else {
			pressAndHoldPontosB = 0;
		}

		if(pressAndHoldProgramacao) {
			if(pressAndHoldProgramacao >= TEMPO_PRESS_AND_HOLD) {
				pressAndHoldProgramacao = 0;
				flagMenu = false;

				memset(rs485EnviaBuffer, TAMANHO_RS485_BUFFER, 0x00);
				strcat(rs485EnviaBuffer, "$,50,");
				sprintfRs485(pontosEquipeA, 3);
				strcat(rs485EnviaBuffer, ",");
				sprintfRs485(pontosEquipeB, 3);
				strcat(rs485EnviaBuffer, ",\r\n");

				HAL_UART_Transmit(&huart2, rs485EnviaBuffer, strlen(rs485EnviaBuffer), 300);
			}
			else if(!flagBotaoProgramacao) {
				flagMenu = false;
				pressAndHoldProgramacao = 0;
			}
		}
		else {
			if(flagBotaoProgramacao) {
				pressAndHoldProgramacao = 1;
			}
		}
	}
}
/*=============================================================================
CONFIGURACOES
==============================================================================*/
void menuConfiguracoes() {

	if(flagCronometro) {
		pressAndHoldProgramacao = 0;
		return;
	}

	if(!pressAndHoldProgramacao) {
		if(flagBotaoProgramacao) {
			pressAndHoldProgramacao = 1;
		}
		return;
	}

	if(flagBotaoProgramacao && pressAndHoldProgramacao < TEMPO_PRESS_AND_HOLD) {
		return;
	}

	if(pressAndHoldProgramacao >= TEMPO_PRESS_AND_HOLD) {
		flagBuzzer = true;
		while(flagBotaoProgramacao);
		pressAndHoldProgramacao = 0;

		menuConfiguracaoCronometro();
		menuConfiguracaoPontos();
		return;
	}

	pressAndHoldProgramacao = 0;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
