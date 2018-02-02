#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int constants[] = {3, 11, 12, -7, 5};
    int degrees[] = {5, 4, 3, 1, 0};
    double minX = -5, minY = -5000; 

    for (double x = -5; x <= 5; x += 0.0001)
    {
        double yVal = 0;

        for (int j = 0; j < 5; j++)
        {
            yVal += constants[j] * pow(x,degrees[j]);
        }

        if (fabs(yVal) < fabs(minY))
        {
            minX = x;
            minY = yVal; 
        }
    }

    cout << minX << endl;

    return EXIT_SUCCESS;
}
