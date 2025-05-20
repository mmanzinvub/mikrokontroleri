/*
 Naslov: MIKROUPRAVLJACI - Programiranje mikrokontrolera AVR familije
 Autor: Zoran Vrhovski
 
 Vježba 10.1.4
 */ 

// ukljucite potrebna zaglavlja
#include <avr/io.h>
#include "AVR VUB/avrvub.h"
#include <util/delay.h>
#include "LCD/lcd.h"
#include "UART/uart.h"
#include "Interrupt/interrupt.h"
#include "DigitalIO/DigitalIO.h"
#include "Timer/timer.h"
#include "ADC/adc.h"

uint32_t vrijeme = 0;
DigitalOutput LED_crvena(B4); // pin PB4 - crvena dioda

ISR(TIMER1_OVF_vect){
	TCNT1 = 49911;
	vrijeme++; // mjerenje vremena rada uC-a
	LED_crvena.toggle(); //promjena stanja crvene diode
}

void inicijalizacija() {
	// inicijalizacija serijske komunikacije
	uart_init(19200);
	// konfiguriranje LCD displeja
	lcd_init();
	// konfiguriranje AD pretvorbe
	adc_init();
	// omoguci globalni prekid
	interrupt_enable();
	// konfiguriranje tajmera 1
	timer1_set_normal_mode();
	timer1_set_prescaler(TIMER1_PRESCALER_1024);
	timer1_interrupt_OVF_enable();
	TCNT1 = 49911;
}

int main(void) {
	inicijalizacija();
	DigitalInput Tipkalo_D0(D0); // pin PD0 - tipkalo 
	Tipkalo_D0.pullup_on(); // ukljuci pull up na PD0 
	uint16_t ADC_4, ADC_5; // vrijednost AD pretvorbe na pinu ADC4 i ADC5
	float T, U_ADC5; // temperatura i napon
	
	while(1) {
		// provjera primljenih poruka
		if(uart_read_all() == true) {
			lcd_clrscr();
			lcd_home();
			lcd_print("%s", uart_buffer);			
			// provjera da li je drugi znak '\0' - kraj stringa
			if (uart_buffer[1] == '\0') { 
				// automat stanja koji obraduje prvi znak poruke
				switch(uart_buffer[0]) {
					case 'P':
						uart_print("ATmega32U4\r");
						break;
					case 'C':
						//posalji stanje crvene LED diode
						uart_print("Stanje crvene diode je %d.\r", LED_crvena.state());
						break;
					case 'D':
						//posalji stanje tipkala na PD0
						uart_print("Stanje tipkala D0 je %d.\r", Tipkalo_D0.state());
						break;
					case 'A':
						// napravite AD pretvorbu na ADC5
						ADC_5 = adc_read(ADC5);
						// posalji ADC5
						uart_print("ADC5 = %u.\r", ADC_5);
						break;
					case 'N':
						// napravite AD pretvorbu na ADC5
						ADC_5 = adc_read(ADC5);
						// izracunajte i posaljite napon U_ADC5
						U_ADC5 = ADC_5 / 1023.0 * 5.0;
						uart_print("Napon na pinu ADC5 je %.3fV.\r", U_ADC5);
						break;
					case 'T':
						// napravite AD pretvorbu na ADC4
						ADC_4 = adc_read(ADC4);
						// izracunajte i posaljite temperaturu
						T = 3435 / (log(ADC_4 / (1023.0 - ADC_4)) + 10.861) - 273.15;
						uart_print("Temperatura je %.3f C.\r", T);
						break;
					case 'V':
						// posaljite vrijeme rada mikroupravljaca
						uart_print("Vrijeme rada mikroupravljaca je %lu s.\r", vrijeme);
						break;
					default:
						uart_print("Neispravan unos!\r");
						break;
				}
			}
		}
	}
	return 0;
}
