/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 4.2.6
 */  
#include "AVR VUB/avrvub.h"
#include "DigitalIO/DigitalIO.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
	
	// instance objekata digitalnih izlaza
	DigitalOutput plava(B7); // stvori objekt plava za diodu na pinu PB7
	DigitalOutput zelena(B6); // stvori objekt zelena za diodu na pinu PB6
	DigitalOutput zuta(B5); // stvori objekt zuta za diodu na pinu PB5
	DigitalOutput crvena(B4); // stvori objekt crvena za diodu na pinu PB4

	// instance objekata digitalnih ulaza
	DigitalInput tipkalo1(D0); // stvori objekt tipkalo1 za tipkalo na pinu PD0
	DigitalInput tipkalo2(D1);
	DigitalInput tipkalo3(F6);
	DigitalInput tipkalo4(F7);
	// instancirati ostale digitalne ulaze
	
	tipkalo1.pullup_on(); //ukljuci pull up za pin PD0
	tipkalo2.pullup_on();
	tipkalo3.pullup_on();
	tipkalo4.pullup_on();
	//ukljuciti ostale pull up otpornike
	
	uint8_t brojac = 0;
	
	while (1) {
		
		//ZAD1 drzi tipkalo 1 i tipkalo 2 da upalis crvenu diodu
		/*
		if(tipkalo1.state() == false && tipkalo2.state() == false) {
			crvena.on();
		}
		else {
			crvena.off();
		}
		*/
		
		//ZAD2 tipkalo 3 stisni 5 puta da upalis zelenu diodu
		
		if (tipkalo3.isFalling_edge() == true) {
			brojac++;
		}
		
		if (brojac == 5) {
			zelena.toggle();
		}
		
		
		//ZAD3 tipk1 drzi 2sec da upalis led diodu, tipk2 drzi 1sec da upalis led diodu, itd.
		/*
		if(tipkalo1.state() == false) {
			_delay_ms(2000);
			zuta.toggle();
		}
		
		if(tipkalo2.state() == false) {
			_delay_ms(1000);
			zuta.toggle();
		}
		
		if(tipkalo3.state() == false) {
			_delay_ms(500);
			zuta.toggle();
		}
		
		if(tipkalo4.state() == false) {
			_delay_ms(250);
			zuta.toggle();
		}
		*/
		
		//ZAD4 tipkalo 1 drzi 3sec da promjeni stanje led diode
		/*
		if(tipkalo1.filtered_state(false, 3000) == false) {
			zuta.toggle();
		}
		*/
		
		//ZAD5 
		
		
		
    }
	return 0;
}

