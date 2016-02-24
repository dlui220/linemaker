#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
	int counter = 0;
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);


  while (counter < 100){
		draw_line( 0, counter, XRES, YRES, s, c);
		draw_line( XRES, 0, 0, counter, s, c);
		
		counter = counter + 5;
	}

	c.green = 0;
	c.red = MAX_COLOR;

	counter = 0;
	while (counter < 100){
		draw_line( XRES, YRES, counter, 0, s, c);
		draw_line( 0, YRES, counter, 0, s, c);

		counter = counter + 5;
	}

  display(s);
  save_extension(s, "lines.png");
}  
