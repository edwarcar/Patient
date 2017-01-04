//
// Created by Carrie Edwards on 12/13/16.
//

#include "Patient.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Patient::Patient()
{
    DOB = "";
    medication = "";
    medName = "";
    contact = "";
    diagnoses = "";
    size = 1;
    name = ""; 
    DOB = ""; 
    medName = "";
    diagnosisName = ""; 
    mSize = 0; 
    dSize = 0;  
    position = -1;  
    vector<string> medicationList = vector<string>(mSize);
    vector<string> diagnosisList = vector<string>(dSize);  

}

void Patient::patientName(string n)
{
    name = n;
}

string Patient::displayPatientName()
{
    return name; 
}

void Patient::patientDOB(string date)
{
    DOB = date;
}

string Patient::displayPatientDOB()
{
    return DOB;
}

void Patient::patientMedications(string meds)
{
        int index = 0;
        bool found = false;

        cout << "size: " << medicationList.size() << endl; 

      if(medicationList.size() != 0)
       {
          cout << "Here" << endl; 

        while(index < medicationList.size() && !found)
          {
                medName = this->medicationList.at(index);
                cout << "inside" << endl;  
                if(meds == medName)
                  {
                        found = true;
                        position = index;
                  }

                index++;
         }
 
       }  
         if(found == false)
         {
                cout << "YO" << endl; 
                medication = meds;
                mSize++; 
                //this->medicationList.resize(mSize);
                cout << "vector size: " << medicationList.size() << endl; 
                this->medicationList.push_back(medication);
                
                cout << "Position: " << mSize << endl; 
         }
         else if(found == true)
         {
                cout << "That medication has already been added." << endl;  
         }

cout << "Current size: " <<  medicationList.size() << endl; 

}

void Patient::displayPatientMedications()
{

for(int count = 0; count < medicationList.size(); count++)
       {
           medication = this->medicationList.at(count);
           cout << medication << endl;   
       }

}

void Patient::patientDiagnoses(string diag)
{
        int index = 0;
        bool found = false;
     
      if(diagnosisList.size() != 0)
      {
        while(index < diagnosisList.size() && !found)
          {
              diagnosisName = this->diagnosisList.at(index);

                if(diag == diagnosisName)
                  {
                        found = true;
                        position = index;
                  }

                index++;
          }
       } 
        if(found == false)
         {
                diagnoses = diag;
                dSize++;
                this->diagnosisList.resize(dSize);
                this->diagnosisList.push_back(diagnoses);
         }
         else if(found == true)
         {
                cout << "That diagnosis has already been added." << endl;
         }

cout << "size: " << diagnosisList.size() << endl; 
}

void Patient::displayPatientDiagnoses()
{

    cout << "size: " << diagnosisList.size() << endl; 

    for(int count = 0; count < diagnosisList.size(); count++)
       {
            diagnosisName = this->diagnosisList.at(count);
            cout << diagnosisName << endl;  
       }  
}

void Patient::patientContactInfo(string con)
{
    contact = con;
}

string Patient::displayPatientContactInfo()
{
    return contact;
}
