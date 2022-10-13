/********************************************************************************
* header.h: Innehåller diverse definitioner och funktionsdeklarationer för
*           implementering av programmet.
* 
*           Minnesregler för skrivning via bitvisa operationer:
*           = medför tilldelning av nytt värde.
*           |= medför bitvis addition.
*           &= ~ medför bitvis multiplikation och invertering.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Inkluderingsdirektiv: */
#include <avr/io.h>        /* Innehåller definitioner av I/O-register, såsom DDRB och PORTB. */
#include <avr/interrupt.h> /* Innehåller funktionalitet för avbrott. */

/* Makrodefinitioner: */
#define LED1 1    /* Lysdiod 1 ansluten till pin 9 / PORTB1. */
#define LED2 2    /* Lysdiod 2 ansluten till pin 10 / PORTB2. */
#define BUTTON1 2 /* Tryckknapp 1 ansluten till pin 2 / PORTD2. */
#define BUTTON2 3 /* Tryckknapp 2 ansluten till pin 3 / PORTD3. */

#define LED1_ON PORTB |= (1 << LED1) /* Tänder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* Tänder lysdiod 2. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Släcker lysdiod 2. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2))   /* Tänder båda lysdioder. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2)) /* Släcker båda lysdioder. */

#define BUTTON1_IS_PRESSED ((PIND & (1 << BUTTON1)) != 0) /* Indikerar ifall BUTTON1 är nedtryckt. */
#define BUTTON2_IS_PRESSED ((PIND & (1 << BUTTON2)) != 0) /* Indikerar ifall BUTTON2 är nedtryckt. */

/* Enumerationer: */
typedef enum { false = 0, true = 1 } bool; /* Realiserar datatypen bool. */

/********************************************************************************
* setup: Initierar mikrodatorn (konfigurerar I/O-portar samt aktiverar externa
*        avbrott INT0 samt INT1 på pin 2 - 3 (PORTD2 - PORTD3).
********************************************************************************/
void setup(void);

/********************************************************************************
* led_toggle: Togglar angiven lysdiod på I/O-port B. uint8_t är en osignerad
*             8-bitars heltalsdatatyp, som kan lagra heltal 0 - 255, vilket är
*             samma som 0000 0000 - 1111 1111.
*
*             - pin: Lysdiodens pin-nummer på I/O-port B.
********************************************************************************/
void led_toggle(const uint8_t pin);

#endif /* HEADER_H_ */