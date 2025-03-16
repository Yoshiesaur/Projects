// REQUIRED LIBRARIES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 5;

void extractFile(string &fname, string &lname, string &subject, string &sub1, string &sub2, string &sub3, int grade1[], int grade2[], int grade3[], ifstream &file)
{

    // After this runs, variables should be populated.
    file.open("testStudent.txt");
    if (!file.is_open())
    {
        cout << "Could not open file" << endl;
        return;
    }

    else
    {
        cout << "File successfully opened" << endl;

        cout << "Extracting name from file" << endl;
        file >> fname >> lname;

        cout << "Extracting course name from file" << endl;
        file >> subject;

        cout << "Extracting subjects from file" << endl;
        file >> sub1 >> sub2 >> sub3;

        cout << "Extracting grades for each subject from file" << endl;
        for (int i = 0; i < SIZE; i++)
        {
            file >> grade1[i];
        }
        for (int i = 0; i < SIZE; i++)
        {
            file >> grade2[i];
        }
        for (int i = 0; i < SIZE; i++)
        {
            file >> grade3[i];
        }
    }
    file.close();
    !file.is_open() ? cout << "File successfully closed" << endl : cout << "File not closed properly" << endl;
}


void displayFile_inFile(string fname, string lname, string subject, string sub1, string sub2, string sub3, int grade1[], int grade2[], int grade3[], ifstream &file){
    int width = 10;
    cout << "Displaying first and last name" << endl;
    cout << setw(width) << fname << " " << lname << endl;

    cout << endl;

    cout << "Displaying course name" << endl;
    cout << setw(width) << subject << endl;

    cout << endl;

    cout << "Displaying subjects" << endl;
    cout << setw(width) << sub1 << " " << sub2 << " " << sub3 << endl;

    cout << endl;

    cout << "Displaying grades for " << sub1 << endl;
    for(int i = 0; i < SIZE; i++){
        cout << setw(width) << "Grade " << (i + 1) << ": " << grade1[i] << endl;
    }
    cout << endl;
    cout << "Displaying grades for " << sub2 << endl;
    for(int i = 0; i < SIZE; i++){
        cout << setw(width) << "Grade " << (i + 1) << ": " << grade2[i] << endl;
    }
    cout << endl;
    cout << "Displaying grades for " << sub3 << endl;
    for(int i = 0; i < SIZE; i++){
        cout << setw(width) << "Grade " << (i + 1) << ": " << grade3[i] << endl;
    }
}

void displayFile_outFile(string fname, string lname, string subject, string sub1, string sub2, string sub3, int grade1[], int grade2[], int grade3[], ofstream &file){
    int width = 10;
    cout << "Displaying first and last name" << endl;
    cout << setw(width) << fname << " " << lname << endl;

    cout << endl;

    cout << "Displaying course name" << endl;
    cout << setw(width) << subject << endl;

    cout << endl;

    cout << "Displaying subjects" << endl;
    cout << setw(width) << sub1 << " " << sub2 << " " << sub3 << endl;

    cout << endl;

    cout << "Displaying grades for " << sub1 << endl;
    for(int i = 0; i < SIZE; i++){
        cout << setw(width) << "Grade " << (i + 1) << ": " << grade1[i] << endl;
    }
    cout << endl;
    cout << "Displaying grades for " << sub2 << endl;
    for(int i = 0; i < SIZE; i++){
        cout << setw(width) << "Grade " << (i + 1) << ": " << grade2[i] << endl;
    }
    cout << endl;
    cout << "Displaying grades for " << sub3 << endl;
    for(int i = 0; i < SIZE; i++){
        cout << setw(width) << "Grade " << (i + 1) << ": " << grade3[i] << endl;
    }
}