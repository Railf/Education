/*  stats.cpp - Function Implementation, Function Calls
    September 11, 2016
    Ralph McCracken, III    */

#include <iostream> // include i/o standard library
#include "stats.h"  // include stats.h header file, function prototypes

// calculates mean of data in array
float Mean (const int* array, size_t size)
{
    float mean = 0.0;   // initialize float variable, mean, to 0.0
    int sum = 0;        // initialize int variable, sum, to 0
    
    // go through each element of the array, one by one
    for(size_t count = 0; count <= size-1; ++count)
    {
        sum += array[count];    // sum is equal to the value in sum plus the next array element
    }// end for
    
    mean = static_cast<float>(sum) / size;  // mean = float-cast of sum, divided by the size of array
    
    return mean;    // return float variable, mean
    
}   // end function, Mean

// calculates median of data in array
// calls function, Sort
float Median (int* array, size_t size)
{
    float median = 0.0;     // initialize float variable, median, to 0.0
    float middle = 0.0;     // initialize float variable, middle, to 0.0
    Sort(array, size-1);    // function call, Sort
    
    if(size % 2 == 0)   // if array size is even...
    {
        middle = array[(size / 2) - 1] + array[(size / 2)]; // middle of array = [(n / 2) - 1] and [n / 2]
        median = middle / 2;                                // median = middle of array / 2
    }// end if
    else               // if array size is odd...
    {
        middle = array[(size - 1) / 2];                     // middle of array = [(n-1) / 2]
        median = middle;                                    // median = middle of array
    }// end else
    
    return median;  // return float variable, median
    
}   // end function, Median


// interchanges values of x and y
void Swap (int& x, int& y)
{
    int holdx = x;  // hold value of x
    x = y;          // give y value to x
    y = holdx;      // give held-x value to y
    
}   // end function, Swap


// sorts the data in array
// calls function, Swap
void Sort (int* array, size_t size)
{
    size_t k;   // initialize size_t variable, k
    
    for(size_t i = 0; i <= size; ++i)           // go through each element of the array, one by one
    {
        k = i;                                  // k = current i
        
        for(size_t j = i + 1; j <= size; ++j)   // go through each element of the array, one+1 by one+1
        {
            if(array[j] < array[k])             // if array[j] is less than array[k]...
            {
                k = j;                          // k = current j
            }   // end if
        }   // end for
        Swap(array[i], array[k]);               // function call, Swap: swap elements at positions array[i] and array[k]
    }   // end for
    
}   // end function, Sort
