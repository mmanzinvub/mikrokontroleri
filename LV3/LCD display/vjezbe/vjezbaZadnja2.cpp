/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 5.1.2
 */ 

#include "AVR VUB/avrvub.h"
#include "LCD/lcd.h"
#include "DigitalIO/DigitalIO.h"
#include <avr/io.h>
#include <util/delay.h>

void inicijalizacija() {
	
	lcd_init(); // inicijalizacija lcd displeja
	
}

int main(void) {
	
	inicijalizacija();
	
	DigitalOutput plava(B7); // stvori objekt plava za diodu na pinu PB7
	DigitalOutput zelena(B6); // stvori objekt zelena za diodu na pinu PB6
	DigitalOutput zuta(B5); // stvori objekt zuta za diodu na pinu PB5
	DigitalOutput crvena(B4); // stvori objekt crvena za diodu na pinu PB4
	
	DigitalInput tipkalo1(D0); // stvori objekt tipkalo1 za tipkalo na pinu PD0
	DigitalInput tipkalo2(D1); // stvori objekt tipkalo1 za tipkalo na pinu PD1
	DigitalInput tipkalo3(F6); // stvori objekt tipkalo1 za tipkalo na pinu PF6
	DigitalInput tipkalo4(F7); // stvori objekt tipkalo1 za tipkalo na pinu PF7
	
	tipkalo1.pullup_on();
	tipkalo2.pullup_on();
	tipkalo3.pullup_on();
	tipkalo4.pullup_on();
	
	// deklaracija podataka
	
	while (1) {
		if (tipkalo1.isFalling_edge() == true) {
			lcd_instr(LCD_ENTRY_INC_SHIFT);
			lcd_instr(LCD_MOVE_DISP_UP);
			_delay_ms(2000);
		}
		
		if (tipkalo1.isFalling_edge() == true) {
			lcd_instr(LCD_ENTRY_INC_SHIFT);
			lcd_instr(LCD_MOVE_DISP_DOWN);
			_delay_ms(2000);
		}
		
		
	}
	return 0;	
}