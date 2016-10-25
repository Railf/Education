// Fig. 3.11: GradeBook.h [based on]
// GradeBook class definition. This file presents Gradebook's public
// interface without reveiling the implementations of Gradebook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class

// Gradebook class definition
class GradeBook
{
public:
    explicit GradeBook( std::string, std::string ); // *** constructor initialize courseName and courseInstructor ***
    void setCourseName( std::string ); // sets the course name
    void setCourseInstructor( std::string ); // *** sets the course instructor ***
    std::string getCourseName() const; // gets the course name
    std::string getCourseInstructor() const; // *** gets the course instructor ***
    void displayMessage() const; //displays a welcome message
private:
    std::string courseName; // course name for this GradeBook
    std::string courseInstructor; // *** course instructor for this GradeBook ***
};  // end class Gradebook
