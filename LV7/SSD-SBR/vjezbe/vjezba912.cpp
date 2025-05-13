/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vje�ba 9.1.2
 */ 

#include <avr/io.h>
#include "AVR VUB/avrvub.h"
#include <util/delay.h>
#include "DigitalIO/DigitalIO.h"

int main(void) {

	// stvaranje objekta za posmacni registar
	Shift_Bit_Register SBR(C7, F1, F0);
	
	// heksadecimalni kodovi znakova sa slika 9.10 i 9.11
	uint8_t signs1[4] = {0b10011100, 0b01101110, 0b00001100, 0b11001110};
	uint8_t signs2[4] = {0b11110010, 0b11011010, 0b01111100, 0b01100110};
			
	while(1) {
		// posalji znakove sa slike 9.10
		for(int n = 0; n < 4; n++) {
			SBR.send_1byte(signs1[n]);
		}
		SBR.clock_rck(); // generiranje impulsa na RCK 
		_delay_ms(1000);
		
		// posalji znakove sa slike 9.11
		SBR.send_4byte(signs2[0], signs2[1], signs2[2], signs2[3]);
		_delay_ms(1000);
	}
	return 0;
}

