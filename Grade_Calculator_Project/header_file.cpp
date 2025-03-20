// REQUIRED LIBRARIES
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class Semester{
    /*
    1: Create new Semester
    2: create a new course
    3: Delete a course
    4: Calculate grades of each course
    5: Display final grade of each course
    6: Calculate Semester GPA
    7: Clear all Courses
    */
private:
    const int SIZE_LIMIT = 6;
    const int HOUR_LIMIT = 18;
    string semester_name;
    vector<Course> courses;
    vector<int> course_hours;
    int total_hours;
    double semester_GPA;

public:
    //Create a new semester
    Semester(string inName){
        semester_name = inName;
    }

    //2: Create a new course
    void add_course(string inName, int inHours){
        if ((courses.size() > SIZE_LIMIT) || (total_hours > 18)){
            cout << "Exceeding size limit or hour limit" << endl;
            return;
        }
        else{
            courses.push_back(inName);
            course_hours.push_back(inHours);
            update_course_hours(inHours);
        }
    }

    //3: Delete a course 
    void delete_course(int index){
        if(course_hours.empty()){
            cout << "Courses is empty" << endl;
        }
        else{ 
            cout << "Erasing " << courses[index].get_course_name() << " at index '" << index << "'" << endl;
            update_course_hours((-1)*course_hours[index]);
            courses.erase(courses.begin() + index);
            course_hours.erase(course_hours.begin() + index);
        }
    }

    //4 Calculate Grade of Each Course

    void update_course_hours(int inHours){
        if(courses.empty()){
            total_hours = 0;
        }
        else{
            total_hours += inHours;
        }
    }

};

class Course{
    /*
    1: Create new SubClass
    2: Delete SubClass
    3: Display Info
    4: Calculate Final Grade*/
private:

    const int SIZE_LIMIT = 5; //Hard coded for data limitations
    string course_name;
    vector<SubClass> subclasses; 
    double final_grade;

public:
    //Constructor
    Course(string inName){
        course_name = inName;
    }
    
    void rename_course(string new_name){
        course_name = new_name;
    }

    double get_course_grade() const{
        return final_grade;
    }

    string get_course_name() const{
        return course_name;
    }

    void insert_subcourse(SubClass inName){
        if(subclasses.size() >= SIZE_LIMIT){
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
            return;
        }
        else{ 
        cout << "Erasing " << subclasses[index].get_subclass_name() << " at index '" << index << "'" << endl;
        subclasses.erase(subclasses.begin() + index);
        calculate_final_grade();
        }

    }

    void display_course() const{
        if(subclasses.empty()){
            cout << "Course is empty" << endl;
        }
        else{ 
            cout << "\n============================" << endl;
            cout << "Course Name: " << course_name << endl;
            cout << "Final Grade: " << fixed << setprecision(2) << final_grade << endl;
            cout << "============================" << endl;

            for (size_t i = 0; i < subclasses.size(); i++) {
            cout << "\n----- SubClass -----" << endl;
            cout << "Name: " << subclasses[i].get_subclass_name() << "\n";
            subclasses[i].display_subclass();
            }

            cout << "============================\n" << endl;
        }
    }
        


    void calculate_final_grade(){
        if(subclasses.empty()){
            final_grade = 0;
        }
        
        else{
            double sum = 0;
            for(size_t i = 0; i < subclasses.size(); i++){
                sum += subclasses[i].get_subclass_weighted_average();
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
        (inWeight > 0) ? subclass_weight = inWeight : subclass_weight = 1;
    }

    void rename_subclass(string new_name){
        subclass_name = new_name;
    }   

    double get_subclass_weight () const{
        return subclass_weight;
    }

    double get_subclass_weighted_average() const{
        return weighted_total;
    }

    string get_subclass_name () const {
        return subclass_name;
    }

    void calculate_subclass_average(){
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
        calculate_subclass_average();
    }

    void display_subclass() const{
        cout << "Subclass Name: " << subclass_name << endl;
        cout << "Weight: " << subclass_weight << endl;
        cout << "Grades: ";
        int j = 1;
        for(double i : grades){
            cout << setw(5) << j << ": " << i << endl;
            j++;
        }
        cout << "Weighted Average: " << weighted_total << endl;
    }

    void insert_grade(double inNumber){
        if(inNumber < 0 || inNumber > 100){
            cout << "Invalid grade. Must be between 0 and 100" << endl;
        }
        else{ 
            grades.push_back(inNumber);
            calculate_subclass_average();            
        }

    }

    void clear_subclass(){
        grades.clear();
        subclass_weight = 0;
        weighted_total = 0;
        calculate_subclass_average();
        cout << "All data has been cleared " << endl;
    }   
};