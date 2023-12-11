/** \file lcddemo.c
 *  \brief A simple demo that draws a string and square
 */

#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"
#include "switches.h"
#include "notes.h"
#include "melodies.h"
#include "globals.h"
#include "timing.h"

#define LED BIT6


/** Initializes everything, clears the screen, draws "hello" and a square */
int
main()
{
  P1DIR |= LED;
  P1OUT |= LED;
  configureClocks();
  lcd_init();
  buzzer_init();
  switch_init();
  enableWDTInterrupts();
  u_char width = screenWidth, height = screenHeight;
  drawTitle();
  drawString8x12(20, 20, "Zelda", COLOR_RED, COLOR_YELLOW);


  
  
}


