/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikroupravljaca AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 4.1.4
 */  

#include "AVR VUB/avrvub.h"
#include <avr/io.h>
#include <util/delay.h>


void inicijalizacija() {
	
	DDRB |= (1 << PB4);
	PORTB |= (1 << PB4);
	
	DDRB |= (1 << PB5);
	PORTB |= (1 << PB5);

	DDRB |= (1 << PB6);
	PORTB |= (1 << PB6);
	
	DDRB |= (1 << PB7); // pin PB7 izlazni pin
	PORTB |= (1 << PB7); // pin PB7 po?etno u visokom stanju
	
}

int main(void) {
	
	inicijalizacija(); // inicijalizacija mikroupravljaca
	
	while(1) {
		PORTB ^= (1 << PB4);
		_delay_ms(100);
		PORTB ^= (1 << PB5);
		_delay_ms(100);
		PORTB ^= (1 << PB6);
		_delay_ms(100);
		PORTB ^= (1 << PB7);
		_delay_ms(100);
		
	}
	
	return 0;
}