/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikroupravljaca AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 4.1.1
 */ 

#include "AVR VUB/avrvub.h"
#include <avr/io.h>

void inicijalizacija() {
	// DDRB |=  (1 << PB7);
	output_port(DDRB, PB7);
	//PORTB |= (1 << PB7);
	set_port(PORTB, PB7, 1);
}


int main(void) {
		
	inicijalizacija();		
	
	return 0;	
}