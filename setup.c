/********************************************************************************
* setup.c: Innehåller diverse initieringsrutiner. Vi använder de funktioner som
*          enbart skall vara synliga och anropbara inuti filen till statiska
*          via nyckelordet static.
*
*          Först initieras mikrodatorns I/O-portar. Lysdiodernas pinnar sätts
*          till utportar genom att ettställa motsvarande bitar i datariktnings-
*          register DDRB. Sedan aktiveras de interna pullup-resistorerna på 
*          tryckknapparnas pinnar för att insignalerna alltid skall bli höga
*          (1) eller låga (0). Insignaler är annars som default satta i ett
*          flytande tillstånd, där insignalen hamnar någonstans mellan 0 - 1.
*          Detta tillstånd kallas inom digitaltekniken för tri-state.
*
*          Därefter aktiveras externa avbrott INT0 - INT1 på pin 2 - 3.
*          Avbrott INT0 på pin 2 (PORTD2) aktiveras på stigande flank, medan 
*          avbrott INT1 på pin 3 (PORTD3) aktiveras på fallande flank.
*
*          Först aktiveras avbrott globalt genom att ettställa biten I, även
*          kallad Global Interrupt Flag, i statusregistret SREG. Detta åstadkommes 
*          via assemblerinstruktionen SEI (Set Interrupt Flag). För att skriva en 
*          assemblerinstruktion inline i C-koden omges denna instruktion av asm(""), 
*          där instruktionen SEI skrivs mellan citattecken. Det går också att anropa
*          funktionen sei() för att ettställa I-biten, men det fungerar inte alltid.
*
*          Sedan aktiveras avbrott INT0 (pin 2) på stigande flank (när BUTTON1 
*          trycks ned) genom att ettställa bitar ISC00 - ISC01 (Interrupt Sense 
*          Control 00 - 01) i kontrollregister EICRA (External Interrupt Control 
*          Register A). Därefter aktiveras avbrott INT1 (pin3) på fallande flank
*          genom att ettställa ISC10 (Interrupt Sense Control) i samma register. 

*          Slutligen aktiveras avbrott INT0 - INT1 genom att ettställa bitarna 
*          med samma namn i maskregister EIMSK (External Interrupt Mask Register).
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static void init_ports(void);
static void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorn (konfigurerar I/O-portar samt aktiverar externa
*        avbrott INT0 samt INT1 på pin 2 - 3 (PORTD2 - PORTD3).
********************************************************************************/
void setup(void)
{
   init_ports();
   init_interrupts();
   return;
}

/********************************************************************************
* init_ports: Konfigurerar I/O-portar genom att sätta lysdioderna till utportar, 
*             samt att de interna pullup-resistorer på tryckknapparnas pinnar
*             aktiveras för att insignalerna alltid skall bli låga / 0 eller 
*             höga / 1 (inportarna är som default i tillståndet tri-state,
*             vilket innebär att insignalen är flytande mellan 0 - 1).
********************************************************************************/
static void init_ports(void)
{
   DDRB = ((1 << LED1) | (1 << LED2));
   PORTD = ((1 << BUTTON1) | (1 << BUTTON2));
   return;
}

/********************************************************************************
* init_interrupts: Aktiverar externa avbrott INT0 - INT1 på pin 2 - 3. Avbrott
*                  INT0 aktiveras på stigande flank, medan avbrott INT1 
*                  aktiveras på fallande flank.       
********************************************************************************/
static void init_interrupts(void)
{
   asm("SEI");
   EICRA = ((1 << ISC00) | (1 << ISC01) | (1 << ISC11));
   EIMSK = ((1 << INT0) | (1 << INT1));
   return;
}