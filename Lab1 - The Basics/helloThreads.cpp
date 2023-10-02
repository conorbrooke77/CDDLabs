#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

/*! displays a message first*/
void taskOne(shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);  // Adding a delay
  
  // Display the first set of messages
  cout <<"I ";
  cout << "must ";
  cout << "print ";
  cout << "first"<<endl;

  // Signal to the semaphore that taskOne is done
  theSemaphore->Signal();
}

/*! displays a message second*/
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
