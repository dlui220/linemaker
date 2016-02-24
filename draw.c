#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

	// Swap the (x,y) coordinates if the end point is to the left of the start point
	if (x0 > x1) {
		draw_line( x1, y1, x0, y0, s, c );
		return;
	}
	
	int x = x0;
	int y = y0;
	int A = y1 - y0; //dy 
	int B = x1 - x0; //dx

	// If end point has a higher y-value than start point
	if ( y1 > y0 ) {
		int d = ( 2 * A ) - B;
		
		if ( A > B ){
			while ( y <= y1 ) {
				plot( s, c, x, y);
				if ( d < 0 ) {
					x++;
					d = d + A;
				}
				d = d - B;
				y++;
			}

		} else {
			while( x <= x1 ){
				plot( s, c, x, y);
				if ( d > 0 ){
					y++;
					d = d - B;
				}
				d = d + A;
				x++;
			}
		}
		
		// If end point has a lower y-value than start point
	} else {
		int d = ( 2 * A ) + B;

		if ( (-1*A) > B ){

      while( y >= y1 ){
        plot( s, c, x, y);
        if( d > 0 ){
          x++;
          d = d + A;
        }
				y--;
        d = d + B;
      } 

    } else {
      
      while( x <= x1 ){
        plot( s, c, x, y);
        if( d > 0 ){
          y--;
          d = d - B;
        }
				x++;
        d = d - A;
      } 
		}
	}
}
