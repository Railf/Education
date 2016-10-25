//
//  main.cpp
//  Lab03_GasMileage
//
//  Created by Ralph McCracken, III on 10/3/15.
//  Copyright © 2015 Ralph McCracken, III. All rights reserved.
//
//  Gas Mileage

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    //  Variables for the miles driven and gallons used, used for the calculations.
    double mileage = 0.0;   //  User-input, also flag variable.
    double gallons = 0.0;   //  User-input.
    
    double mpg_trip = 0.0;  //  = mileage / gallons
    double mpg_total = 0.0; //  Sum of all mpg_trip's.
    
    int trips = 1;          //  Count: the number of trips--initialize at 1.

    //  Initial prompt to user.
    cout << "Enter miles driven (-1 to quit): ";    //  Prompt for the mileage, and present exit flag.
    cin >> mileage;                                 //  Store user-input mileage into variable, mileage.
    
    if(mileage == -1)                               //  If flag value (-1) is entered,
        return 0;                                   //  terminate program.
    
    cout << "Enter gallons used: ";                 //  Prompt for the gallons used.
    cin >> gallons;                                 //  Store user-input gallons used into variable, gallons.
    
    mpg_trip = mileage / gallons;                   //  Calculation mpg_trip by dividing the mileage by gallons used.
    mpg_total += mpg_trip;                          //  Add current trip's mpg to the total's mpg.
    cout << "MPG this trip: " << mpg_trip;          //  Prompt user of the mpg obtained for this trip, mpg_trip.
    
    cout << "\nTotal MPG: " << mpg_total / trips << endl << endl;   //  Average of all the trip's mpg.
    //  End initial prompt to user.
    
    //  While statement to loop the trip-entering process, until flag value (-1) is entered as variable, mileage.
    while (mileage != -1){
        
        //  Loop prompt to user.
        ++trips;                                        //  Add 1 to the trip counter.
        cout << "Enter miles driven (-1 to quit): ";    //  Prompt for the mileage, and present exit flag.
        cin >> mileage;                                 //  Store user-input mileage into variable, mileage.
        
        if(mileage == -1)                               //  If flag value (-1) is entered,
            return 0;                                   //  terminate program.
        
        cout << "Enter gallons used: ";                 //  Prompt for the gallons used.
        cin >> gallons;                                 //  Store user-input gallons used into variable, gallons.
        
        mpg_trip = mileage / gallons;                   //  Calculation mpg_trip by dividing the mileage by gallons used.
        mpg_total += mpg_trip;                          //  Add current trip's mpg to the total's mpg.
        cout << "MPG this trip: " << mpg_trip;          //  Prompt user of the mpg obtained for this trip, mpg_trip.
        
        cout << "\nTotal MPG: " << mpg_total / trips << endl << endl;   //  Average of all the trip's mpg.
        //  End loop prompt to user.
    }   //  End loop, while
}   //  End function, main
