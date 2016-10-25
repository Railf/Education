//
//  main.c
//  Lab 5: Temperatures - Part A + Part B
//
//  Created by Ralph McCracken, III on 7/6/15.
//  Copyright (c) 2015 Ralph McCracken, III. All rights reserved.
//

#include <stdio.h>

//  Global, constant macro strings to describe the category of a given element of array temp.
#define COLD "Cold day"
#define OK "Pleasant day"
#define HOT "Hot day"

// Global-counter variables for the categories of temperature.
int cDays = 0;  //  COLD
int pDays = 0;  //  OK  (Pleasent)
int hDays = 0;  //  HOT


//  Function prototype for tempAnalysis.
char* tempAnalysis(int temp);

//  Begin operations at function, main.
int main(void) {
    
    //  Initialize array temp with the given collection of temperatures.
    int temp[26] = { 55, 62, 68, 74, 59, 45, 41, 58, 60, 67, 65, 78, 82, 88, 91, 92, 90, 93, 87, 80, 78, 79, 72, 68, 61, 59 };
    
    //  Initialize temperature total to zero, for the average operation at end of run.
    int tempTotal = 0;
    
    //  Initialize variable that serves as the element of icrementation to zero, to check each value in the array, temp.
    int check = 0;
    
    puts("Temperature Analysis\n");
    
    /*  While check is less than and equal to array temp's maximum memory allocation ( 0 to 25 == 26 memory locations):
        Print the temperature and its category, at the temperature to the total temperature, and add one to check.      */
    while (check <= 25){
        printf("%d: %12s\n", temp[check], tempAnalysis(temp[check]));
        tempTotal += temp[check];
        check++;
    }
    
    //  Output data for the number of each type of day.
    puts("-----------------");
    printf("    Cold days: %2d\n", cDays);
    printf("Pleasant days: %2d\n", pDays);
    printf("     Hot days: %2d\n", hDays);
    
    
    //  Output average temperature (total sum of temperatures divided by total number of temperatures).
    puts("--------------------------");
    printf("Average temperature: %.2f", (double)tempTotal/check);
    
}//  End function, main.

//  Function, tempAnalysis, takes the temperature at the current location of array temp and categorizes said temperature for the given groups of heat index.
char* tempAnalysis(int temp){
    
    //  If the temperature is less than 60, add one to COLD counter variable, cDays, and return category COLD.
    if(temp < 60){
        cDays++;
        return COLD;

    //  If the temperature is greater than or equal to 60, while also less than or equal to 84, add one to OK counter variable, pDays, and return category OK.
    }else if (temp >= 60  && temp <= 84){
        pDays++;
        return OK;
        
    //  If the temperature is greater than or equal to 85, add one to HOT counter variable, hDays, and return category HOT.
    }else{
        hDays++;
        return HOT;
    }

    // Return to function call (never reaches this point, but a return value is required from every scope of a function block).
    return 0;
    
}//  End function, tempAnalysis.
