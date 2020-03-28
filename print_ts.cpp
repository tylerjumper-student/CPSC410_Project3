/*
 * print_ts.cpp,
 *
 *  Created on: Mar 24, 2020
 *      Author: tyler
 */

#include "print_ts.h"
#include "tester.h"
#include<thread>
#include <mutex>
#include <iostream>

using namespace std;

mutex m;

//when I run this an abort error occurs, debug and you will see the problem I can look it up online tomorrow

void PRINT1(std::string& txt) {
	m.lock();
	cout << txt <<endl;
	m.unlock();
}
void PRINT2(std::string& txt, std::string& txt1) {
	m.lock();
	cout << txt << txt1 << endl;
	m.unlock();
}
void PRINT3(std::string& txt, std::string& txt1, std::string& txt2) {
	m.lock();
	cout << txt << txt1 << txt2 << endl;
	m.unlock();
}
void PRINT4(std::string& txt, std::string& txt1, std::string& txt2, std::string& txt3) {
	m.lock();
	cout << txt << txt1 << txt2 << txt3 << endl;
	m.unlock();
}
void PRINT5(std::string& txt, std::string& txt1, std::string& txt2, std::string& txt3, std::string& txt4){
	m.lock();
	cout << txt << txt1 << txt2 << txt3 << txt4 <<endl;
	m.unlock();
}