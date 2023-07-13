/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 2: I.S.A.A.C and Operator Overloading
 * 17 October 2022
 */

// WorkPay class header file

#ifndef WORKP_H
#define WORKP_H

class WorkPay{
	public:
		//default constructor through constructor delegation
		WorkPay() {WorkPay(8);};

		WorkPay(int);
		void storeData(int);
		double retrieveHours();
		double retrieveDays();
		WorkPay operator+(double);
		WorkPay operator-(double);
		WorkPay operator++(int);
		WorkPay operator--(int);
		WorkPay operator++();
		WorkPay operator--();
	private:
		double hoursData;
		double daysData;
};
#endif
