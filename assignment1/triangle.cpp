//Eric Lin
//Question 4

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double conv_deg(double rad);
double conv_rad(double deg);
double cosineLaw(double a, double b, double c);
double sineLaw(double a, double b, double angle_a);

int main()
{
    double side1 = 0;
    cout << "Please enter the first side length of the triangle: ";
    cin >> side1;
    
    double side2 = 0;
    cout << "Please enter the second side length of the triangle: ";
    cin >> side2;

    double side3 = 0;   // Assume longest side
    cout << "Please enter the third side length of the triangle: ";
    cin >> side3;
    
    if ((side3 > (side1 + side2)) || side1 < 0 || side2 < 0 || side3 < 0)
        cout << "The triangle you have entered is invalid." << endl;
    else
    {   
        double angle1_cos = cosineLaw(side2, side3, side1);
        double angle2_cos = cosineLaw(side3, side1, side2);
        double angle3_cos = cosineLaw(side1, side2, side3);
        
        double angle3_sin = angle3_cos;
        double angle1_sin = sineLaw(side3, side1, conv_rad(angle3_sin));
		double angle2_sin = sineLaw(side1, side2, conv_rad(angle1_sin));
        
        double perimeter = side1 + side2 + side3;
        double s = perimeter/2;
        double area = sqrt(s*(s-side1)*(s-side2)*(s-side3));

        cout << "Angles according to Law of Cosines: " << angle1_cos << " " <<
        angle2_cos << " " << angle3_cos << endl;

        cout << "Angles according to Law of Sines: " << angle1_sin << " " <<
        angle2_sin << " " << angle3_sin << endl;
        
        cout << "Area: " << area << endl;
        
        return EXIT_SUCCESS;
    }
}

double conv_deg(double rad)
{
    //converts radians to degrees
    
    double deg = 0;
    deg = rad * 180 / M_PI;
    return deg;
}

double conv_rad(double deg)
{
    //converts degrees to radians
    
    double rad = 0;
    rad = deg * M_PI / 180;
    return rad;
}

double cosineLaw(double a, double b, double c)
{
    double angle_c = 0;
    angle_c = conv_deg(acos((pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b)));
    return angle_c;
}

double sineLaw(double a, double b, double angle_a)
{
    double angle_b = 0;
    angle_b = conv_deg(asin((sin(angle_a)*b/a)));
    return angle_b;
}

/*
 
 Case 1:
 Please enter the first side length of the triangle: 3
 Please enter the second side length of the triangle: 4
 Please enter the third side length of the triangle: 5
 Angles according to Law of Cosines: 36.8699 53.1301 90
 Angles according to Law of Sines: 36.8699 53.1301 90
 Area: 6
 
 --------------------------------
 Process exited after 2.778 seconds with return value 0
 
 Case 2: 
 Please enter the first side length of the triangle: 13
 Please enter the second side length of the triangle: 13
 Please enter the third side length of the triangle: 24.021
 Angles according to Law of Cosines: 22.4992 22.4992 135.002
 Angles according to Law of Sines: 22.4992 22.4992 135.002
 Area: 59.7489
 
 --------------------------------
 Process exited after 6.766 seconds with return value 0
 
 Sine Law Note:
 To avoid the ambiguous case of Sine, the largest angle calculated from the 
 Cosine Law will be used to ensure that the correct angles are calculated and 
 outputed. This is because the arcsin function will always output an acute angle 
 even if the actual angle in question is obtuse. Hence, a situation where the 
 sineLaw function would output an acute angle when the obtuse one is needed can
 be avoided. 
 
 The largest angle will always be angle3_cos as it is assumed the longest side
 of the triangle is side3.
 
*/
