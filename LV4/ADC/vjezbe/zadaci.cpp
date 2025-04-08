/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Zadaci
 */ 


#include "AVR VUB/avrvub.h"
#include "LCD/lcd.h"
#include <avr/io.h>
#include <util/delay.h>
#include "ADC/adc.h"

void inicijalizacija() {
	
	lcd_init(); // inicijalizacija lcd displeja
	adc_init(); // inicijalizacija AD pretvorbe
}

int main(void) {
	
	inicijalizacija();

	uint16_t ADC_5; // vrijednost AD pretvorbe na pinu ADC5
	float R_POT; // otpor potenciometra
	
	while(1) {
		
		ADC_5 = adc_read(ADC5); // ADC na kanalu ADC5
		
		R_POT = ADC_5 / 1023.0 * 10000.0;
		
		lcd_clrscr();
		lcd_home();
		lcd_print("ADC = %d", ADC_5);
		lcd_print("\nPOT_R = %.1f%c", R_POT, 217); //234 nije ohm
		_delay_ms(1000);
	}
	return 0;
}