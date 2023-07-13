/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 2: I.S.A.A.C and Operator Overloading
 * 17 October 2022
 */

/* This file is the driver file for the implementation of two classes:
 * the WorkPay and Simulation classes. This class includes each class's
 * header file, and creates an object for each class. The user in prompted
 * and inputs S or W depending on which class's object the user would like
 * to test. If W is selected, a WorkPay object is constructed, and each
 * of the class's public methods is called, including the class's overloaded
 * operators, and various outputs are printed to display the class's updated
 * data. If S is selected, a Simulation object is constructed and the class's
 * runOneGame() method is called. If the user selects Q, the program will stop
 * running. The user will continue to be prompted to give either S, W, or Q 
 * until Q is selected by the user.
 * */

// importing libraries
#include <iostream>
#include <cstdlib>
// importing class header files
#include "WorkPay.h"
#include "Simulation.h"

using namespace std;

char input;
bool running = true;

/* main function that continuously prompts the user to run Simulation
 * or WorkPay until the user decides to quit.
 */
int main(){
	do{
		cout<<"S for Simulation and W for WorkPay: ";
	        cin>>input;
		switch(input){
			case 'S':
			case 's':
				// defines a scope so that an object may be created in this case
				{
					Simulation sim;
					sim.runOneGame();
					break;
				}
			case 'W':
			case 'w':
				//defines a  scope so that an object may be created in this case
				{
					WorkPay wp;
					wp.storeData(12);
					cout<<"Hours: "<<wp.retrieveHours()<<endl;
					cout<<"Days: "<<wp.retrieveDays()<<endl;
					wp = wp + 3;
					cout<<"Hours: "<<wp.retrieveHours()<<endl;
					wp = wp - 3;
					cout<<"Hours: "<<wp.retrieveHours()<<endl;
					wp++;
					cout<<"Days: "<<wp.retrieveDays()<<endl;
					wp--;
					cout<<"Days: "<<wp.retrieveDays()<<endl;
					--wp;
					cout<<"Days: "<<wp.retrieveDays()<<endl;
					++wp;
					cout<<"Days: "<<wp.retrieveDays()<<endl;
					cout<<endl;
					break;
				}
			case 'Q':
			case 'q':
					// sets the condition on which the continous loop is running to false
					running = false;
					break;
			default:
					// Performs input validation.
					cout<<"Invalid Input. Please try again."<<endl;
		}
	}while(running);
}
