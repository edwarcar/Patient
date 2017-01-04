
//
//// Created by Carrie Edwards on 12/13/16.
//

#include "Physician.hpp"
#include <iostream>
#include <string>
#include "Patient.hpp"
#include <vector>
using namespace std;

Physician::Physician()
{

name = ""; 

}

void Physician::setPhysicianName(string n)
{
   name = n;
}

string Physician::getPhysicianName()
{

   return name; 
}


void Physician::setRecordObject(Update* obj)
{
   record = obj;  
}

Update* Physician::getRecordObject()
{

   return record;  

}
