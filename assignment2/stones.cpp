//Eric Lin and Jonathan Lin

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("stones.txt");
	ofstream fout("shapes.txt");
	
	if (!fin)
	{
		cout << "File read error";
		return EXIT_FAILURE;
	}
	
	int NumberOfStones=0;
	fin >> NumberOfStones;
	
	for (int StoneNumber=1; StoneNumber<=NumberOfStones; StoneNumber++)
	{
		double SideOne = 0, SideTwo = 0, Angle = 0;
		const double SIDE_LENGTH_TOL = 0.7, ANGLE_TOL = 0.5; 
		const double RIGHT_ANGLE = 90;
		
		fin >> SideOne >> SideTwo >> Angle;
		
		if ((fabs(SideOne-SideTwo)<SIDE_LENGTH_TOL))
		{
			if (fabs(Angle-RIGHT_ANGLE)<ANGLE_TOL)
			{
				fout << SideOne << "cm\t" << SideTwo << "cm\t" << Angle 
				     << "°\t" << "Square" << endl;
			}
			else
			{
				fout << SideOne << "cm\t" << SideTwo << "cm\t" << Angle 
				     << "°\t" << "Rhombus" << endl;
			}
		}
		else
		{
			if (fabs(Angle-RIGHT_ANGLE)<ANGLE_TOL)
			{
				fout << SideOne << "cm\t" << SideTwo << "cm\t" << Angle 
				     << "°\t" << "Rectangle" << endl;
			}
			else
			{
				fout << SideOne << "cm\t" << SideTwo << "cm\t" << Angle 
				     << "°\t" << "Parallelogram" << endl;
			}
		}
	}
	
	fin.close();
	fout.close();
	
	return EXIT_SUCCESS;
}

/*
--------------------------------
Process exited after 3.427 seconds with return value 0
Press any key to continue . . .
*/

