/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikroupravljaca AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 4.1.5
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
	
	while (1) { // beskonaèna petlja 
	
		for (int i = 4; i <= 7; i++) {
			
			_delay_ms(100);
			
			PORTB &= ~(1 << i);
			
			if (i != 7) {
				PORTB |= (1 << (i+1));
			}
			else {
				PORTB |= (1 << PB4);
			}
		}
	}
	return 0;
}