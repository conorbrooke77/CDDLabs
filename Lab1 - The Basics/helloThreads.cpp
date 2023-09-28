#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;

/*! displays a message first*/
void taskOne(shared_ptr<Semaphore> theSemaphore, int delay){
  sleep(delay);
  cout <<"I ";
  cout << "must ";
  cout << "print ";
  cout << "first"<<endl;

  //tell taskTwo to start now
  theSemaphore->Signal();
}

/*! displays a message second*/
void taskTwo(shared_ptr<Semaphore> theSemaphore){
  //wait here until taskOne finishes...
  theSemaphore->Wait();
  
  cout <<"This ";
  cout << "will ";
  sleep(5);
  cout << "appear ";
  cout << "second"<<endl;
  
}


int main(void){
  thread threadOne, threadTwo;
  shared_ptr<Semaphore> sem( new Semaphore);
 
  /**< Launch the threads  */
  int taskOneDelay=5;
  
  threadOne=thread(taskTwo,sem);
  threadTwo=thread(taskOne,sem,taskOneDelay);

   /**< Wait for the threads to finish */
  threadOne.join();
  threadTwo.join();

  cout << "Launched from the main\n";
  return 0;
}
