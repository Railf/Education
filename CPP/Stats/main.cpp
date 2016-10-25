/*  main.cpp - Function main, Function Calls
    September 11, 2016
    Ralph McCracken, III    */

#include <iostream> // include i/o standard library
#include "stats.h"  // include stats.h header file, function prototypes

// front-end of the program
// calls functions, Mean and Median
int main() {
  int num;            // user input
  size_t size = 0;    // counter variable, size, initialized at 0
  int array[100];     // user input value storage array, size of 100
    
  // prompt user for data, integers
  std::cout << "Enter integers ('x' to quit): ";
  
  while (size < 100 && std::cin >> num)       // while receiving integers, and no more than 100 integers
  {
    array[size] = num;                      // store input integer in respective array location
    ++size;                                 // prepare next array location for input storage
  }
  
  // output data
  std::cout << "\nData as entered:  ";                                // array, as entered
  for(size_t count = 0; count < size; ++count)                        // list each element of the array, one after the next
  {
    std::cout                               << array[count] << " "; // list array element and add a space to separate
  }
  std::cout << "\nMean:\t"                    << Mean(array, size);   // function call of Mean
  std::cout << "\nMedian:\t"                  << Median(array, size); // function call of Median
  std::cout << "\nData after sort:  ";                                // array, after Median's Sort function call
  for(size_t count = 0; count < size; ++count)                        // list each element of the array, one after the next
  {
    std::cout                               << array[count] << " "; // list array element and add a space to separate
  }
  std::cout << "\n";                                                  // new line
  
} // end function, main
