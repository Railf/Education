//
//  main.c
//  Fahrenheit_Converter
//
//  Created by Ralph McCracken, III on 6/10/15.
//  Copyright (c) 2015 Ralph McCracken, III. All rights reserved.
//

#include <stdio.h>

int main(void) {
    float temp_F;   //Initialization of float variable temp_F (Fahrenheit temperature).
    float temp_C;   //Initialization of float variable temp_C (Celsius temperature).
    
    puts("Please input your temperature in degrees Fahrenheit: ");  // Prompt.
    scanf("%f" , &temp_F);                                          // Receive input from user in the form of type float, and put it at the temp_F pointer.
    
    temp_C = (5.0 / 9.0) * (temp_F - 32.0);                         // Compute the temperature in Celsius, based on the value of the input Fahrenheit temperature.
    
    puts("----------------------------------------------------");   // Visual component: Section break.
    printf("The temperature in degrees Celsius is: %f", temp_C);    // Display result to the user after computation.
}   //End function main.
