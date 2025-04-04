/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikroupravljaca AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 4.1.2
 */  

#include "AVR VUB/avrvub.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija() {
	
	DDRB |= (1 << PB7); // pin PB7 izlazni pin
	PORTB |= (1 << PB7); // pin PB7 pocetno u visokom stanju
	_delay_ms(1000);
	PORTB &= ~(1 << PB7);

	_delay_ms(1000);
	PORTB |= 0x80;
	_delay_ms(1000);
	PORTB &= ~0x80;

	_delay_ms(1000);
	set_port(PORTB, PB7, 1);
	_delay_ms(1000);
	set_port(PORTB, PB7, 0);
	
}

int main(void) {
	
	inicijalizacija();
	
	return 0;
}