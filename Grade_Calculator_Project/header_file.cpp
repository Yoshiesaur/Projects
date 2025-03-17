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