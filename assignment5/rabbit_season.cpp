#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int hours(int time_hhmmss);
int minutes(int time_hhmmss);
int seconds(int time_hhmmss);
double x_coordinate(double heading, double distance);
double y_coordinate(double heading, double distance);
int get_duration(int start_hours, int start_minutes, int start_seconds,
                 int end_hours, int end_minutes, int end_seconds);

int main()
{
    ifstream fin("wascally_wabbits.txt");
    ofstream fout("rabbit.txt");

    fout << fixed << setprecision(2);

    if (!fin)
    {
        cout << "File read error";

        return EXIT_FAILURE;
    }

    int rabbitNum = 0;
    int prevRabbitNum = 0;

    int hour1 = 0, hour2 = 0;
    int min1 = 0, min2 = 0;
    int sec1 = 0, sec2 = 0;
    int startTime = 0, endTime = 0;
    double xVal = 0, yVal = 0;
    double radius = 0, angle = 0;
    int duration = 0;

    while (fin >> rabbitNum)
    {
        fout << setw(2) << rabbitNum;

        hour1 = hour2;
        min1 = min2;
        sec1 = sec2;

        fin >> startTime;
        hour2 = hours(startTime);
        min2 = minutes(startTime);
        sec2 = seconds(startTime);

        fout << setw(4) << hour2 << ":" << setfill('0') << setw(2) << min2
            << ":" << setfill('0') << setw(2) <<sec2;

        fin >> angle >> radius;

        xVal = x_coordinate(angle, radius);
        yVal = y_coordinate(angle, radius);

        fout << setfill(' ') << setw(4) << "( " << setw(5) << xVal << ","
            << setw(6) << yVal << ")";

        if (rabbitNum == prevRabbitNum)
        {
            duration = get_duration(hour1, min1, sec1, hour2, min2, sec2);
        }
        else
            duration = 0;

        fout << setw(6) << duration << endl;

        prevRabbitNum = rabbitNum;
    }
}

int hours(int time_hhmmss)
{
    return time_hhmmss/10000;
}

int minutes(int time_hhmmss)
{
    return ((time_hhmmss%10000) - seconds(time_hhmmss))/100;
}

int seconds(int time_hhmmss)
{
    return time_hhmmss%100;
}

double x_coordinate(double heading, double distance)
{
    return distance*cos(heading*M_PI/180);
}

double y_coordinate(double heading, double distance)
{
    return distance*sin(heading*M_PI/180);
}

int get_duration(int start_hours, int start_minutes, int start_seconds,
                 int end_hours, int end_minutes, int end_seconds)
{
    int time1 = start_hours*3600 + start_minutes*60 + start_seconds;

    int time2 = end_hours*3600 + end_minutes*60 + end_seconds;

    if (time1 <= time2)
        return time2 - time1;
    else
        return ((24*60*60) - time1) + time2;
}
