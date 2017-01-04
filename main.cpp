#include <iostream>
#include <string>
#include "Patient.hpp"
#include "Update.hpp"
#include "Physician.hpp"
#include "validateInput.hpp"
using namespace std;

int main()
{

//Physician vector declaration
vector<Physician*> physiciansList(0); 

//variable declarations
int entry;
int value;
int input; 
int size = 1; 
int position = -1; 
string physician; 
string patient; 
string entryVal; 
string inputVal;
string name; 

//create objects
Update obj;
validateInput validate; 

//create Physician pointer
Physician* pName;

//create Records pointer 
Update* updateObj; 

cout << "Welcome to the medical record system. " << endl;
cout << endl;

do
{

cout << "Main menu: " << endl;
cout << "1) Add a physician to the database. " << endl; 
cout << "2) Edit patients within a physician's patient list. " << endl; 
cout << "3) Display list of physician's patients. " << endl; 
cout << "4) Remove a patient from the list." << endl; 
getline(cin, inputVal); 
input = validate.checkInt(inputVal); 

if(input == 1)
{


cout << "Enter the name of the physician you would like to add" << endl; 
getline(cin, physician);

pName = new Physician; 

//add new physician to the vector 
physiciansList.push_back(pName); 

size++;

physiciansList.resize(size);

updateObj = new Update; 
 
pName->setPhysicianName(physician); 
pName->setRecordObject(updateObj); 

} 
else if(input == 2)
{
 int index = 0;
 bool found = false;

 cout << "Enter the name of the physician whose patient list you would like to access." << endl; 
 getline(cin, name);  


      //check if physician is in list 

      if(physiciansList.size() != 0)
      {

        while(index < physiciansList.size() && !found)
          {
              
                pName = physiciansList.at(index);

                cout << "indeex: " << index << endl; 

                if(pName->getPhysicianName() == name)
                  {
                        cout << "found" << endl; 
                        found = true;
                        position = index;
                  }
                else
                  {
                        cout << "Not found" << endl; 
                        found = false;
                        position = -1; 
			cout << "size: " << physiciansList.size() << endl; 

                        index++;  
                         
                  }
                
          }

          cout << "checked list" << endl; 
      }
      if(position == -1)
      {
               cout << "Physician not found in record. " << endl;
      }
        else
        {
               cout << "Found" << endl; 
        
	if(index != 0)
  	{
          pName = physiciansList.at(position);
          updateObj = pName->getRecordObject();
  	}
 
        do
        {

		cout << "Please select from the following options." << endl;
		cout << "1) Add an entry. " << endl;
		cout << "2) Update an entry. " << endl;
		cout << "3) Search for an entry. " << endl;
		cout << "4) Sort the entries in alphabetical order " << endl;
		cout << "5) Remove an entry." << endl; 
		cout << "6) Finished updating entries." << endl; 
		getline(cin, entryVal);
		entry = validate.checkInt(entryVal); 

    	if(entry == 1)
    	{
        	updateObj->addPatient();
    	}
    	else if(entry == 2)
    	{
        	updateObj->updateEntry();
    	}
    	else if(entry == 3)
    	{
        	updateObj->searchEntry();
    	}
    	else if(entry == 4)
    	{
        	updateObj->sortEntry();
    	}
    	else if(entry == 5)
    	{
        	updateObj->removeEntry(); 
    	}

     
	}while(entry != 6); 

	}
}

else if(input == 3)
{

    if(physiciansList.size() > 0)
      { 
        //display patients of specified physician 
        updateObj = pName->getRecordObject(); 
	updateObj->display();  
      }
    else
     {
         cout << "There are no patients currently in the list. " << endl; 
     }
}
else if(input == 4)
{
     if(physiciansList.size() > 0)
      {  
        //display all patients in the system 
	for(int count = 0; count < physiciansList.size(); count++)
         {
	      pName = physiciansList[count]; 
              updateObj = pName->getRecordObject(); 
              updateObj->display();
         }
      }
     else
      {
	  cout << "There are currently no patients in the system. " << endl; 
      }  
}
else if(input == 5)
{

//Displaying all patients within physician system
for(int index = 0; index < physiciansList.size(); index++)
{ 
	cout << "Physician name: ";
	pName = physiciansList.at(index); 
	cout << pName << endl; 
	cout << "Patients: " << endl;  
	updateObj = pName->getRecordObject();  
	updateObj->display(); 

}

}

}while(input < 6); 

//clear dynamically allocated memory
delete updateObj; 

for(int i = 0; i < physiciansList.size(); i++)
{
    delete physiciansList[i];
}

return 0;

}
