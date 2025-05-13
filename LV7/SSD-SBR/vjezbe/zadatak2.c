/*
 * zadatak2.c
 *
 * Created: 5/13/2025 4:35:27 PM
 *  Author: Matko
 */

#include <avr/io.h>
#include "AVR VUB/avrvub.h"
#include <util/delay.h>
#include "DigitalIO/DigitalIO.h"
#include "SSD i SBR/ssd_sbr.h"
#include "ADC/adc.h"

void inicijalizacija(){
	adc_init(); // inicijalizacija AD pretvorbe
}

int main(void) {
	
	inicijalizacija();
	// stvaranje objekta za posmacni registar
	Shift_Bit_Register SBR(C7, F1, F0);
	
	uint8_t d1, d2, d3, d4;
	uint16_t T;
	uint16_t ADC_4;
	
	while(1) {
		
		ADC_4 = adc_read(ADC4);
		
		T = (3435 / (log(ADC_4 / (1024.0 - ADC_4)) + 10.861)) - 273.15;
		
		// racunanje znamenaka za prikaz
		
		T = T * 100;
		
		d1 = T / 1000;
		d2 = (T / 100) % 10;
		d3 = (T / 10) % 10;
		d4 = T % 10;
		
		// slanje cetiri bajta na posmacne registre
		SBR.send_4byte(digits[d1], digits[d2] | DOT, digits[d3], digits[d4]);
		_delay_ms(200);
	}
	return 0;
}
