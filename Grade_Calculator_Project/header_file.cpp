// REQUIRED LIBRARIES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Course {

private:
    //Single Variables
    string first_name;
    string last_name;
    string course_name;
    double sum;

    //Vectors
    vector<string> course_subjects;
    vector<int> grades;
    vector<double> weights;

    //Files
    ofstream file;

    //Strictly Forbidden
    void openFile(string file_name){
        if (file_name.find(".txt") == string::npos) {
        file_name.append(".txt");
        }
        
        file.open(file_name);
        if(!file.is_open()){
            cout << "File not opened" << endl;
            return;
        }
        else{
            cout << "File opened successfully" << endl;
        }
    }

    void closeFile(){
        file.close();
        file.is_open() ? cout << "File not closed properly" << endl : cout << "File closed properly" << endl;
    }

public:
    Course(string fname, string lname, string inCourseName){
        first_name = fname;
        last_name = lname;
        course_name = inCourseName;
        cout << "Created new Student " << first_name << " " << last_name << endl;
    }

    void delete_weight_at(int target_index){
        if(target_index < 0 || target_index >= weights.size()){
            cout << "Invalid Weight Index" << endl;
        }
        else{ 
            cout << "Removing weight: " << weights[target_index] << " at index '" << target_index << "'" << endl;
            weights.erase(weights.begin() + target_index);
        }
    }

    void delete_grade_at(int target_index){
        if (target_index < 0 || target_index >= grades.size()){
            cout << "Invalid Index" << endl;
        }
        else{
            cout << "Erasing " << grades[target_index] << " at index '" << target_index << "'" << endl;
            grades.erase(grades.begin() + target_index);
        }
    }

    void deleteAll(){
        grades.clear();
        weights.clear();
        course_subjects.clear();
        cout << "All data has been deleted " << endl;
    }

    void saveToFile(string file_name){
        openFile(file_name);
        if(file.is_open()){
            cout << "Saving data to file" << endl;
            file << first_name << " " << last_name << endl;
            file << course_name << endl;
            
            for(int i : weights){
                file << i << " ";
                for(int j : grades){
                    file << j << " ";
                }
                file << endl;
            }
            closeFile();
        }
        else{
            return;
        }
        
    }
};