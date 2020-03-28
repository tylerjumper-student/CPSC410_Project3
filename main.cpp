/*
 * main.cpp,
 *
 *  Created on: Mar 24, 2020
 *      Author: tyler
 */

#include "tester.h"
#include "print_ts.h"

using namespace std;



int main() {
	string a = "hello";
	int numThrd = 3;
	int timestoPrnt = 5;
	int millSecDely = 200;
	
	startThreads(a, numThrd, P4, timestoPrnt, millSecDely);
	return 0;
 }