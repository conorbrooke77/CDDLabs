/**
 * @file MutualExclusionExample.cpp
 * @brief Demonstrates mutual exclusion using semaphores with multiple threads.
 * @author Conor Brooke
 * @date 30/09/2023
 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

static const int num_threads = 100; ///< Number of threads to be created.
int sharedVariable=0; ///< Variable that will be updated by multiple threads concurrently.

/**
 * @brief Updates the shared variable in a mutual exclusion manner.
 * 
 * This function demonstrates the concept of rendezvous, ensuring that only 
 * one thread updates the sharedVariable at a time using semaphores.
 * 
 * @param firstSem Semaphore used to ensure mutual exclusion.
 * @param numUpdates Number of times the shared variable should be updated by the calling thread.
 */
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
  for(int i = 0; i < numUpdates; i++){
    
    // Wait for the semaphore to become available
    firstSem->Wait();
    
    // UPDATE SHARED VARIABLE HERE!
    sharedVariable++;
    
    // Signal that the critical section is done
    firstSem->Signal();
  }
}

/**
 * @brief Main function that launches multiple threads to update the shared variable.
 * 
 * @return int Returns 0 on successful execution.
 */
int main(void){
  vector<thread> vt(num_threads); ///< Vector to hold all the thread objects.

  shared_ptr<Semaphore> aSemaphore(new Semaphore(1)); ///< Semaphore initialized to 1 to ensure mutual exclusion.
				    
  // Launch the threads
  for(thread& t: vt){
    t=thread(updateTask,aSemaphore,1000);
  }
  
  cout << "Launched from the main\n";
  
  // Join the threads with the main thread
  for (auto& v :vt){
      v.join();
  }
  cout << sharedVariable << endl; ///< Display the final value of sharedVariable after all threads have finished.
  return 0;
}
