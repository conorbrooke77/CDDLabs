/**
 * @file SemaphoreExample.cpp
 * @brief Demonstrates the use of semaphores for thread synchronization.
 * @author Conor Brooke
 * @date 30/09/2023
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

/**
 * @brief Task function that simulates a delay and then displays a message.
 * 
 * @param theSemaphore The semaphore used for synchronization.
 * @param delay The time (in seconds) for which the task waits before printing.
 */
void taskOne(shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  
  // Display the first set of messages
  cout <<"I ";
  cout << "must ";
  cout << "print ";
  cout << "first"<<endl;

  // Signal to the semaphore that taskOne is done
  theSemaphore->Signal();
}

/**
 * @brief Task function that waits for a semaphore signal and then displays a message.
 * 
 * @param theSemaphore The semaphore used for synchronization.
 */
void taskTwo(shared_ptr<Semaphore> theSemaphore){
  
  // Wait until the semaphore gets the signal from taskOne
  theSemaphore->Wait();

  // Display the second set of messages
  cout <<"This ";
  cout << "will ";
  sleep(5);
  cout << "appear ";
  cout << "second"<<endl;
}

/**
 * @brief Main function that launches two threads and synchronizes them using semaphores.
 * 
 * @return int Returns 0 on successful execution.
 */
int main(void){
  // Declare two threads
  thread threadOne, threadTwo;

  // Create a shared semaphore object
  shared_ptr<Semaphore> sem(new Semaphore);

  // Set a delay for taskOne
  int taskOneDelay=5;

  // Launch the two tasks as threads
  threadOne=thread(taskTwo,sem);
  threadTwo=thread(taskOne,sem,taskOneDelay);

  // Wait until both threads have finished executing
  threadOne.join();
  threadTwo.join();

  cout << "Launched from the main\n";
  
  return 0;
}
