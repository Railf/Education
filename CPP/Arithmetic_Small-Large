//
//  main.cpp
//  Lab01: Arithmetic, Smallest and Largest
//
//  Created by Ralph McCracken, III on 9/6/15.
//  Copyright (c) 2015 Ralph McCracken, III. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    //User input variables
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;
    
    //Mathmatic outcome variables
    int     sum     = 0;
    double  average = 0;
    int     product = 0;
    
    //Size comparison variables
    int smallest    = 0;
    int largest     = 0;
    
    cout << "Input three different integers: "; //Promp user for input (integers).
    cin >> number1;                             //Integer 1
    cin >> number2;                             //Integer 2
    cin >> number3;                             //Integer 3
    
    //Computations: Arithmetic
    sum     = number1 + number2 + number3;      //All three integers added together.
    average = (double)sum / 3;                      //Sum of integers divided by number of integers (3).
    product = number1 * number2 * number3;  //All three integers multiplied together.
    
    //Computations: Largest
    if(number1 > number2 && number1 > number3)
        largest = number1;
    else if(number2 > number1 && number2 > number3)
        largest = number2;
    else
        largest = number3;
    
    //Computations: Smallest
    if(number1 < number2 && number1 < number3)
        smallest = number1;
    else if(number2 < number1 && number2 < number3)
        smallest = number2;
    else
        smallest = number3;
    
    //Output to user
    cout << "Sum is "       << sum      << endl;    //sum
    cout << "Average is "   << average  << endl;    //average
    cout << "Product is "   << product  << endl;    //product
    cout << "Smallest is "  << smallest << endl;    //smallest
    cout << "Largest is "   << largest  << endl;    //largest
}
