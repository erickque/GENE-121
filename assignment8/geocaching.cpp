#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <cmath>

using namespace std;

const int NS = 50; 
const int EW = 25; 
const int MAX_CACHES = 25;

//Let the NW corner be the origin, and the SE corner be (24, 49)

void readElevation(ifstream & fin, int elevations[NS][EW]);
int readGeocache(ifstream & fin, bool geocache[NS][EW]);
double getEnergy(int elevations[NS][EW], int x1, int y1, int x2, int y2);
bool nextGeocache(int elevations[NS][EW], bool geocache[NS][EW], int xCur,
                  int yCur, int & xGeo, int & yGeo);
void optimizePath(int elevations[NS][EW], bool geocache[NS][EW],
                  int coordinates[2][MAX_CACHES], int caches);
void writeFile(ofstream & fout, int coordinates[2][MAX_CACHES], int caches);

int main()
{
	ifstream elevationFile("elevations.txt");
	ifstream cacheFile("caches.txt");
	ofstream fout("output.txt");

	if (!elevationFile || !cacheFile)
	{
		cout << "File(s) not found." << endl;
		return EXIT_FAILURE;
	}

	int elevations[NS][EW] = {0};
	bool geocache[NS][EW] = {0};
	int coordinates[2][MAX_CACHES] = {0};	//one row for x, and one row for y

	readElevation(elevationFile, elevations);
	int caches = readGeocache(cacheFile, geocache);
	optimizePath(elevations, geocache, coordinates, caches);
	writeFile(fout, coordinates, caches);

	elevationFile.close();
	cacheFile.close();
	fout.close();

	return EXIT_SUCCESS;
}

void readElevation(ifstream & fin, int elevations[NS][EW])
{
    for (int row = 0; row < NS; row++)
        for (int col = 0; col < EW; col++)
            fin >> elevations[row][col];
}

int readGeocache(ifstream & fin, bool geocache[NS][EW])
{
    int geocaches = 0;
    for (int row = 0; row < NS; row++)
        for (int col = 0; col < EW; col++)
        {
            fin >> geocache[row][col];
            if (geocache[row][col])
            {
                geocaches++;
            }
        }
    return geocaches;
}

double getEnergy(int elevations[NS][EW], int x1, int y1, int x2, int y2)
{
    double energy = 0;
    
    double horizontal = 100 * sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    double vertical = fabs(elevations[y2][x2]-elevations[y1][x1]);
    
    //Moving vertically takes 7 times as much energy as horizontally
    energy = 7 * vertical + horizontal;
    
    return energy;
}

bool nextGeocache(int elevations[NS][EW], bool geocache[NS][EW], int xCur,
                  int yCur, int & xGeo, int & yGeo)
{
    bool found = false;
    int closestX = 0, closestY = 0, minEnergy = 10e5;
    for (int row = 0; row < NS; row++)
        for (int col = 0; col < EW; col++)
        {
            if(geocache[row][col])
            {
                int energy = getEnergy(elevations, xCur, yCur, col, row);
                if (energy < minEnergy)
                {
                    minEnergy = energy;
                    closestX = col;
                    closestY = row;
                    found = true;
                }
            }
        }
    xGeo = closestX;
    yGeo = closestY;
    geocache[closestY][closestX] = 0; //Erase next geocache so to not revisit
    return found;
}

void optimizePath(int elevations[NS][EW], bool geocache[NS][EW],
                  int coordinates[2][MAX_CACHES], int caches)
{
    int xCur = 0, yCur = 0; //Start at origin
    
    for(int cache = 0; cache < caches; cache++)
    {
        int xGeo = 0, yGeo = 0;
        
        if (nextGeocache(elevations, geocache, xCur, yCur, xGeo, yGeo))
        {
            coordinates[0][cache] = xGeo;
            coordinates[1][cache] = yGeo;
            xCur = xGeo;
            yCur = yGeo;
        }
    }
}

void writeFile(ofstream & fout, int coordinates[2][MAX_CACHES], int caches)
{
    fout << "(0, 0)" << endl; //Starting coordinates
    for (int cache = 0; cache < caches; cache++)
    {
        fout << "(" << coordinates[0][cache] << ", " << coordinates[1][cache]
        << ")" << endl;
    }
}
