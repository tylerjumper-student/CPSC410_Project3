/*
 * tester.cpp,
 *
 *  Created on: Mar 24, 2020
 *      Author: tyler
 */

#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <chrono>

#include "tester.h"
#include "print_ts.h"

using namespace std;

int numPrints = 0;
vector<thread> threads;

/*
 * helper method for numTimesToPrint
 */
void helperPrintMethod(std::string str, WHICH_PRINT wp, int printTimes, int ms_delay, int timesPrinted) {

    while (timesPrinted <= printTimes) {
        switch (wp)
        {
        case P1:
            PRINT1(str);
            this_thread::sleep_for(chrono::milliseconds(ms_delay));	//will be millisecond_delay
            break;
        case P2:
            PRINT2(str, str);
            this_thread::sleep_for(chrono::milliseconds(ms_delay));	//will be millisecond_delay
            break;
        case P3:
            PRINT3(str, str, str);
            this_thread::sleep_for(chrono::milliseconds(ms_delay));	//will be millisecond_delay
            break;
        case P4:
            PRINT4(str, str, str, str);
            this_thread::sleep_for(chrono::milliseconds(ms_delay));	//will be millisecond_delay
            break;
        case P5:
            PRINT5(str, str, str, str, str);
            this_thread::sleep_for(chrono::milliseconds(ms_delay));	//will be millisecond_delay
            break;
        default:
            cout << "Error please check which print method you selected" << endl;
            break;
        }
        timesPrinted++;
    }

}

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay){     
    //string* p = &s;
    //for loop that creates a thread for whatever number numThreads is
    //sends it to helper method
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(std::thread(helperPrintMethod, s, wp, numTimesToPrint, millisecond_delay, numPrints));    //I get errors when i leave the string s alone but 
                                                                                                                   //when I pass it as ref(s) I don't get an error. 
                                                                                                                 //But it won't run or pass the actual value
    }
}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel){

    //need to check this one out to see if I'm doing it correctly
    if (bCancel == true) {
        //all running threads 

        //print USER_CHOSE_TO_CANCEL and then exit
        cout << USER_CHOSE_TO_CANCEL << endl;
    }
    else {
        bCancel = !bCancel;
    }
}
/*
 * waits for all threads to complete
 */
void joinThreads(){
    //need to check this one out to see if I'm doing it correctly


    for (auto& thread : threads) {
        thread.join();
    }
    threads.clear();
    cout << "All threads done" << endl;
}




