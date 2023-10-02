# Mutual Exclusion and Thread Synchronization Using Semaphores

This lab demonstrates the concepts of mutual exclusion and thread synchronization using semaphores. We explore two main scenarios:

1. Synchronizing two threads so that one thread prints its messages before the other.
2. Ensuring that only one of many threads can update a shared variable at a given time, demonstrating mutual exclusion.

## Description

### 1. Semaphore-based Synchronization

Two threads are launched: one displaying a message after a delay and another displaying its message upon receiving a signal from the first thread. This ensures that the messages are always printed in the correct order, regardless of how the threads are scheduled.

### 2. Mutual Exclusion with a Shared Variable

A large number of threads (`num_threads`) are launched concurrently. Each thread increments a shared variable multiple times. A semaphore ensures mutual exclusion
so that only one thread updates the shared variable at any given moment. After all threads have finished, the shared variable's final value shows the succussful implementation of mutual exclusion.

## Usage

1. Compile the program using the provided Makefile, `Mainmake`: make -f MainMake

## License

This project is licensed under the GNU General Public License (GPL). See the [LICENSE](https://www.gnu.org/licenses/gpl-3.0.en.html) file for details.

## Author

**Conor Brooke**
Email: conorbrooke19@gmail.com

## Repository

Git URL: [https://github.com/conorbrooke77/](https://github.com/conorbrooke77/Concurrent-Programming-Labs/tree/main/Lab1%20-%20The%20Basics)
