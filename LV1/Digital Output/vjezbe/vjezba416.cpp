/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikroupravljaca AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 4.1.6
 */  

#include "AVR VUB/avrvub.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija() {
	
	DDRB |= (1 << PB7) | (1 << PB6) | (1 << PB5) | (1 << PB4); // PB7, PB6, PB5 i PB4 izlazni pinovi
	PORTB |= (1 << PB4); // postavljanje PB7 u visoko stanje
	
	DDRF |= (1 << PF4); //pin PF4 za Buzzer 
}

int main(void) {
	
	inicijalizacija(); // inicijalizacija mikroupravljaca
	
	for (int i = 0; i < 5; i++) { // petlja koja se izvodi 50 puta
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
	// ovdje ugasiti crvenu LED diodu
	PORTB ^= (1 << PB4);
	
	// ovdje ukljuciti Buzzer
	PORTF ^= (1 << PF4);
	BUZZ(10000, 1000);
	
	return 0;	
}