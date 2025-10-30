///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityTeclado
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
DESLIGA SAIDAS TECLADO
==============================================================================*/
void desligaSaidasTeclado() {
	off(TECLADO_L1_GPIO_Port, TECLADO_L1_Pin);
	off(TECLADO_L2_GPIO_Port, TECLADO_L2_Pin);
	off(TECLADO_L3_GPIO_Port, TECLADO_L3_Pin);
	off(TECLADO_L4_GPIO_Port, TECLADO_L4_Pin);
	off(TECLADO_L5_GPIO_Port, TECLADO_L5_Pin);
}
/*=============================================================================
ACIONA SAIDA TECLADO
==============================================================================*/
void acionaSaidaTeclado(uint8_t saida) {
	desligaSaidasTeclado();

	switch(saida) {
		case 0: on(TECLADO_L1_GPIO_Port, TECLADO_L1_Pin); break;
		case 1: on(TECLADO_L2_GPIO_Port, TECLADO_L2_Pin); break;
		case 2: on(TECLADO_L3_GPIO_Port, TECLADO_L3_Pin); break;
		case 3: on(TECLADO_L4_GPIO_Port, TECLADO_L4_Pin); break;
		case 4: on(TECLADO_L5_GPIO_Port, TECLADO_L5_Pin); break;
	}
}
/*=============================================================================
LEITURA TECLADO
==============================================================================*/
void leituraTeclado() {
	static uint8_t saida = 0;
	uint8_t statusC1 = false, statusC2 = false, statusC3 = false, statusC4 = false, statusC5 = false, statusC6 = false;
	acionaSaidaTeclado(saida);

	statusC1 = input(TECLADO_C1_GPIO_Port, TECLADO_C1_Pin);
	statusC2 = input(TECLADO_C2_GPIO_Port, TECLADO_C2_Pin);
	statusC3 = input(TECLADO_C3_GPIO_Port, TECLADO_C3_Pin);
	statusC4 = input(TECLADO_C4_GPIO_Port, TECLADO_C4_Pin);
	statusC5 = input(TECLADO_C5_GPIO_Port, TECLADO_C5_Pin);
	statusC6 = input(TECLADO_C6_GPIO_Port, TECLADO_C6_Pin);

	switch(saida) {
		case 0:
			flagBotaoProgramacao = statusC1;
			flagBotao5Min = statusC2;
			flagBotao20Min = statusC3;
			flagBotaoFaltaA = statusC4;
			flagBotaoPontoA = statusC5;
			flagBotao2PontosA = statusC6;
			break;

		case 1:
			flagBotaoProgrRegr = statusC1;
			flagBotao10Min = statusC2;
			flagBotaoZeraTudo = statusC3;
			flagBotaoRemoveFaltaA = statusC4;
			flagBotaoRemovePontoA = statusC5;
			flagBotao3PontosA = statusC6;
			break;

		case 2:
			flagBotaoTempoA = statusC1;
			flagBotaoCampainha = statusC2;
			flagBotaoSoltaCronometro = statusC3;
			flagBotaoTempoB = statusC4;
			flagBotaoPeriodo = statusC5;
			flagBotaoParaCronometro = statusC6;
			break;

		case 3:
			flagBotao1Min = statusC1;
			flagBotao1Seg = statusC2;
			flagBotaoZeraFalta = statusC3;
			flagBotaoFaltaB = statusC4;
			flagBotaoPontoB = statusC5;
			flagBotao2PontosB = statusC6;
			break;

		case 4:
			flagBotaoRemove1Min = statusC1;
			flagBotaoRemove1Seg = statusC2;
			flagBotaoZeraCronometro = statusC3;
			flagBotaoRemoveFaltaB = statusC4;
			flagBotaoRemovePontoB = statusC5;
			flagBotao3PontosB =statusC6;
			break;
	}

	saida ++;
	if(saida > 4) {
		saida = 0;
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
