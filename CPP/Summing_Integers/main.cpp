//
//  main.cpp
//  Lab05_SummingIntegers: Summing Integers
//
//  Created by Ralph McCracken, III on 10/22/15.
//  Copyright © 2015 Ralph McCracken, III. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    int sum_num = 0;
    int total = 0;
    int integer = 0;
    
    cout << "Enter the number of integers you would like to add, followed by those integers:" << endl;
    cin >> sum_num;
    for (int flag = 1; flag <= sum_num; flag++ ){
        cin >> integer;
        total += integer;
    }
    
    cout << endl << "Total: " << total << endl;
}
