//
//  main.cpp
//  Lab02_GradeBook
//
//  Created by Ralph McCracken, III on 9/20/15.
//  Copyright © 2015 Ralph McCracken, III. All rights reserved.
//

#include <iostream>
#include "GradeBook.h" //  include definition of class Gradebook
using namespace std;

//  function main begins program execution
int main()
{
    //  create GrabeBook object
    GradeBook gradeBook1( "COP2224 Introduction to Programming in C++", "Heidi Gentry Kolen" );
    
    //  display the welcome message from the gradeBook1 object
    gradeBook1.displayMessage();
} //  end main
