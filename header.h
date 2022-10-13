/********************************************************************************
* header.h: Inneh�ller diverse definitioner och funktionsdeklarationer f�r
*           implementering av programmet.
* 
*           Minnesregler f�r skrivning via bitvisa operationer:
*           = medf�r tilldelning av nytt v�rde.
*           |= medf�r bitvis addition.
*           &= ~ medf�r bitvis multiplikation och invertering.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Inneh�ller definitioner av I/O-register, s�som DDRB och PORTB. */
#include <avr/interrupt.h> /* Inneh�ller funktionalitet f�r avbrott. */

/* Makrodefinitioner: */
#define LED1 1    /* Lysdiod 1 ansluten till pin 9 / PORTB1. */
#define LED2 2    /* Lysdiod 2 ansluten till pin 10 / PORTB2. */
#define BUTTON1 2 /* Tryckknapp 1 ansluten till pin 2 / PORTD2. */
#define BUTTON2 3 /* Tryckknapp 2 ansluten till pin 3 / PORTD3. */

#define LED1_ON PORTB |= (1 << LED1) /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* T�nder lysdiod 2. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2))   /* T�nder b�da lysdioder. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2)) /* Sl�cker b�da lysdioder. */

#define BUTTON1_IS_PRESSED ((PIND & (1 << BUTTON1)) != 0) /* Indikerar ifall BUTTON1 �r nedtryckt. */
#define BUTTON2_IS_PRESSED ((PIND & (1 << BUTTON2)) != 0) /* Indikerar ifall BUTTON2 �r nedtryckt. */

/* Enumerationer: */
typedef enum { false = 0, true = 1 } bool; /* Realiserar datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorn (konfigurerar I/O-portar samt aktiverar externa
*        avbrott INT0 samt INT1 p� pin 2 - 3 (PORTD2 - PORTD3).
********************************************************************************/
void setup(void);

/********************************************************************************
* led_toggle: Togglar angiven lysdiod p� I/O-port B. uint8_t �r en osignerad
*             8-bitars heltalsdatatyp, som kan lagra heltal 0 - 255, vilket �r
*             samma som 0000 0000 - 1111 1111.
*
*             - pin: Lysdiodens pin-nummer p� I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin);

#endif /* HEADER_H_ */