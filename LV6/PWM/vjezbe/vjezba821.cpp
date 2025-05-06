/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vje�ba 8.2.1
 */ 

#include "AVR VUB/avrvub.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Timer/timer.h"

void inicijalizacija() {
	// inicijalizacija za timer 0 - neinvertirajuci Fast PWM
	timer0_set_prescaler(TIMER0_PRESCALER_8);
	timer0_set_fast_PWM();
	timer0_OC0A_enable_non_inverted_PWM();
	
	output_port(DDRB,PB7);	
}

int main(void) {
		
	inicijalizacija();
		
	while(1) {
		OCR0A = 25;
		_delay_ms(1000);
		OCR0A = 102;
		_delay_ms(1000);
		OCR0A = 230;
		_delay_ms(1000);
	}
	return 0;
}