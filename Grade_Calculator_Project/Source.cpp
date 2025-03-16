/*
This program stores and save grades for a semster, with individual subject, with each having weighted parts
i.e. Quizzes, Exams, Homeworks 
This is a working development 
1) Get a new file to open and extract files (incomplete) 
2) Extract variables from an existing files (complete)
3) Include weighted averags (incomplete)
4) Calculate final, weighted grades (incomplete)*/

//REQUIRED LIBRARIES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

#include "header_file.cpp"

using namespace std;

//FUNCTION PROTOTYPES
void extractFile(string& fname, string& lname, string& course, string& sub1, string& sub2, string& sub3, int arr[], int arr2[], int arr3[], ifstream& f);
void displayFile(string fname, string lname, string course, string sub1, string sub2, string sub3, int arr[], int arr2[], int arr3[], ifstream f);


//MAIN FUNCTION
int main(){
    //Variables used
    int selection;
    int n = 10;
    string first_name, last_name;
    string course_name;
    string subject_1, subject_2, subject_3;
    int grade_1[SIZE], grade_2[SIZE], grade_3[SIZE];


    ifstream inFile;
    ofstream outFile;
    //After this runs, variables should be populated. 
    extractFile(first_name, last_name, course_name, subject_1, subject_2, subject_3, grade_1, grade_2, grade_3, inFile);
    //Displaying variables extracted
    displayFile_inFile(first_name, last_name, course_name, subject_1, subject_2, subject_3, grade_1, grade_2, grade_3, inFile);
    
    cout << endl;

    //Creating a new file with name, course, subjects(3), and grades(3)
    cout << "Creating new File" << endl;
    
    outFile.open("newStudent.txt");
    if (!outFile.is_open()){
        cout << "Couldn't create new file" << endl;
        return -1;
    }

    else {
        cout << "Successfully created new file" << endl;
        cout << endl;
        cout << "Enter your first and last name: ";
        cin >> first_name >> last_name;

        cout << "Enter course name: ";
        cin >> course_name;
        
        cout << "Enter category names: " << endl;
        cin >> subject_1 >> subject_2 >> subject_3;

        cout << "Enter 5 grades for " << subject_1 << " (one at a time).";
        for (int i = 0; i < SIZE; i++){
            cin >> grade_1[i];
        }
        cout << "Enter 5 grades for " << subject_2 << " (one at a time).";
        for (int i = 0; i < SIZE; i++){
            cin >> grade_2[i];
        }
        cout << "Enter 5 grades for " << subject_3 << " (one at a time).";
        for (int i = 0; i < SIZE; i++){
            cin >> grade_3[i];
        }
    }
    outFile.close();
    outFile.is_open() ? cout << "Couldn't properly close file" << endl : cout << "Closed file propelry" << endl;
    cout << endl;

    displayFile_outFile(first_name, last_name, course_name, subject_1, subject_2, subject_3, grade_1, grade_2, grade_3, outFile);

    return 0;
}


//FUNCTIONS
//Welcomes the user and gives options 
