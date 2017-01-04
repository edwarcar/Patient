//
// Created by Carrie Edwards on 12/13/16.
//

#ifndef PRACTICE_PATIENT_H
#define PRACTICE_PATIENT_H

#include <iostream>
using namespace std;
#include <string>
#include <vector> 

class Patient
{

private:
    string name;
    string DOB;
    string medication;
    string medName; 
    string contact;
    string diagnoses;
    string diagnosisName; 
    int position;
    int size;
    int mSize; 
    int dSize;  
    vector<string> medicationList; 
    vector<string> diagnosisList;

public:
    Patient(); 
    void patientName(string name);
    void patientDOB(string date);
    void patientMedications(string meds);
    void patientDiagnoses(string conditions);
    void patientContactInfo(string info);
    string displayPatientName();
    string displayPatientDOB(); 
    void displayPatientMedications();
    void displayPatientDiagnoses(); 
    string displayPatientContactInfo(); 

};


#endif //PRACTICE_PATIENT_H
