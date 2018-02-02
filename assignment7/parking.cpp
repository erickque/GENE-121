#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX_SPOTS = 50;

void readFile (ifstream & fin, bool currentStatus[], string currentName[])
{
    bool isStaff = -1;
    string name = "";
    int space = -1;
    int count = 0;
    while (count < MAX_SPOTS && fin >> isStaff >> name >> space)
    {
        int index = (space-1);

        currentStatus[index] = isStaff;
        currentName[index] = name;
    }
}

int getAddRemove (ifstream & fin, bool isStaff[], string name[])
{
    int count = 0;
    while (count < MAX_SPOTS && fin >> isStaff[count] && fin >> name[count])
        count ++;
    return count;
}

void freeUpSpace (string currentName[], string removeName)
{
    for (int space = 0; space < MAX_SPOTS; space++)
    {
        if (currentName[space] == removeName)
        currentName[space] = "";  //empty name indicates a free space
    }
}

int firstFreeSpace (string currentName[], bool isStaff)
{
    int freeSpace = 0;
    
    if (isStaff)
    {
        for (int index = 0; index < MAX_SPOTS && freeSpace == 0; index++)
        {
          if (currentName[index] == "")
              freeSpace = (index + 1);
        }
    }
    else
    {
        for (int index = 26 - 1; index < MAX_SPOTS && freeSpace == 0; index++)
        {
          if (currentName[index] == "")
              freeSpace = (index + 1);
        }
    }
    return freeSpace;
}

bool assignSpace (bool currentStatus[], string currentName[], string name,
                  bool isStaff)
{
    bool assigned = false;
    int index = firstFreeSpace(currentName, isStaff) - 1;

    if (index >= 0)
    {
        currentStatus[index] = isStaff;
        currentName[index] = name;
        assigned = true;
    }
    
    return assigned;
}

void moveUpStaff (bool isStaff[], string name[])
{
    for (int index = 26 - 1; index < MAX_SPOTS; index++)
    {
        int freeSpace = firstFreeSpace(name,true);
        if (freeSpace > 0 && freeSpace < (index + 1) && isStaff[index])
        {
            bool assigned = assignSpace(isStaff, name, name[index],
                                        isStaff[index]);
            if (assigned)
                name[index] = "";
        }
    }
}

void outputData(ofstream & fout, bool currentStatus[], string currentName[])
{
    for (int index = 0; index < MAX_SPOTS; index++)
    {
        if (currentName[index] != "")
          fout << currentStatus[index] << setw(20) << currentName[index] <<
            setw(4) << index+1 << endl;
    }
}

int main()
{

    bool currentStatus[MAX_SPOTS] = {0};    // 0 = student, 1 = staff
    string currentName[MAX_SPOTS];

    bool removeStatus[MAX_SPOTS] = {0};
    string removeName[MAX_SPOTS];

    bool addStatus[MAX_SPOTS] = {0};
    string addName[MAX_SPOTS];
    bool addAssigned[MAX_SPOTS] = {0};

    ifstream current("parking_current.txt");
    ifstream toAdd("parking_add.txt");
    ifstream toRemove("parking_remove.txt");

    if (!current || !toAdd || !toRemove)
    {
        cout << "Unable to locate file. " << endl;
        return EXIT_FAILURE;
    }

    ofstream fout("output.txt");

    readFile(current, currentStatus, currentName);

    int addNum = getAddRemove(toAdd, addStatus, addName);
    int removeNum = getAddRemove(toRemove, removeStatus, removeName);

    for (int count = 0; count < removeNum; count++)
    {
        string name = removeName[count];
        freeUpSpace(currentName, name);
    }

    bool full = false;
    bool allAssigned = false;

    do
    {
        moveUpStaff(currentStatus, currentName);

        for (int count = 0; count < addNum; count++)
        {
            if (!addAssigned[count])
                addAssigned[count] = assignSpace(currentStatus, currentName,
                                                 addName[count],
                                                 addStatus[count]);
        }

        allAssigned = true;
        
        for (int space = 0; space < addNum; space++)
        {
            if (!addAssigned[space])
                allAssigned = false;
        }

        full = true;
        
        for (int space = 25; space < MAX_SPOTS; space++)
        {
            if (currentName[space] == "")
                full = false;
        }
    }
    while (!full && !allAssigned);

    outputData(fout, currentStatus, currentName);

    current.close();
    toAdd.close();
    toRemove.close();
    fout.close();

    return EXIT_SUCCESS;
}
