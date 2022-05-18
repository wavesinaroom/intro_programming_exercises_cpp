/* 1. Define a class Student, which contains the following information about 
   students: full name, course, subject, university, e-mail and phone number.

   2. Declare several constructors for the class Student, which have different 
   lists of parameters (for complete information about a student or part of it).
   Data, which has no initial value to be initialized with null. 
   Use nullable types for all non-mandatory data.

   3. Add a static field for the class Student, which holds the number of created
   objects of this class.

   4. Add a method in the class Student, which displays complete information about
   the student.

   5. Modify the current source code of Student class so as to encapsulate 
   the data in the class using properties.
*/

#include <iostream>
#include <optional>

class student
{

static int studentNumber; 

private:
    std::optional<std::string> fullName;
    std::optional<std::string> course;
    std::optional<std::string> subject;
    std::optional<std::string> university;
    std::optional<std::string> email;
public:
    //Constructor
    student(std::string fullName, std::string course, std::string subject, std::string university, std::string email); 
    student(std::string fullName, std::string course, std::string subject, std::string university); 
    student(std::string fullName, std::string course, std::string subject);
    student(std::string fullName, std::string course);
    student(std::string fullName);
    //Destructor
    ~student();
};

student::student(std::string fullName, std::string course, std::string subject, std::string university, std::string email)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = subject;
    this->university = university;
    this->email = email;
}
student::student(std::string fullName, std::string course, std::string subject, std::string university)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = subject;
    this->university = university;
}
student::student(std::string fullName, std::string course, std::string subject)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = subject;
}
student::student(std::string fullName, std::string course)
{
    this->fullName = fullName;
    this->course = course;
}
student::student(std::string fullName)
{
    this->fullName = fullName;
}

student::~student()
{
}


