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

	while(flagBotaoProgramacao);

	while(flagMenu) {
		if(flagBotao1Min) {
			flagBuzzer = true;
			while(flagBotao1Min) {
				cronometro.minutos ++;
				if(cronometro.minutos > 99) {
					cronometro.minutos = 0;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao5Min) {
			flagBuzzer = true;
			while(flagBotao5Min) {
				cronometro.minutos += 5;
				if(cronometro.minutos > 99) {
					cronometro.minutos = 0;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao10Min) {
			flagBuzzer = true;
			while(flagBotao10Min) {
				cronometro.minutos += 10;
				if(cronometro.minutos > 99) {
					cronometro.minutos = 0;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao20Min) {
			flagBuzzer = true;
			while(flagBotao20Min) {
				cronometro.minutos += 20;
				if(cronometro.minutos > 99) {
					cronometro.minutos = 0;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoRemove1Min) {
			flagBuzzer = true;
			while(flagBotaoRemove1Min) {
				cronometro.minutos --;
				if(cronometro.minutos > 99) {
					cronometro.minutos = 99;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao1Seg) {
			flagBuzzer = true;
			while(flagBotao1Seg) {
				cronometro.segundos ++;
				if(cronometro.segundos > 59) {
					cronometro.segundos = 0;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoRemove1Seg) {
			flagBuzzer = true;
			while(flagBotaoRemove1Seg) {
				cronometro.segundos --;
				if(cronometro.segundos > 59) {
					cronometro.segundos = 59;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoFaltaA || flagBotaoFaltaB) {
			flagBuzzer = true;
			while(flagBotaoFaltaA || flagBotaoFaltaB) {
				cronometro.decimais ++;
				if(cronometro.decimais > 9) {
					cronometro.decimais = 0;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoRemoveFaltaA || flagBotaoRemoveFaltaB) {
			flagBuzzer = true;
			while(flagBotaoRemoveFaltaA || flagBotaoRemoveFaltaB) {
				cronometro.decimais --;
				if(cronometro.decimais > 9) {
					cronometro.decimais = 9;
				}
				telaAjustaValorAtualCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoProgramacao) {
			flagBuzzer = true;
			memset(rs485EnviaBuffer, 0x00, TAMANHO_RS485_BUFFER);
			strcat(rs485EnviaBuffer, "$,01,");
			sprintfRs485(setpointCronometro.minutos, 2);
			sprintfRs485(setpointCronometro.segundos, 2);
			sprintfRs485(setpointCronometro.decimais, 1);
			strcat(rs485EnviaBuffer, ",");
			sprintfRs485(cronometro.minutos, 2);
			sprintfRs485(cronometro.segundos, 2);
			sprintfRs485(cronometro.decimais, 1);
			strcat(rs485EnviaBuffer, ",");
			sprintfRs485(tipoCronometro, 1);
			strcat(rs485EnviaBuffer, ",\r\n");

			HAL_UART_Transmit(&huart2, rs485EnviaBuffer, strlen(rs485EnviaBuffer), 300);

			salvaCronometro();
			flagMenu = false;
		}
	}

	while(flagBotaoProgramacao);
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
			flagBuzzer = true;
			while(flagBotao1Min) {
				setpointCronometro.minutos ++;
				if(setpointCronometro.minutos > 99) {
					setpointCronometro.minutos = 0;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}
		if(flagBotao5Min) {
			flagBuzzer = true;
			while(flagBotao5Min) {
				setpointCronometro.minutos += 5;
				if(setpointCronometro.minutos > 99) {
					setpointCronometro.minutos = 0;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao10Min) {
			flagBuzzer = true;
			while(flagBotao10Min) {
				setpointCronometro.minutos += 10;
				if(setpointCronometro.minutos > 99) {
					setpointCronometro.minutos = 0;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao20Min) {
			flagBuzzer = true;
			while(flagBotao20Min) {
				setpointCronometro.minutos += 20;
				if(setpointCronometro.minutos > 99) {
					setpointCronometro.minutos = 0;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoRemove1Min) {
			flagBuzzer = true;
			while(flagBotaoRemove1Min) {
				setpointCronometro.minutos --;
				if(setpointCronometro.minutos > 99) {
					setpointCronometro.minutos = 99;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotao1Seg) {
			flagBuzzer = true;
			while(flagBotao1Seg) {
				setpointCronometro.segundos ++;
				if(setpointCronometro.segundos > 59) {
					setpointCronometro.segundos = 0;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoRemove1Seg) {
			flagBuzzer = true;
			while(flagBotaoRemove1Seg) {
				setpointCronometro.segundos --;
				if(setpointCronometro.segundos > 59) {
					setpointCronometro.segundos = 59;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(flagBotaoProgrRegr) {
			flagBuzzer = true;
			while(flagBotaoProgrRegr) {
				if(tipoCronometro == REGRESSIVO) {
					tipoCronometro = PROGRESSIVO;
				}
				else {
					tipoCronometro = REGRESSIVO;
				}
				telaAjustaCronometro();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}

		if(pressAndHoldProgramacao) {
			if(pressAndHoldProgramacao >= TEMPO_PRESS_AND_WAIT) {
				pressAndHoldProgramacao = 0;
				flagBuzzer = true;
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
				flagBuzzer = true;
			}
		}
	}
}
/*=============================================================================
MENU CONFIGURAÇÃO PONTOS
==============================================================================*/
void menuConfiguracaoPontos() {
	uint8_t flagMenu = true, pressAndHoldPontosA = 0, pressAndHoldPontosB = 0, pressAndHoldRemovePontosA = 0, pressAndHoldRemovePontosB = 0;
	telaAjustaPontos();

	while(flagMenu) {
		if(flagBotaoPontoA) {
			flagBuzzer = true;
			while(flagBotaoPontoA) {
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
		}
		else {
			pressAndHoldPontosA = 0;
		}

		if(flagBotaoPontoB) {
			flagBuzzer = true;
			while(flagBotaoPontoB) {
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
		}
		else {
			pressAndHoldPontosB = 0;
		}

		if(flagBotaoRemovePontoA) {
			flagBuzzer = true;
			while(flagBotaoRemovePontoA) {
				if(pressAndHoldRemovePontosA < 10) {
					pontosEquipeA --;
				}
				else if(pressAndHoldRemovePontosA < 20) {
					pontosEquipeA -= 10;
				}
				else {
					pontosEquipeA -= 50;
				}

				if(pontosEquipeA > 999) {
					pontosEquipeA = 999;
				}

				if(pressAndHoldRemovePontosA < 20) {
					pressAndHoldRemovePontosA ++;
				}

				telaAjustaPontos();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}
		else {
			pressAndHoldRemovePontosA = 0;
		}

		if(flagBotaoRemovePontoB) {
			flagBuzzer = true;
			while(flagBotaoRemovePontoB) {
				if(pressAndHoldRemovePontosB < 10) {
					pontosEquipeB --;
				}
				else if(pressAndHoldRemovePontosB < 20) {
					pontosEquipeB -= 10;
				}
				else {
					pontosEquipeB -= 50;
				}

				if(pontosEquipeB > 999) {
					pontosEquipeB = 999;
				}

				if(pressAndHoldRemovePontosB < 20) {
					pressAndHoldRemovePontosB ++;
				}

				telaAjustaPontos();
				HAL_Delay(DEBOUNCE_HOLD);
			}
		}
		else {
			pressAndHoldRemovePontosB = 0;
		}

		if(pressAndHoldProgramacao) {
			if(pressAndHoldProgramacao >= TEMPO_PRESS_AND_WAIT) {
				pressAndHoldProgramacao = 0;
				flagMenu = false;
				flagBuzzer = true;

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
				flagBuzzer = true;
			}
		}
	}

	while(flagBotaoProgramacao);
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
			flagBuzzer = true;
			pressAndHoldProgramacao = 1;
		}
		return;
	}

	if(flagBotaoProgramacao && pressAndHoldProgramacao < TEMPO_PRESS_AND_WAIT) {
		return;
	}

	if(pressAndHoldProgramacao >= TEMPO_PRESS_AND_WAIT) {
		flagBuzzer = true;
		while(flagBotaoProgramacao);
		pressAndHoldProgramacao = 0;

		menuConfiguracaoCronometro();
		menuConfiguracaoPontos();
		telaOperacao();
	}

	pressAndHoldProgramacao = 0;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
