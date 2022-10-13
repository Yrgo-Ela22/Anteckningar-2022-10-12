/********************************************************************************
* setup.c: Inneh�ller diverse initieringsrutiner. Vi anv�nder de funktioner som
*          enbart skall vara synliga och anropbara inuti filen till statiska
*          via nyckelordet static.
*
*          F�rst initieras mikrodatorns I/O-portar. Lysdiodernas pinnar s�tts
*          till utportar genom att ettst�lla motsvarande bitar i datariktnings-
*          register DDRB. Sedan aktiveras de interna pullup-resistorerna p� 
*          tryckknapparnas pinnar f�r att insignalerna alltid skall bli h�ga
*          (1) eller l�ga (0). Insignaler �r annars som default satta i ett
*          flytande tillst�nd, d�r insignalen hamnar n�gonstans mellan 0 - 1.
*          Detta tillst�nd kallas inom digitaltekniken f�r tri-state.
*
*          D�refter aktiveras externa avbrott INT0 - INT1 p� pin 2 - 3.
*          Avbrott INT0 p� pin 2 (PORTD2) aktiveras p� stigande flank, medan 
*          avbrott INT1 p� pin 3 (PORTD3) aktiveras p� fallande flank.
*
*          F�rst aktiveras avbrott globalt genom att ettst�lla biten I, �ven
*          kallad Global Interrupt Flag, i statusregistret SREG. Detta �stadkommes 
*          via assemblerinstruktionen SEI (Set Interrupt Flag). F�r att skriva en 
*          assemblerinstruktion inline i C-koden omges denna instruktion av asm(""), 
*          d�r instruktionen SEI skrivs mellan citattecken. Det g�r ocks� att anropa
*          funktionen sei() f�r att ettst�lla I-biten, men det fungerar inte alltid.
*
*          Sedan aktiveras avbrott INT0 (pin 2) p� stigande flank (n�r BUTTON1 
*          trycks ned) genom att ettst�lla bitar ISC00 - ISC01 (Interrupt Sense 
*          Control 00 - 01) i kontrollregister EICRA (External Interrupt Control 
*          Register A). D�refter aktiveras avbrott INT1 (pin3) p� fallande flank
*          genom att ettst�lla ISC10 (Interrupt Sense Control) i samma register. 

*          Slutligen aktiveras avbrott INT0 - INT1 genom att ettst�lla bitarna 
*          med samma namn i maskregister EIMSK (External Interrupt Mask Register).
********************************************************************************/
#include "header.h"

/* Statiska funktioner: */
static void init_ports(void);
static void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorn (konfigurerar I/O-portar samt aktiverar externa
*        avbrott INT0 samt INT1 p� pin 2 - 3 (PORTD2 - PORTD3).
********************************************************************************/
void setup(void)
{
   init_ports();
   init_interrupts();
   return;
}

/********************************************************************************
* init_ports: Konfigurerar I/O-portar genom att s�tta lysdioderna till utportar, 
*             samt att de interna pullup-resistorer p� tryckknapparnas pinnar
*             aktiveras f�r att insignalerna alltid skall bli l�ga / 0 eller 
*             h�ga / 1 (inportarna �r som default i tillst�ndet tri-state,
*             vilket inneb�r att insignalen �r flytande mellan 0 - 1).
********************************************************************************/
static void init_ports(void)
{
   DDRB = ((1 << LED1) | (1 << LED2));
   PORTD = ((1 << BUTTON1) | (1 << BUTTON2));
   return;
}

/********************************************************************************
* init_interrupts: Aktiverar externa avbrott INT0 - INT1 p� pin 2 - 3. Avbrott
*                  INT0 aktiveras p� stigande flank, medan avbrott INT1 
*                  aktiveras p� fallande flank.       
********************************************************************************/
static void init_interrupts(void)
{
   asm("SEI");
   EICRA = ((1 << ISC00) | (1 << ISC01) | (1 << ISC11));
   EIMSK = ((1 << INT0) | (1 << INT1));
   return;
}