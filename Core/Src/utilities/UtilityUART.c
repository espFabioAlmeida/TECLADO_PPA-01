///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityUART
//AUTOR:      Fábio Almeida
//CRIADO:     04/08/2023
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
DEBOUNCE
==============================================================================*/
void limpaRS485Buffer() {
	contadorRS485Buffer = 0;
	memset(rs485Buffer, 0x00, TAMANHO_RS485_BUFFER);
}
/*=============================================================================
SPRINTF RS485
==============================================================================*/
void sprintfRs485(uint32_t valor, uint8_t qntdDig) {
	//Enviar 0 em qntdDig para ignorar "zeros" a esquerda
	char dataChar[9];
	memset(dataChar, 0x00, 9);
	sprintf(dataChar, "%u", valor);

	switch(qntdDig) {
		case 9:
			if(valor < 100000000) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 8:
			if(valor < 10000000) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 7:
			if(valor < 1000000) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 6:
			if(valor < 100000) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 5:
			if(valor < 10000) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 4:
			if(valor < 1000) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 3:
			if(valor < 100) {
				strcat(rs485EnviaBuffer, "0");
			}
		case 2:
			if(valor < 10) {
				strcat(rs485EnviaBuffer, "0");
			}
	}

	strcat(rs485EnviaBuffer, dataChar);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
