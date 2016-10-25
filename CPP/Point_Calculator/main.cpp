//  main.cpp
//  PointCalc - Point Calculator
//
//  Created by Ralph McCracken, III on 10/19/15.
//  Copyright © 2015 Ralph McCracken, III. All rights reserved.
//  Finished on 11/20/15 @ 12:25:12.


#include <iostream>         //C++ library that allows for user to input and output data to the screen.
#include <iomanip>          //C++ library that allows for the manipulation of input and output of data.
#include <cmath>            //C++ standard math library.
#include "pointCalc.cpp"    //Include self-made pointCalc.cpp.
using namespace std;        //Namespace std.

int main(int argc, const char * argv[]) {   //Function, type int [main]: START
    int x1_value = 0;   //Variable initilization: type int, x1_value [point 1, x]
    int y1_value = 0;   //Variable initilization: type int, y1_value [point 1, y]
    int x2_value = 0;   //Variable initilization: type int, x2_value [point 2, x]
    int y2_value = 0;   //Variable initilization: type int, y2_value [point 2, y]
    
    //Prompt user of the program and instructions.
    cout << "Point Calculator  |    Version 1.0.0    |  Ralph Wayne McCracken, III" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "   Enter two different points by their respecting x- and y-values."    << endl;
    cout << "---------------------------------------------------------------------" << endl << endl;
    
    //Prompt for point 1 [x1_value , y1_value].
    cout << "Point 1, x-value: ";   //Prompt for x1_value.
    cin >> x1_value;                //Obtain x1_value.
    cout << "       , y-value: ";   //Prompt for y1_value.
    cin >> y1_value;                //Obtain y1_value.
    cout << setw(25) << "( " << x1_value << " , " << y1_value << " )"       << endl << endl;    //Output point 1 [x1_value , y1_value].
    
    //Prompt for point 2 [x2_value , y2_value].
    cout << "Point 2, x-value: ";   //Prompt for x2_value.
    cin >> x2_value;                //Obtain x2_value.
    cout << "       , y-value: ";   //Prompt for y2_value.
    cin >> y2_value;                //Obtain y2_value.
    cout << setw(25) << "( " << x2_value << " , " << y2_value << " )"       << endl << endl;    //Output point 1 [x1_value , y1_value].
    
    //Output: Results [DISTANCE, MID-POINT, SLOPE; LINE] and program notes.
    cout << "=====================================================================" << endl
         << "   RESULTS   | NOTE: 1. Distance rounded to the nearest thousandth."   << endl
         << "             |       2. Larger fractions are not reduced."             << endl
         << "=====================================================================" << endl << endl;
    
    PointCalc points_1(x1_value , y1_value , x2_value , y2_value);  //Create object [points_1] from class [PointCalc].
    cout << fixed << setprecision(3);                               //Set precision of the distance to the nearest thousandth [0.000].
    cout    << "1. DISTANCE  |d = √[(x2 - x1)^2 + (y2 - y1)^2]   | " << points_1.distance()     << " units" << endl << endl //OUTPUT RESULTS    >   DISTANCE
            << "2. MID-POINT |x = (x2 - x1)/2  ; y = (y2 - y1)/2 | " << points_1.midpoint()     <<             endl << endl //                  >   MID-POINT
            << "3. SLOPE     |m = (y2 - y1)/(x2 - x1)            | " << points_1.slope()        <<             endl << endl //                  >   SLOPE
            << "4. LINE      |y = mx + b  ;  y - y1 = m(x - x1)  | " << points_1.line();                                    //                  >   LINE
}   //Function, type int [main]: END
