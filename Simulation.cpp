/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 2: I.S.A.A.C and Operator Overloading
 * 17 October 2022
 */

/* This file contains the functionality for the Simulation class. This class
 * simulates two TAs both grading 80 students projects. These TAs have different
 * grading efficiencies, and these are accounted for. This class moves Janeway
 * and Sisko through their grading with their respective efficiencies, and 
 * displays their progress to the user.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Simulation.h"

using namespace std;

// an array that shows each TA's progress in their grading
char display[80];

// unsigned ints that store the TAs' respective locations
unsigned int janewayPos = 0;
unsigned int siskoPos = 0;

// this method moves Janeway through their grading process and takes a pointer
// to an integer that represents Janeway's position in the array
void Simulation::moveJaneway(unsigned int *ptrJaneway){
	int chance = rand() % 100;
	display[*ptrJaneway] = '-';
	// randomly determies grading action for Sisko
	if(chance < 50){
		if(*ptrJaneway < sizeof(display) - 3){
			*ptrJaneway += 3;
		}
		else{
			*ptrJaneway += sizeof(display) - *ptrJaneway - 1;
		}
	}
	else if(chance > 84){
		if(*ptrJaneway >= 6){
                        *ptrJaneway -= 6;
                }
                else{
                        *ptrJaneway -= *ptrJaneway;
                }
	}
	else{
		if(*ptrJaneway < sizeof(display) - 1){
                        *ptrJaneway += 1;
                }
                else{
                        *ptrJaneway += sizeof(display) - *ptrJaneway - 1;
                }
	}
	display[*ptrJaneway] = 'J';
}

// this method moves Sisko through their grading process and takes a pointer
// to an integer that represents Sisko's position in the array
void Simulation::moveSisko(unsigned int *ptrSisko){
	int chance = rand() % 100;
	// checks if new Janeway position is old Sisko position.
	// in this case, old Sisko position is not reset to -
	if(display[*ptrSisko] != 'J'){
	        display[*ptrSisko] = '-';
	}
	// randomly determies grading action for Sisko
        if(chance < 5){
		if(*ptrSisko >= 12){
                        *ptrSisko -= 12;
                }
                else{
                        *ptrSisko -= *ptrSisko;
                }
	}
	else if(chance < 35){
		if(*ptrSisko < sizeof(display) - 1){
                        *ptrSisko += 1;
                }
                else{
                        *ptrSisko += sizeof(display) - *ptrSisko - 1;
                }
	}
	else if(chance < 65){
		if(*ptrSisko < sizeof(display) - 9){
                        *ptrSisko += 9;
                }
                else{
                        *ptrSisko += sizeof(display) - *ptrSisko - 1;
                }
	}
	// checks if new Sisko position is also new Janeway position
	if(display[*ptrSisko] == 'J'){
		display[*ptrSisko] = '!';
	}
	else{
        	display[*ptrSisko] = 'S';
	}
}

// this method contains the main simulation functionality
void Simulation::runOneGame(){
	// simulation runs until condition is true
	bool gameOver = false;
	// intializes random number generator
	srand(time(0));
	// declares and assigns pointers to each TA's position variables
	unsigned int *janewayPtr;
	janewayPtr = &janewayPos;
	*janewayPtr = 0;
	unsigned int *siskoPtr;
	siskoPtr = &siskoPos;
	*siskoPtr = 0;
	// sets the display to default - characters
	setProgress();
	cout<<"                        Running I.S.A.A.C. Simulation..."<<endl;
	cout<<"                        Janeway: J              Sisko: S"<<endl;
	cout<<"     <<< Intelligent System for Academic Assistance in Computing Simulation >>>"<<endl;
	while(!gameOver){
		cout<<"[ ";
		for(int i = 0; i < sizeof(display); i++){
			cout<<display[i];
		}
		cout<<" ] "<<endl;
		// checks for winner
		if(display[sizeof(display) - 1] != '-'){
	                if(display[sizeof(display) - 1] == 'J'){
	                        gameOver = true;
	                        cout<<"JANEWAY WINS!!!!\n"<<endl;
	                }
	                if(display[sizeof(display) - 1] == 'S'){
	                        gameOver = true;
	                        cout<<"SISKO WINS!!!\n"<<endl;
	                }
	                if(display[sizeof(display) - 1] == '!'){
	                        gameOver = true;
	                        cout<<"WOW!!! A TIE!!!\n"<<endl;
	                }
                }
		// if no winner, the TA's are moved again and the program
		// pauses for one second
		else{
			moveJaneway(janewayPtr);
			moveSisko(siskoPtr);
			usleep(999999);
		}
	}
}

// initliazes the display with - characters
void Simulation::setProgress(){
	for(int i = 0; i < sizeof(display); i++){
		display[i] = '-';
	}
}
