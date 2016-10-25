//
//  main.c
//  Lab 06: ATM Withdraw
//
//  Created by Ralph McCracken, III on 7/15/15.
//  Copyright (c) 2015 Ralph McCracken, III. All rights reserved.
//

#include <stdio.h>

//  Function prototype for function Withdraw.
void withdraw(long int amount);

//  Begin operations...
int main(void) {
    long int amount;
    
    //  Prompt user for an amount to withdraw.
    puts("Please enter an integer amount to withdraw (multiple of 10):");
    scanf("%ld", &amount);   //  Store amount as integer due to the "multiple of 10" requirement.
    
    //  If the amount entered by the user is not a multiple of ten (10) then...
    while(amount % 10 != 0){
        //  Prompt user for an amount to withdraw, and emphasize the error.
        puts("--------------------------------------------------------------");
        puts("The amount entered is not a multiple of 10.");
        puts("Please enter an integer amount to withdraw (multiple of 10):");
        scanf("%ld", &amount);   //  Store amount as integer--due to the "multiple of 10" requirement--in amount variable.
    }//  end while(amount % 10 != 0)
    
    //  Function call to withdraw.
    withdraw(amount);
}// end function, main

//  Take in the value of variable, amount, and determines the least amount of 50's, 20's, and 10's to dispense.
void withdraw(long int amount){
    //  Show user of the about they entered to withdraw, in the monetary format.
    puts("--------------------------------------------------------------");
    printf("The amount withdrawn is: $%ld.00\n", amount);
    puts("--------------------------------------------------------------");
    
    long int remainder = 0; //  Initialize the remaining amount to zero (0).
    long int withdrawn[3];  //  Array to store the number of each type of bill.
    withdrawn[0] = 0;       //  Count: Fifties
    withdrawn[1] = 0;       //  Count: Twenties
    withdrawn[2] = 0;       //  Count: Tens
    
    //  The Bread and Butter: While the remaining amount is not zero..
    while(amount != 0){                     //  While the amount is greater than zero (after decrements by this statement)...
        if(amount / 50 >= 1){               //  If the amount is divisible by 50...
            remainder = amount % 50;        //  Set variable, remainder, equal to the remainder of: amount / 50.
            withdrawn[0] = amount / 50;     //  Set array mememory location 0, "Count: Fifties," equal to: amount / 50.
            amount = remainder;             //  Set the amount equal to the amount remaining, variable remainder.
            
        }else if(amount / 20 >= 1){         //  If the amount is divisible by 50...
            remainder = amount % 20;        //  Set variable, remainder, equal to the remainder of: amount / 20.
            withdrawn[1] = amount / 20;     //  Set array mememory location 0, "Count: Twenties," equal to: amount / 20.
            amount = remainder;             //  Set the amount equal to the amount remaining, variable remainder.
            
        }else{                              //  If the amount is divisible by 50...
            remainder = amount % 10;        //  Set variable, remainder, equal to the remainder of: amount / 10.
            withdrawn[2] = amount / 10;     //  Set array mememory location 0, "Count: Tens," equal to: amount / 10.
            amount = remainder;             //  Set the amount equal to the amount remaining, variable remainder.
            
        }
    }// end while(remainder != 0)
    
    //  Output data
    printf("Bills withdrawn: %7ld\n", withdrawn[0] + withdrawn[1] + withdrawn[2]);
    puts("------------------------");
    printf("Fifties  (50):   %7ld\n", withdrawn[0]);
    printf("Twenties (20):   %7ld\n", withdrawn[1]);
    printf("Tens     (10):   %7ld", withdrawn[2]);
}//  end function, withdraw
