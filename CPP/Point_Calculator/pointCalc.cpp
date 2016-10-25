//  Point Calculator: pointCalc.cpp
//  PointCalc member-function definitions.

#include <iostream>     //C++ library that allows for user to input and output data to the screen.
#include <cmath>        //C++ standard math library.
using namespace std;    //Namespace std.


class PointCalc{    //Class [PointCalc]: START
public:
    PointCalc(int x1_value, int y1_value, int x2_value, int y2_value)   //Take in arguements [x1_value, y1_value, x2_value, y2_value].
    : x1(x1_value) , y1(y1_value) , x2(x2_value) , y2(y2_value) {}      //Initialize class's private variables [x1, y1, x2, y2].
    
    double distance(){  //Function, type double [distance]: START
        
        /*  The purpose of this function is to take in two points as arguements from the class initialization
            and subsequently manipulate them to calculate the distance between the two point.
                FORMULA: d = √[(x2 - x1)^2 + (y2 - y1)^2]                                                       */
        
        double distance = 0;                                        //Variable Initilization: type double, distance
        distance = sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0)); //d = √[(x2 - x1)^2 + (y2 - y1)^2]
        return distance;                                            //Return: type double, distance
    }                                                               //Function, type double [distance]: END
    
    string midpoint(){  //Function, type string [midpoint]: START
        
        /*  The purpose of this function is to take in two points as arguements from the class initialization
            and subsequently manipulate them to calculate the mid-point between the two input points.
                FORMULA: x = (x2 - x1)/ 2 ; y = (y2 - y1)/2                         */
        
        string midpoint = "";   //Variable initialization: type string, midpoint
        int x_mid = 0;          //Variable initialization: type int, x_mid
        int y_mid = 0;          //Variable initialization: type int, y_mid
        string x_mid_str = "";  //Variable initialization: type string, x_mid_str
        string y_mid_str = "";  //Variable initialization: type string, y_mid_str
        
        if (m_den%2 == 0){                          //If 2 divides into the difference of x's [x2 - x1] evenly...
            x_mid = m_den/2;                        //Divide difference of x's [x2 - x1] by 2 [(x2-x1)/2], and store in variable [x_mid].
            x_mid_str = to_string(x_mid);           //Convert x_mid, type int, to string [x_mid_str].
        }else{                                      //If 2 divides into the difference of x's [x2 - x1] unevenly...
            x_mid = m_den;                          //Store difference of x's [x2 - x1] into variable [x_mid].
            x_mid_str = to_string(x_mid) + "/2";    //Convert x_mid, type int, to string [x_mid_str] and add "/2" to the string.
        }
        
        if (m_num%2 == 0){                          //If 2 divides into the difference of y's [y2 - y1] evenly...
            y_mid = m_num/2;                        //Divide difference of y's [y2 - y1] by 2 [(y2-y1)/2], and store in variable [y_mid].
            y_mid_str = to_string(y_mid);           //Convert y_mid, type int, to string [y_mid_str].
        }else{                                      //If 2 divides into the difference of y's [y2 - y1] unevenly...
            y_mid = m_num;                          //Store difference of y's [y2 - y1] into variable [y_mid].
            y_mid_str = to_string(y_mid) + "/2";    //Convert y_mid, type int, to string [y_mid_str] and add "/2" to the string.
        }
        
        midpoint = "( " + x_mid_str + " , " + y_mid_str + " )"; //Variable definition: type string, midpoint
        return midpoint;                                        //Return: type string, midpoint
    }                                                           //Function, type string [midpoint]: END
    
    string slope(){ //Function, type string [slope]: START
        
        /*  The purpose of this function is to take in two points as arguements from the class initialization
            and subsequently manipulate them to calculate the slope bewteen the two points.
                FORMULA: m = (y2 - y1)/(x2 - x1)                                                                */
        
        string slope = "";          //Variable initialization: type string, slope
        
        if (m_num%m_den == 0){                                              //If the difference of y's [y2 - y1] divides evenly into the difference of x's [x2 - x1]...
            slope = to_string(m);                                           //m = (y2 - y1)/(x2 - x1)
        }else{                                                              //If the difference of y's [y2 - y1] divides unevenly into the difference of x's [x2 - x1]...
            if (m_num < 0 && m_den < 0)                                     //If the difference of y's [y2 - y1] is negative and the difference of x's [x2 - x1] is negative...
                slope = to_string(-(m_num)) + "/" + to_string(-(m_den));    //Negative divided by a negative is a positive: change both signs to positive.
            else if (m_num > 0 && m_den > 0)                                //If the difference of y's [y2 - y1] is positive and the difference of x's [x2 - x1] is positive...
                slope = to_string(m_num) + "/" + to_string(m_den);          //Positive diveded by a positive is a positive: do not change either's sign.
            else if (m_num > 0 && m_den < 0)                                //If the difference of y's [y2 - y1] is positive and the difference of x's [x2 - x1] is negative...
                slope = to_string(-(m_num)) + "/" + to_string(-(m_den));    //Positive divided by a negative is a negative: bring the deominator's negative to the numerator [cleaner].
            else                                                            //If the difference of y's [y2 - y1] is negative and the difference of x's [x2 - x1] is positve...
                slope = to_string(m_num) + "/" + to_string(m_den);          //Negative divided by a positive is a negative: do not change either's sign.
        }
        
        return slope;   //Return: type string, slope
    }                   //Function: type string [slope]: END
    
    string line(){    //Function, type string [line]: START
        
        /*  The purpose of this function is to take in two points as arguements from the class initialization
            and subsequently manipulate them to calculate the equation of the line that passes through the two points.
                FORMULA: y = mx + b  ;  y - y1 = m(x - x1)                                                              */
        
        string line = "";                       //Variable initialization:  type string, line
        int b = y1 - m*x1;                      //Variable definition:      type int, b     [y - mx]                [y = mx + b;    solved for b]
        int b_num = (m_den*y1) - (m_num*x1);    //Variable definition:      type int, b_num [m_dem(y) - m_num(x)]   [Numerator;     creates common denominator fraction]
        int b_den = m_den;                      //Variable definition:      type int, b_den [m_den]                 [Denominator;   common denominator]
        
        if (b_num < 0 && b_den < 0){            //If the numerator [b_num] is negative and the denominator is negative...
            b_num = -(b_num); b_den = -(b_den); //Negative divided by a negative is a positive: change both signs to positive.
        }if (b_num > 0 && b_den < 0){           //If the numerator [b_num] is positive and the denominator is negative...
            b_num = -(b_num); b_den = -(b_den); //Positive divided by a negative is a negative: bring the deominator's negative to the numerator [cleaner].
        }
        
        
        if (m_num%m_den == 0){                                          //If the difference of y's [y2 - y1] divides evenly into the difference of x's [x2 - x1]...
            if (b > 0)                                                      //If b [y - mx] is positive...
                line = "y = " + slope() + "x + " + to_string(b) + "\n";     //y = mx + b
            else                                                            //If b [y - mx] is negative...
                line = "y = " + slope() + "x - " + to_string(b) + "\n";     //y = mx - b
        }else{                                                          //If the difference of y's [y2 - y1] divides unevenly into the difference of x's [x2 - x1]...
            if (b > 0)                                                      //If b [y - mx] is positive...
                line = "y = (" + slope() + ")x + (" + to_string(b_num) + "/" + to_string(b_den) + ")" + "\n";   //y = (m)x + (b_num/b_den)
            else                                                            //If b [y - mx] is negative...
                line = "y = (" + slope() + ")x - (" + to_string(-b_num) + "/" + to_string(b_den) + ")" + "\n";   //y = (m)x - (b_num/b_den)
        }
        
        return line;    //Return: type string, line
    }                   //Function: type string [line]: END
    
private:                    //Constructor variables [created upon class initialization through class heading arguements]
    int x1;                 //Variable definition: type int, x1     [x1_value]
    int y1;                 //Variable definition: type int, y1     [y1_value]
    int x2;                 //Variable definition: type int, x2     [x2_value]
    int y2;                 //Variable definition: type int, y2     [y2_value]
    int m_num = y2 - y1;    //Variable definition: type int, m_num  [y2 - y1]       [difference of y's]
    int m_den = x2 - x1;    //Variable definition: type int, m_den  [x2 - x1]       [difference of x's]
    int m = m_num/m_den;    //Variable definition: type int, m      [m_num/m_den]   [slope; m = (y2 - y1)/(x2 - x1)]
};                          //Class [PointCalc]: END
