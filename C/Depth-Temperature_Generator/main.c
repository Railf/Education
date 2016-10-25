//
//  main.c
//  Lab03: Depth-Tempurature Generator.
//
//  Created by Ralph McCracken, III on 6/17/15.
//  Copyright (c) 2015 Ralph McCracken, III. All rights reserved.
//

//Include standard input/output library.
#include <stdio.h>

//Celsius function with parameter depth for the celsius calucation.
//Celsius = (10 * depth in kilometers) + 20
float celsius_at_depth(float depth){
    
    //Initialization of variable celsius, float.
    float celsius = 0.00;
    
    //Calculation.
    celsius = (10.00 * depth) + 20.00;
    
    //Return value of calculated temperature to function call, main.
    return celsius;
    
}//End function celsius_at_depth=====================================

//Fahrenheit function with parameter depth for the celsius calucation.
//Fahrenheit = (1.8 * temperature in celsius) + 20
float fahrenheit(float celsius){
    
    //Initialization of variable fahrenheit, float.
    float fahrenheit = 0.00;
    
    //Calculation.
    fahrenheit = (1.80 * celsius) + 32.00;
    
    //Return value of calculated temperature to function call, main.
    return fahrenheit;
    
}//End function fahrenheit===========================================

int main(void) {
    
    //Initialization of variables: depth, celsius, and fahrenheit.
    float depth = 0.00;
    
    //Prompt user for depth.
    puts("Enter a depth in kilometers (km): ");
    scanf("%f", &depth);
    
    //Separation segment (for organization, but primarily for looks).
    puts("---------------------------------");
    
    
    //Output calculations.
    
        //Output celsius, when given the depth, via function call.
        printf("Degrees Celsius: %.2f\n", celsius_at_depth(depth));
    
        //Output fahrenheit, when given the degrees celsius, via nested function call.
        printf("Degress Fahrenheit: %.2f\n", fahrenheit(celsius_at_depth(depth)));
    
}//end function main=================================================
