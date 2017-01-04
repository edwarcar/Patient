//
// Created by Carrie Edwards on 12/13/16.
//

#include "Update.hpp"
#include "Patient.hpp"
#include "validateInput.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

Update::Update()
{

    input = 0;
    patientPosition = 0;
    name = "";
    dob = "";
    med = "";
    dia = "";
    cont = "";
    entry = "";
    inp = ""; 
    newPatient = NULL; 
    size = 0;
    position = -1;
    patientsName = ""; 
    patName = "";  
    
    //create patient objects
    Patient info;

    //create a vector
    vector<Patient*> patientList = vector<Patient*>(size); 
}

Update::~Update()
{

//deallocate dynamic memory
for (int i = 0; i < patientList.size(); i++)
{
    delete patientList[i];
}

}

void Update::addPatient()
{
    size += 1;
    this->patientList.resize(size);

    //create a new patient object
    //delete newPatient;
    newPatient = new Patient;

    //add new patient object to the vector
    this->patientList.push_back(newPatient);

    cout << "Please enter the patient's name." << endl; 
    getline(cin, name); 
    newPatient->patientName(name); 

    cout << "Please enter the patient's date of birth." << endl;
    getline(cin, dob); 
    newPatient->patientDOB(dob);

    cout << "Please enter the patients medications." << endl;
    cout << "You can enter names of medications one at a time. Enter x when you are finished entering medications." << endl;  
    do
    {
    	getline(cin, med); 
    
        if(med != "x")
        {
    		newPatient->patientMedications(med);
        }

    }while(med != "x");  

    cout << "Please enter the patient's diagnoses." << endl;
    cout << "You can enter diagnoses one at a time. Enter x when you are finished entering diagnoses." << endl;
    
    do
    {

    getline(cin, dia);
    
    if(dia != "x")
    {
        newPatient->patientDiagnoses(dia);
    }

    }while(dia != "x"); 

    cout << "Please enter the patient's contact information." << endl;
    getline(cin, cont);
    newPatient->patientContactInfo(cont);

}

void Update::updateEntry()
{

    cout << "What patient would you like to update?" << endl;
    getline(cin, patientsName);

    if (position != -1)
    {
        do 
         {
            cout << "What would you like to do? " << endl;
            cout << "1) Update patient's name." << endl;
            cout << "2) Update patient's date of birth." << endl;
            cout << "3) Update patient's medications." << endl;
            cout << "4) Update patient's diagnoses." << endl;
            cout << "5) Update patient's contact information." << endl;
            cout << "6) Delete patient from record. " << endl;
            cout << "7) Finished updating." << endl;
            getline(cin, inp); 
            input = obj.checkInt(inp); 
  
            if (input == 1)
            {
                cout << "Enter the name that you would like to replace " << newPatient->displayPatientName() << " with: " << endl;
                getline(cin, name); 
                newPatient->patientName(name);
            }
            else if (input == 2)
            {
                cout << "Enter the date of birth that you would like to replace for " << newPatient->displayPatientName() << "'s current date of birth.  " << endl;
                getline(cin, dob);
                newPatient->patientDOB(dob);
            }
            else if (input == 3)
            {
  		cout << "Would you like to add a medication, or delete an existing one?" << endl; 
                cout << "Enter 1 for add new medication, or 2 for delete an existing one." << endl; 
		getline(cin, entry); 

  
                cout << "Enter the medication you would like to add for " << newPatient->displayPatientName()  << endl;
                getline(cin, med);
                newPatient->patientMedications(med);

            }
            else if (input == 4)
            {
                cout << "Enter the diagnosis you would like to add for " << newPatient->displayPatientName() << endl; 
                getline(cin, dia); 
                newPatient->patientDiagnoses(dia); 
            }
            else if (input == 5)
            {
		cout << "Enter the contact information you would like to update for " << newPatient->displayPatientName() << endl; 
                getline(cin, cont); 
                newPatient->patientContactInfo(cont);  
            }
            else if (input == 6)
            {
		removeEntry(); 
            }

        } while (input <= 6);

    }
    else
    {
        cout << "That patient wasn't found in record." << endl;
    }
}

void Update::searchEntry()
{

    //search the vector
    cout << "What patient would you like to search for?" << endl;
    getline(cin, patientsName);

        int index = 1; 
        bool found = false; 

        while(index <= patientList.size() && !found)
          {
               newPatient = this->patientList.at(index);

               patName = newPatient->displayPatientName();  
                
        	if(patName == patientsName)
                  {
			found = true; 
                        position = index; 
                  }
 
                index++;  
          }
 
         if(position == -1)
         {
		cout << "Patient not found in record. " << endl;

         }
         else
         {
        	newPatient = this->patientList.at(position);

        	display();
         }
}

void Update::sortEntry()
{
    //sort the vector
    sort(this->patientList.begin(), this->patientList.end());
    display(); 
}

void Update::display()
{
    //display patient's information
    cout << "Patient name: " << newPatient->displayPatientName() << endl;
    cout << "Patient date of birth " << newPatient->displayPatientDOB() << endl;
    cout << "Patient's diagnoses: " << endl;  
    newPatient->displayPatientDiagnoses();
    cout << "Patient's medications: " << endl; 
    newPatient->displayPatientMedications();
    cout << "Patient's contact information: " << newPatient->displayPatientContactInfo() << endl;
}

void Update::removeEntry()
{

cout << "Which entry would you like to remove?" << endl; 
getline(cin, entry); 

        int index = 1;
        bool found = false;

        while(index <= patientList.size() && !found)
          {
               newPatient = this->patientList.at(index);

               patName = newPatient->displayPatientName();

                if(patName == entry)
                  {
                        found = true;
                        position = index;
                  }

                index++;
          }


         if(position == -1)
         {
                cout << "Patient not found in record. " << endl;

         }
         else
         {
                patientList.erase(patientList.begin() + position); 
         }


}
