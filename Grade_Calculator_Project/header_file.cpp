// REQUIRED LIBRARIES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <array>

using namespace std;

const int SIZE = 5;

class Course {

private:
    string first_name;
    string last_name;
    string course_name;
    vector<int> grades;
    double weight;
    double sum;
    ofstream file;
public:
    Course(string fname, string lname, string inCname){
        first_name = fname;
        last_name = lname;
        course_name = inCname;
        cout << "Created new Student " << first_name << " " << last_name << endl;
    }
    void addWeight(double inWeight){
        weight = inWeight;
    }

    void pushGrade(int grade){
        grades.push_back(grade);
    }

    double CalcGrade() const{
        if (grades.empty()){
            cout << "Grade Stack is empty"  << endl;
            return 0;
        }

        double sum = 0;

        for(int i = 0; i < grades.size(); i++){
            sum += grades[i];
        }
        return sum*(weight /100.f);
    }

    void display() const{
        cout << "Student: " << first_name << " " << last_name;
        cout << "Grades: ";
        for(int i = 0; i < grades.size(); i++){
            cout << grades[i] << " ";
        }
        cout << "\nWeight: " << weight << "%" << endl;
    }

    void saveToFile(){
        string file_name;
        if (file_name.find(".txt.")){
            file.open(file_name);
            if(file.is_open()){
                cout << "File '" << file_name <<"' succesfully opened" << endl;
                cout << endl;
                cout << "Saving data to file: " << endl;
                file << first_name << " " << last_name << endl;
                file << course_name << endl;
                
            }
            else{
                cout << "File could not be properly opened" << endl;
            }
        }
        else{
            file.open(file_name.append(".txt"));
            !file.is_open() ? cout << "Could not open file '" << file_name <<".txt'" << endl : cout << "Properly opened file" << endl;
        }
    }
};

void extractFile(string &fname, string &lname, string &subject, string &sub1, string &sub2, string &sub3, int &weight1, int &weight2, int &weight3, int grade1[], int grade2[], int grade3[], ifstream &file)
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

        cout << endl;

        cout << "Extracting name from file" << endl;
        file >> fname >> lname;

        cout << endl;

        cout << "Extracting course name from file" << endl;
        file >> subject;

        cout << endl;

        cout << "Extracting subjects from file" << endl;
        file >> sub1 >> sub2 >> sub3;

        cout << endl;

        cout << "Extracting weights for each subject from file" << endl;
        file >> weight1 >> weight2 >> weight3;

        cout << endl;

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
        cout << endl;
    }
    file.close();
    !file.is_open() ? cout << "File successfully closed" << endl : cout << "File not closed properly" << endl;
    cout << endl;

}


void displayFile_inFile(string fname, string lname, string subject, string sub1, string sub2, string sub3, int &weight1, int &weight2, int &weight3, int grade1[], int grade2[], int grade3[], ifstream &file){
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

    cout << "Displaying weights for each subject" << endl;
    cout << dec << grade1 << " " << grade2 << " " << grade3 << endl;
    
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

void displayFile_outFile(string fname, string lname, string subject, string sub1, string sub2, string sub3, int &weight1, int &weight2, int &weight3, int grade1[], int grade2[], int grade3[], ofstream &file){
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

    cout << "Displaying weights for each subject" << endl;
    cout << setw(width) << grade1 << " " << grade2 << " " << grade3 << endl;

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