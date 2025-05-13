/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 9.1.1
 */ 

/*
#include <avr/io.h>
#include "AVR VUB/avrvub.h"
#include <util/delay.h>
#include "DigitalIO/DigitalIO.h"

void inicijalizacija() {

	
}

int main(void) {
	
	inicijalizacija();
	
	DigitalOutput ShiftReg_SI(C7);
	DigitalOutput ShiftReg_SCK(F1);
	DigitalOutput ShiftReg_RCK(F0);

	uint8_t number;

	for ( int n = 0; n < 4; n ++) {
		number = 0xBE;
		for(int i = 0; i < 8; i++) {
			if(number & 0x01) { // ako je bit0 == 1
				ShiftReg_SI.set(); // na SI posalji 1
			}
			else { // ako je bit0 == 0
				ShiftReg_SI.reset(); // na SI posalji 0
			}
			// rastuci brid signala SCK
			ShiftReg_SCK.set(); //SCK = 1
			_delay_us(1);
			ShiftReg_SCK.reset(); //SCK = 0
			_delay_us(1);
			
			number = number >> 1; // posmakni broj za jedan u desno
		}
	}
	
	// rastuci brid signala RCK
	ShiftReg_RCK.set(); //RCK = 1
	_delay_us(1);
	ShiftReg_RCK.reset(); //RCK = 0
	_delay_us(1);
	
	while(1) {
		
	_delay_ms(100);
	}
	return 0;
}*/

#include <avr/io.h>
#include "AVR VUB/avrvub.h"
#include <util/delay.h>
#include "DigitalIO/DigitalIO.h"

int main (void) {
	
	Shift_Bit_Register SBR (C7, F1, F0);
	uint8_t number4 = 0x66;
	uint8_t number3 = 0xF2;
	uint8_t number2 = 0xDA;
	uint8_t number1 = 0x60;
	
	for (int n = 0; n < 4; n++) {
		SBR.send_4byte(number4, number3, number2, number1);
	}
	
	// generiranje impulsa na RCK
	SBR.clock_rck();
	
	while (1) {
		
	_delay_ms(100);
	}
	
	return 0;
}