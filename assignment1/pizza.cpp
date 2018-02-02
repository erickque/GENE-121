//Eric Lin

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    
    int pizzas = 0;
    cout << "Please enter the total number of pizzas: ";
    cin >> pizzas;
    
    int students = 0;
    cout << "Please enter the number of students: ";
    cin >> students;
    
    const int RADIUS = 17;
    double total_sa = pizzas * M_PI * pow(RADIUS,2);                      
    
    if (students > 0)
    {
    	double student_sa = total_sa / students;
    
    	cout << "Each student will eat " << student_sa << " cm^2 of pizza.";
    }
    else
    	cout << "No one showed up!" << " There is " << total_sa << 
            " cm^2 of pizza left." << endl;
    	
    return EXIT_SUCCESS;

}

/*
Case 1:
Please enter the total number of pizzas: 22
Please enter the number of students: 11
Each student will eat 1815.84 cm^2 of pizza.

--------------------------------
Process exited after 5.86 seconds with return value 0

Case 2:
Please enter the total number of pizzas: 5
Please enter the number of students: 9
Each student will eat 504.4 cm^2 of pizza.

--------------------------------
Process exited after 3.317 seconds with return value 0

Case 3:
Please enter the total number of pizzas: 6
Please enter the number of students: 0
No one showed up! There is 5447.52 cm^2 of pizza left.
 
--------------------------------
Process exited after 5.964 seconds with return value 0

*/

