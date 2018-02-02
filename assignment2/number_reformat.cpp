//Eric Lin and Jonathan Lin

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    
    cout << "Enter an integer between -999999 and 999999: ";
    int num = 0;
    cin >> num;

    if (abs(num) >= 1e6)
    {
        cout << "The number you have entered does not lie between the " <<
        "stated boundaries.";
        
        return EXIT_FAILURE;
    }
    
    /* Only numbers 1000 and greater need a comma added between their hundreds
     and thousands place values. Numbers less than 1000 can be directly 
     outputted. */
    
    if (num < 0)
    {
        num = abs(num);
        cout << "-";
    }
    if (num >= 1000)
    {
        cout << num / 1000 << "," << num % 1000;
    }
    else
    {
        cout << num;
    }

    return EXIT_SUCCESS;
}

/* Test Cases

Enter an integer between -999999 and 999999: 1000000
The number you have entered does not lie between the stated boundaries.
--------------------------------
Process exited after 4.792 seconds with return value 1

Enter an integer between -999999 and 999999: 999999
999,999
--------------------------------
Process exited after 17.09 seconds with return value 0

Enter an integer between -999999 and 999999: -999999
-999,999
--------------------------------
Process exited after 2.863 seconds with return value 0

Enter an integer between -999999 and 999999: 123456
123,456
--------------------------------
Process exited after 5.864 seconds with return value 0

Enter an integer between -999999 and 999999: -1934
-1,934
--------------------------------
Process exited after 13.15 seconds with return value 0

Enter an integer between -999999 and 999999: 84
84
--------------------------------
Process exited after 10.03 seconds with return value 0

Enter an integer between -999999 and 999999: 0
0
--------------------------------
Process exited after 4.678 seconds with return value 0

Enter an integer between -999999 and 999999: 12004
12,004
--------------------------------
Process exited after 4.727 seconds with return value 0

*/



