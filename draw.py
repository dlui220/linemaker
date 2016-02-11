from display import *

def draw_line( screen, x0, y0, x1, y1, color ):
    if (x0 > x1):
        draw_line( screen, x1, y1, x0, y0, color );
    x = x0
    y = y0
    A = y1 - y
    B = -1 * (x1 - x)
    
    if (A/B > 0 and A/B < 1):
        d = (2 * A) + B
        while (x < x1):
            plot(screen, color, x, y)
            if (d > 0):
                y += 1
                d += 2 * B
            x += 1
            d += 2 * A
    if (A/B > 1):
        while (y <= y1):
            plot( screen, color, x, y)
            if (d < 0):
                x += 1
                d += 2 * A
            y += 1
            d += 2 * B

    # pass
