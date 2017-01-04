//
// Created by Carrie Edwards on 12/13/16.
//

#ifndef PRACTICE_UPDATE_H
#define PRACTICE_UPDATE_H


#include <iostream>
using namespace std;
#include <string>
#include <vector>  
#include "Patient.hpp"
#include "validateInput.hpp"

class Patient; //forward declaration

class Update
{

private:
    int size;
    int position;  
    Patient *newPatient;
    validateInput obj;  
    string patName; 
    int input;
    string patientsName;
    int patientPosition;
    string name; 
    string dob;
    string med; 
    string dia;  
    string cont;
    string entry; 
    string inp;  
    vector<Patient*> patientList;

public:
    Update();
    ~Update(); 
    void addPatient();
    void updateEntry();
    void searchEntry();
    void sortEntry();
    void display();
    void removeEntry(); 
};


#endif //PRACTICE_UPDATE_H
