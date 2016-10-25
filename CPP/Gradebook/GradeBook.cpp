// Fig. 3.12: GradeBook.cpp [based on]
// Gradebook member-function definitions. This file contains
// implementations of the member functions prototyped in Gradebook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class Gradebook
using namespace std;

// *** constructor initializes courseName and courseInstructor with string supplied arguments ***
GradeBook::GradeBook( string course, string instructor )
    : courseName( course ) // member initializer to initialize courseName
    , courseInstructor( instructor ) // *** member initializer to intialize courseInstructor ***
{
    // empty body
} // end Gradebook constuctor

// function to set the course name
void GradeBook::setCourseName( string course )
{
    courseName = course; // store the course name in the object
} // end function setCourseName

// *** function to set the course instructor ***
void GradeBook::setCourseInstructor( string instructor )
{
    courseInstructor = instructor; // *** store the course instructor in the object ***
} // *** end function setCourseInstructor ***

// function to get the course name
string GradeBook::getCourseName() const
{
    return courseName; // return object's course name
} // end function getCourseName

// *** function to get the course name ***
string GradeBook::getCourseInstructor() const
{
    return courseInstructor; // *** return object's course instructor ***
} // *** end function getCourseInstructor ***

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
    // *** call getCourseName and getCourseInstructor to get the course name and course instructor ***
    cout << "Welcome to the grade book for \n" << getCourseName() << "!"
    << "\n\nThis course is presented by: \n" << getCourseInstructor() << endl << endl;
} // end function displayMessage
