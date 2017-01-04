/* ********************************************************************
 A uthor: Carrie Edwards
 * ** Date: 11/5/2016
 * * ** Description: This file contains the function for the inputValid class. 
 * * *********************************************************************/

#include <iostream>
#include <string>
#include "validateInput.hpp"
#include <cstdlib>
using namespace std; 

/*********************************************************************
 *  *  * ** Description: This function checks to make sure an integer was inputted by the user. It sends in the variable as a string, then determines if the string contains anything other than integers. If it does, it will prompt the user to enter a new value until the user enters an integer 
 *   *   * **
 *    *    * *********************************************************************/

int validateInput::checkInt(string intString)
{
    status = true;
    
    do
    {
        for(int x = 0; x < intString.length(); x++)
        {
            num = intString.at(x);
            
            if(num >= 48 && num <= 57)
            {   
                status = true; 
            }
            else
            {
                cout << "Please enter an integer." << endl;
                getline(cin, numEnt);
                intString = numEnt;
                status = false;
            }

        }
        
    }while(status == false);
    
    int value = atoi(intString.c_str());
    
    return value; 
    
}

/*********************************************************************
 *  *  * * * ** Description: This function checks to make sure that a value inputted by the user is in an acceptable range to prevent errors from occurring 
 *   *   * * * **
 *    *    * * * *********************************************************************/

int validateInput::checkRange(int intNum)
{
    string number; 
    stat = true;
    do
    {
        if(intNum < 1 || intNum > 4)
        {
            cout << "Please enter a number selection between 1 and 4." << endl;
            getline(cin, number);
            intNum = checkInt(number);  
            stat = false;
        }
        else
        {
            stat = true;
        }
        
    }while(stat == false);
    
    return intNum;

}

    
