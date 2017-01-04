
/*********************************************************************
 *  * ** Author: Carrie Edwards
 *  * ** Date: 11/5/2016
 *  * ** Description: This file contains the class declaration for the inputValid class, including private member variables and public function prototype.  
 *  * *********************************************************************/


#include <iostream>
#include <string> 
using namespace std; 

#ifndef INPUTVALIDATE_HPP
#define INPUTVALIDATE_HPP

class validateInput 
{

private:
	bool status;
 	bool stat;
	int number;  
	int num; 
	int intString;
	string numEnt;
 
public:
	int checkInt(string intString);
	int checkVal(int intNum);
        int checkRange(int intNum); 
        int checkValue(int intNum); 
};

#endif


