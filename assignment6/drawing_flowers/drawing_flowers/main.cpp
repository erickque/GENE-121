// Eric Lin

#include <cmath>
#include "ccc_win.h"

int ccc_win_main(){
    
    const double CENTER_RAD = 0.5;
    const double PETAL_RAD = 0.31;
    const double STEM_LENGTH = 1;
    
    int flowers = cwin.get_int("Enter a number of flowers: ");
    
    for (int flowerCount = 0; flowerCount < flowers ; flowerCount++)
    {
        Point click = cwin.get_mouse("Click where to place the flowers.");
        
        double xVal = click.get_x(), yVal = click.get_y();
        
        Circle center(click,CENTER_RAD);
        
        double stemYStart = yVal - (CENTER_RAD + 2*PETAL_RAD);
        Line stem(Point(xVal,stemYStart),Point(xVal,stemYStart - STEM_LENGTH));
        
        cwin << center << stem;
        
        for (int petalCount = 0; petalCount < 8; petalCount++)
        {
            double angle = petalCount*M_PI/4;
            
            double petalX = xVal + (CENTER_RAD + PETAL_RAD)*cos(angle);
            double petalY = yVal + (CENTER_RAD + PETAL_RAD)*sin(angle);
            
            Point petalCen(petalX,petalY);
            
            Circle petal(petalCen,PETAL_RAD);
            cwin << petal;
        }
    }

    return 0;
}
