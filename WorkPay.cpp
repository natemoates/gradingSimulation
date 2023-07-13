/* Nathaniel Oates
 * CPSC 1070: 010
 * Project 2: I.S.A.A.C and Operator Overloading
 * 17 October 2022
 */

/* This file contains the functionality for the WorkPay class. The WorkPay
 * class takes an integer in it's constructor and sets the class's hoursData
 * and daysData variables. The class allows the data in these variables to 
 * be retrieved, and allows each piece of data to be manipulated with 
 * overloaded operators.
 */


#include <iostream>
#include <cstdlib>
#include "WorkPay.h"

using namespace std;

// Constructor
WorkPay::WorkPay(int hours){
	hoursData = static_cast<double>(hours);
	daysData = hoursData/8;
}

// stores data in class variables
void WorkPay::storeData(int num){
	if(num < 0){
		hoursData = static_cast<double>(0);
        	daysData = hoursData/8;
	}
	else{
		hoursData = static_cast<double>(num);
		daysData = hoursData/8;
	}
}

// when called, returns the class's hours stored
double WorkPay::retrieveHours(){
	return hoursData;
}

// when called, returns the class's days stored
double WorkPay::retrieveDays(){
	return daysData;
}

//overloaded operators
WorkPay WorkPay::operator+(double num){
	WorkPay obj;
	hoursData += num;
	daysData = hoursData/8;
	obj.storeData(hoursData);
	return obj;
}

WorkPay WorkPay::operator-(double num){
	WorkPay obj;
	// checks if the number being subtracted from hoursData is smaller or 
	// equal to hours data, if it is not it sets hoursData and daysData to 0
	if(num <= hoursData){
		hoursData -= num;
		daysData = hoursData/8;
		obj.storeData(hoursData);
	}
	else{
		hoursData = 0;
		daysData = 0;
		obj.storeData(hoursData);
	}
	return obj;
}

WorkPay WorkPay::operator++(int){
	WorkPay obj;
	obj.storeData(hoursData);
	daysData++;
	hoursData+=8;
	return obj;
}

WorkPay WorkPay::operator--(int){
	WorkPay obj;
	obj.storeData(hoursData);
	daysData--;
	hoursData-=8;
	return obj;
}

WorkPay WorkPay::operator++(){
	WorkPay obj;
	hoursData += 8;
	daysData++;
	obj.storeData(hoursData);
	return obj;
}

WorkPay WorkPay::operator--(){
	WorkPay obj;
	hoursData -= 8;
	daysData--;
	obj.storeData(hoursData);
	return obj;
}
