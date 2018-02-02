#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int time1 = 0;
    int hour1 = 0;
    int min1 = 0;

    do {
        cout << "Enter first time: ";
        cin >> time1;

        min1 = time1 % 100;
        hour1 = (time1 - min1)/100;
    }
    while(hour1 < 0 || hour1 >= 24 || min1 < 0 || min1 >= 60);

    int time2 = 0;
    int hour2 = 0;
    int min2 = 0;

    do
    {
        cout << "Enter second time: ";
        cin >> time2;

        min2 = time2 % 100;
        hour2 = (time2 - min2)/100;
    }
    while(hour2 < 0 || hour2 >= 24 || min2 < 0 || min2 >= 60);

    int hourDif = 0;
    int minDif = 0;

    hourDif = abs(hour2 - hour1);
    minDif = min2 - min1;

    int timeDif = 0;

    if (time1 > time2)
    minDif *= -1;

    timeDif = (hourDif * 60) + minDif;

    cout << "There are " << timeDif << " minutes between the two times." << endl;

    return EXIT_SUCCESS;
}
