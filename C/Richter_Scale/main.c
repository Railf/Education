//
//  main.c
//  Lab 04: Richter Scale
//
//  Created by Ralph McCracken, III on 7/1/15.
//  Copyright (c) 2015 Ralph McCracken, III. All rights reserved.
//
//======================================================================================================================
//  QUESTION: Could you handle this problem with a switch statement? If so, use a swtich statement; if not, explain why.
/*  Yes.    A switch statement can solve this problem,
            but the method of doing so is unconventional.
 
    First,  you must redirect the input value of the user to a flag value (using if statements)
            because a switch statement handles cases of constant value not comparison.
                Example: "case 1" is acceptable, while "case x >= 1" is not.
 
    Then,   you must use the flag value to coinside with the repective Richter scale number characterization.
 *///===================================================================================================================

#include <stdio.h>

//This function converts the users entered Richter scale number to a flag value that can be used in a switch statement.
double richterScale(double n){
    unsigned int characterization = 0;
    /*  CHARACTERIZATION TABLE  ======================================================
        0   n < 5.0:            Little or no damage
        1   5.0 <= n < 5.5:     Some damage
        2   5.5 <= n < 6.5:     Serious damage:     Walls may crack or fall.
        3   6.5 <= n < 7.5:     Disaster:           Houses and buildings may collapse.
        4   Higher:             Catastrophe:        Most buildings destroyed.
     *///=============================================================================
    
    if (n < 5.0){                   // 0   n < 5.0:            Little or no damage
        characterization = 0;
        
    }else if (n >= 5.0 && n < 5.5){ // 1   5.0 <= n < 5.5:     Some damage
        characterization = 1;
        
    }else if (n >= 5.5 && n < 6.5){ // 2   5.5 <= n < 6.5:     Serious damage:     Walls may crack or fall.
        characterization = 2;
        
    }else if (n >= 6.5 && n < 7.5){ // 3   6.5 <= n < 7.5:     Disaster:           Houses and buildings may collapse.
        characterization = 3;
        
    }else                           // 4   Higher:             Catastrophe:        Most buildings destroyed.
        characterization = 4;
        
    return characterization;        // Return characterization to function main.
}// End function richterScale   ========================================================================================

int main(void) {
    double rScale = 0.0;                // Initialize Richter scale number to 0.0;
    unsigned int characterization = 0;  // Initialize flag value to 0.
    
    puts("Enter the Richter scale number of the earthquake:");  //Prompt user for Richter sclae number.
    scanf("%lf", &rScale);
    characterization = richterScale(rScale);                    //Envoke function richterScale, and store return value.
    
    
    switch (characterization){  //switch statement
        case 0:     // 0   n < 5.0:            Little or no damage
            puts("-------------------------------------------------");
            printf("Richter Scale Number: %.1lf\n", rScale);
            puts("Earthquake Characterization:      Little or no damage");
            break;
            
        case 1:     // 1   5.0 <= n < 5.5:     Some damage
            puts("-------------------------------------------------");
            printf("Richter Scale Number: %.1lf\n", rScale);
            puts("Earthquake Characterization:      Some damage");
            break;
            
        case 2:     // 2   5.5 <= n < 6.5:     Serious damage:     Walls may crack or fall.
            puts("-------------------------------------------------");
            printf("Richter Scale Number: %.1lf\n", rScale);
            puts("Earthquake Characterization:      Serious damage:     Walls may crack or fall.");
            break;
            
        case 3:     // 3   6.5 <= n < 7.5:     Disaster:           Houses and buildings may collapse.
            puts("-------------------------------------------------");
            printf("Richter Scale Number: %.1lf\n", rScale);
            puts("Earthquake Characterization:      Disaster:           Houses and buildings may collapse.");
            break;
            
        default:    // 4   Higher:             Catastrophe:        Most buildings destroyed.
            puts("-------------------------------------------------");
            printf("Richter Scale Number: %.1lf\n", rScale);
            puts("Earthquake Characterization:      Catastrophe:        Most buildings destroyed.");
            break;
    }
}
