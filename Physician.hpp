
#ifndef PRACTICE_PHYSICIAN_H
#define PRACTICE_PHYSICIAN_H

#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Patient.hpp"
#include "Update.hpp"

class Update; //forward declaration

class Physician 
{

private:
    string name;
    Update* record; 
 
public:
    Physician(); 
    void setPhysicianName(string name);
    string getPhysicianName(); 
    void setRecordObject(Update* obj);
    Update* getRecordObject();   
};


#endif //PRACTICE_PATIENT_H

