//
//  main.cpp
//  Lab05_Parking
//
//  Created by Ralph McCracken, III on 11/12/15.
//  Copyright © 2015 Ralph McCracken, III. All rights reserved.
//

#include <iostream> //Include in-out standard library.      //Sending and recieving data from the user.
#include <iomanip>  //Include in-out manipulation library.  //Manipulating data.
#include <cmath>    //Include math library.                 //Math functions.
using namespace std;

double calculateCharges(double time){       //Function calculateCharges: START
    double charge = 2.00;                       //variable definition: charge, type double, initiated to the minimum charge of $2.00.
    double excess = 0.00;                       //variable definition: excess, type double, used to determine hours parked in excess to the 3 alloted by $2.00.
    
    if (time > 3.00){                           //if-statement: if the time parked is in excess to three hours then:
        excess = ceil(time - 3.00);                 //calculation: excess is equal to the excess hours of the time parked minus the alloted three hours
        charge += excess * 0.50;                    //calculation: charge is $2.00 + ($0.50 times excess hours)
        
        if (charge > 10.00)                         //nested if-statement: if the charge is larger than $10.00:
            charge = 10.00;                             //calculation: charge is reduced to $10.00 (the maximum).
        
        return charge;                              //return statement: return the newly calculated charge variable, type double.
    }                                           //if-statement: END
    
    return charge;                              //return statement: return initialized (2.00) charge variable, type double.
}                                           //Function calculateCharges: END

int main() {                                //Function main: START
    double car1 = 0.00;                         //variable definition: car1, type double, holds the user input for time car 1 was parked.
    double car2 = 0.00;                         //variable definition: car2, type double, holds the user input for time car 2 was parked.
    double car3 = 0.00;                         //variable definition: car3, type double, holds the user input for time car 3 was parked.
    
                                                //promt: ask for the time car 1 was parked.
    cout << "Enter the amount of time car 1 spent parked: ";
    cin >> car1;                                //variable assignment: user input for the time car 1 was parked.
    
                                                //error checking: if input time car 1 is parked is greater than 24 hours or less than 0 hours.
    while (car1 > 24.00){
        cout << "ERROR: A vehicle can only be parked for 24 hours." << endl << endl;
        cout << "Enter the amount of time car 1 spent parked: ";
        cin >> car1;
    }while (car1 < 0.00){
        cout << "ERROR: Please enter a positive amount of time." << endl << endl;
        cout << "Enter the amount of time car 1 spent parked: ";
        cin >> car1;
    }
    
                                                //promt: ask for the time car 2 was parked.
    cout << "Enter the amount of time car 2 spent parked: ";
    cin >> car2;                                //variable assignment: user input for the time car 2 was parked.
    
                                                //error checking: if input time car 2 is parked is greater than 24 hours or less than 0 hours.
    while (car2 > 24.00){
        cout << "ERROR: A vehicle can only be parked for 24 hours." << endl << endl;
        cout << "Enter the amount of time car 2 spent parked: ";
        cin >> car2;
    }while (car2 < 0.00){
        cout << "ERROR: Please enter a positive amount of time." << endl << endl;
        cout << "Enter the amount of time car 2 spent parked: ";
        cin >> car2;
    }
    
                                                //promt: ask for the time car 3 was parked.
    cout << "Enter the amount of time car 3 spent parked: ";
    cin >> car3;                                //variable assignment: user input for the time car 3 was parked.
    
                                                //error checking: if input time car 3 is parked is greater than 24 hours or less than 0 hours.
    while (car3 > 24.00){
        cout << "ERROR: A vehicle can only be parked for 24 hours." << endl << endl;
        cout << "Enter the amount of time car 3 spent parked: ";
        cin >> car3;
    }while (car3 < 0.00){
        cout << "ERROR: Please enter a positive amount of time." << endl << endl;
        cout << "Enter the amount of time car 3 spent parked: ";
        cin >> car3;
    }
                                                //output: data is output with formating required for the completion of the lab.
    cout << endl;
    cout << "Car"   << setw(10)                             << "Hours"  << setw(10)                             << "Charge"                 << endl;
    cout << "1  "   << setw(10) << setprecision(1) << fixed << car1     << setw(10) << setprecision(2) << fixed << calculateCharges(car1)   << endl;
    cout << "2  "   << setw(10) << setprecision(1) << fixed << car2     << setw(10) << setprecision(2) << fixed << calculateCharges(car2)   << endl;
    cout << "3  "   << setw(10) << setprecision(1) << fixed << car3     << setw(10) << setprecision(2) << fixed << calculateCharges(car3)   << endl;
}                                           //Function main: END
