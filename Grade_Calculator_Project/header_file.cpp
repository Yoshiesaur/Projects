// REQUIRED LIBRARIES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Course{
    /*
    1: Create new SubClass
    2: Delete SubClass
    3: Display Info
    4: Calculate Final Grade*/
private:

    int limit = 5; //Hard coded for data limitations
    string course_name;
    vector<SubClass> subclasses; 
    double final_grade;

public:
    //Constructor
    Course(string inName){
        course_name = inName;
    }

    double get_course_grade(){
        return final_grade;
    }

    string get_course_name(){
        return course_name;
    }

    void insert_subcourse(SubClass inName){
        if(subclasses.size() >= limit){
            cout << "Number of SubCourses reached" << endl;
        }
        else{
        subclasses.push_back(inName);
        calculate_final_grade();            
        }

    }

    void delete_subclass(int index){
        if(index < 0 || index >= subclasses.size()){
            cout << "Invalid Index" << endl;
        }
        else{ 
        cout << "Erasing " << subclasses[index].getName() << " at index '" << index << "'" << endl;
        subclasses.erase(subclasses.begin() + index);
        calculate_final_grade();
        }

    }

    void display() const{
        if(subclasses.empty()){
            cout << "Course is empty" << endl;
        }
        else{ 
            cout << "Course Name: " << course_name << endl;
            for(SubClass i : subclasses){
                cout << "Subclass name: " << i.getName() << endl;
                i.display_subclass();
            } 
        }
    }

    void calculate_final_grade(){
        if(subclasses.empty()){
            cout << "Subclasses are empty" << endl;
            final_grade = 0;
        }
        
        else{
            double sum = 0;
            for(SubClass i : subclasses){
                sum += i.getWeightedTotal();
            }
            final_grade = sum;
        }
    }

};

class SubClass {
    /*This class should be able to 
    1: Insert grades
    2: Delete grades
    3: Delete a certain grade
    4: Display all info
    5: Calculate Weighed Average
    6: Implement getname(), getweightedtotal(), getweight();
    */

private:
    //Single Variables
    string subclass_name;
    vector<double> grades;
    double weighted_total;
    double subclass_weight;

public:

    SubClass(string inName, double inWeight){
        subclass_name = inName;
        subclass_weight = inWeight;
    }

    double getWeight(){
        return subclass_weight;
    }

    double getWeightedTotal(){
        return weighted_total;
    }

    string getName(){
        return subclass_name;
    }

    void calculate_average(){
        if(grades.empty()){
            weighted_total = 0;
        }
        else{
            double sum = 0;
            for(double j: grades){
                sum += j;
            }
            weighted_total = sum*(subclass_weight/100.f);
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
        calculate_average();
    }

    void display_subclass() const{
        cout << "Subclass Name: " << subclass_name << endl;
        cout << "Weight: " << subclass_weight << endl;
        cout << "Grades: ";
        int j = 1;
        for(double i : grades){
            cout << setw(15) << j << ": " << i << endl;
            j++;
        }
        cout << "Weighted Average: " << weighted_total << endl;
    }

    void insert_grade(double inNumber){
        grades.push_back(inNumber);
        calculate_average();
    }

    void deleteAll(){
        grades.clear();
        subclass_name.clear();
        subclass_weight = 0;
        weighted_total = 0;
        calculate_average();
        cout << "All data has been cleared " << endl;
    }   
};