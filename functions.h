#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
#include <ctime>

using namespace std;


// Variables 
char Student_name[100], Student_ID[100];
int target_student_id, random_hours;
string Major;
int prog_hours, comput_physics_hours, gen_lab_hours, calculus_hours;

string target_students[3] = {"COSC", "MATH", "PHYS"};
string hours[4] = {"Computational Physics Hours", "General Lab Hours", "Calculus Hours", "Programming Hours"};

float GPA;
float gpa;
string hour_type;

// Generate random target student
int random_target_student () {
    srand(time(0));
    target_student_id = (rand() % 3);
    return target_student_id;

    }

// Generate random hours
int random_number_generator(int num) {
    srand(time(0));
    random_hours = (rand() % num);
    return random_hours;
}


// Get student details
string student_details () {

    cout << "Please enter your full name: ";
    cin.getline (Student_name, 100);

    cout << "Please enter your student ID: ";
    cin >> Student_ID;

    cout << "\n";
}


// Check number of hours
string check_hours() {
    if (hours[random_number_generator(4)] == "Programming Hours") 
    cout << "Programming hours          "<<  prog_hours << "\n\n";
    // return "prog_hours";

    if (hours[random_number_generator(4)] == "Computational Physics Hours") 
    cout << "Computational Physics Hours          "<<  comput_physics_hours << "\n\n";
    // return "comput_physics_hours";

    if (hours[random_number_generator(4)] == "Calculus Hours") 
    cout << "Calculus hours          "<<  calculus_hours << "\n\n";
    // return "calculus_hours";

    if (hours[random_number_generator(4)] == "General Lab Hours") 
    cout << "General Lab hours          "<<  gen_lab_hours << "\n\n";
    // return "gen_lab_hours";
}      


// GPA Generator
double gpa_generator() {

    srand(time(0));
    int low = (rand() % 4);
    int high = (rand() % 6);

    double random_decimals[100] = {0.01, 0.02, 0.3, 0.5, 0.87, 0.36, 0.55, 0.3, 0.1,0.9,0.99,0.56,0.36,0.17,0.287,0.88,0.89,0.23,0.64,0.25,0.14,0.26,0.27};
    // gpa = low + static_cast<float>(rand()) * static_cast<float>(high-low) / RAND_MAX;
    gpa = 1 + (rand() % 3);
    gpa = gpa + random_decimals[random_number_generator(50)]; 

    
    return gpa;
 }


// Check project qualification 
string project_qualification () {

    cout << "Greetings " << Student_name << "\n";
    cout << "Here is what we have on record for you:" << "\n";

    prog_hours = (8 + rand() % 15);
    comput_physics_hours = (5 + rand() % 15);
    calculus_hours = (7 + rand() % 15);
    gen_lab_hours = (10 + rand() % 12);

    Major = target_students[random_target_student()];
    GPA = gpa_generator();

    cout << "Name:                      "<< Student_name << "\n";
    cout << "Student ID                 "<< Student_ID << "\n";
    cout << "Major                      "<<  Major << "\n";
    cout << "GPA                        "<<  GPA  << "\n";

    check_hours();
    
    cout << "Here is the possible list of projects you qualify for: " << "\n";

    // ProjectQualification
    if (Major == "COSC") {
        if (GPA >= 3.25 && prog_hours >= 9) {
            cout << "Project A";
        }
        else {
            cout << "Unfortunately, you do not qualify for any project at this time." << "\n";
            cout << "---------------------------------------------------------" << "\n";
        }
    }

    else if (Major == "PHYS") {
        if (GPA >= 3.25 && comput_physics_hours >= 6) {
            cout << "Project A";
        }
        if (GPA > 3.00 && gen_lab_hours >= 12) {
            cout << "Project B";
        }
        else {
            cout << "Unfortunately, you do not qualify for any project at this time." << "\n";
            cout << "---------------------------------------------------------" << "\n";
        }
    }

    else if (Major == "MATH") {
        if (GPA >= 3.25 && calculus_hours >= 9) {
            cout << "Project A";
        }
        if (GPA > 3.00) {
            cout << "Project B";
        }
        else {
            cout << "Unfortunately, you do not qualify for any project at this time." << "\n";
            cout << "---------------------------------------------------------" << "\n";
        }
    }
}

#endif


// Wlexor Mercy