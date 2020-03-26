/*
 * main.cpp,
 *
 *  Created on: Mar 24, 2020
 *      Author: tyler
 */

#include "tester.h"
#include "print_ts.h"



int main() {
	std::string a = "hello";
	int numThrd = 4;
	int timestoPrnt = 1;
	int millSecDely = 200;
	
	startThreads(a, numThrd, P1, timestoPrnt, millSecDely);
	return 0;
}