///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    Utility LCD
//AUTOR:      Fábio Almeida
//CIRADO:     05/02/2021
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES DO ARQUIVO
==============================================================================*/
#define TEMPO_TELA_INICIAL 2000
/*=============================================================================
TELA INICIAL
==============================================================================*/
void telaInicial() {
	uint8_t flagTrocado = false;
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("AUTOMASENSOR");
	lcdPosLc(2, 1);
	lcdEscreve("FeA");
	HAL_Delay(TEMPO_TELA_INICIAL);
	flagBuzzer = true;

	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("Teclado PPA-01");
	lcdPosLc(2, 1);
	lcdEscreve("V");
	escreveDado(VERSAO_FIRMWARE, 0, 0, 2);
	lcdEscreve(".");
	escreveDado(SUBVERSAO_FIRMWARE, 0, 0, 1);
	lcdEscreve(" OUT/2025");
	HAL_Delay(TEMPO_TELA_INICIAL);

	flagBuzzer = true;
	limpaLcd();
}
/*=============================================================================
TELA OPERACAO
==============================================================================*/
void telaOperacao() {
	lcdPosLc(1, 1);
	if(flagCronometro) {
		lcdEscreve("Cronometro: Run ");
	}
	else {
		lcdEscreve("Cronometro: Stop");
	}

	escreveDado(setpointCronometro.minutos, 2, 1, 2);
	lcdEscreve(":");
	escreveDado(setpointCronometro.segundos, 0, 0, 2);
	lcdEscreve(".");
	escreveDado(setpointCronometro.decimais, 0, 0, 1);

	if(tipoCronometro == PROGRESSIVO) {
		lcdEscreve(" Progres.");
	}
	else {
		lcdEscreve(" Regress.");
	}
}
/*=============================================================================
TELA AJUSTA VALOR ATUAL CRONOMETRO
==============================================================================*/
void telaAjustaValorAtualCronometro() {
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("COMECA COM: ");
	escreveDado(cronometro.minutos, 2, 1, 2);
	lcdEscreve(":");
	escreveDado(cronometro.segundos, 0, 0, 2);
	lcdEscreve(".");
	escreveDado(cronometro.decimais, 0, 0, 1);
}
/*=============================================================================
TELA AJUSTA CRONOMETRO
==============================================================================*/
void telaAjustaCronometro() {
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("SET: ");
	escreveDado(setpointCronometro.minutos, 1, 1, 2);
	lcdEscreve(":");
	escreveDado(setpointCronometro.segundos, 0, 0, 2);
	lcdEscreve(".");
	escreveDado(setpointCronometro.decimais, 0, 0, 1);

	lcdPosLc(2, 1);
	if(tipoCronometro == PROGRESSIVO) {
		lcdEscreve("Progressivo");
	}
	else {
		lcdEscreve("Regressivo");
	}
}
/*=============================================================================
TELA AJUSTA PONTOS
==============================================================================*/
void telaAjustaPontos() {
	limpaLcd();
	lcdPosLc(1, 1);
	lcdEscreve("Equipe A: ");
	escreveDado(pontosEquipeA, 0, 0, 3);
	lcdPosLc(2, 1);
	lcdEscreve("Equipe B: ");
	escreveDado(pontosEquipeB, 0, 0, 3);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
