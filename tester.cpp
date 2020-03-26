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

#include "tester.h"
#include "print_ts.h"

using namespace std;

vector<thread> threads;

/*
 * starts cancelable threads
 * string s			-the string to print
 * numThreads 		-the number of threads to start
 * wp 				-which print statement should be used
 * numTimesToPrint 	-the number of PRINT statements each thread will call
 * millisecond_delay- how long (in milliseconds) to wait between prints
 */
void startThreads(std::string s, int numThreads, WHICH_PRINT wp, int numTimesToPrint, int millisecond_delay){
    //I think this is running correctli so far. don't sleep on this though

    //for loop that creates a thread for whatever number numThreads is
    for (int i = 0; i < numThreads ; ++i) {
        //right here you should call sleep or whatever call it is to delay the prints

        /*numTimesToPrint never changes so this will run as many times as the for loop does
                if numTimes to print is 1 and numThreads is 4...
        */
        switch (numTimesToPrint) {
            //...then this case will be called 4 times, creating 4 different threads and sending them to PRINT1
        case 1:
            threads.push_back(thread(PRINT1, std::ref(s)));
            
            break;
        case 2:
            threads.push_back(thread(PRINT2, std::ref(s), std::ref(s)));
            break;
        case 3:
            threads.push_back(thread(PRINT3, std::ref(s), std::ref(s), std::ref(s)));
            break;
        case 4:
            threads.push_back(thread(PRINT4, std::ref(s), std::ref(s), std::ref(s), std::ref(s)));
            break;
        case 5:
            threads.push_back(thread(PRINT5, std::ref(s), std::ref(s), std::ref(s), std::ref(s), std::ref(s)));
            break;
        default:
            cout << "invalid number, please try again with a number between 1-4" << endl;
            break;
        }

        
    }

}

/*
 * if bCanceled== true then causes all running threads to print USER_CHOSE_TO_CANCEL and then exit
 * if false then just reset logic used to cancel threads
 */
void setCancelThreads(bool bCancel){

    //need to check this one out to see if I'm doing it correctly
    if (bCancel == true) {
        //all running threads print USER_CHOSE_TO_CANCEL and then exit
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
    cout << "All threads done" << endl;
}
