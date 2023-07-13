/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 2: I.S.A.A.C and Operator Overloading
 * 17 October 2022
 */

//Simulation class header file


#ifndef SIM_H
#define SIM_H

class Simulation{
	public:
		void runOneGame();
	private:
		void moveJaneway(unsigned int *ptrJaneway);
		void moveSisko(unsigned int *ptrSisko);
		void setProgress();
};
#endif
