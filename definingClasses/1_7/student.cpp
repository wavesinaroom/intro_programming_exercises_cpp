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

class Student
{

static int studentNumber; 

public:
    std::string* fullName;
    std::string* course;
    std::string* subject;
    std::string* university;
    std::string* email;
    //Constructor
    Student(std::string *fullName, std::string* course, std::string* subject, std::string* university, std::string* email); 
    Student(std::string *fullName, std::string* course, std::string* subject, std::string* university); 
    Student(std::string *fullName, std::string* course, std::string* subject);
    Student(std::string *fullName, std::string* course);
    Student(std::string *fullName);
    Student();
    //Destructor
    ~Student();

    void showStudentInfo(); 

};

Student::Student(std::string *fullName, std::string* course, std::string* subject, std::string* university, std::string* email)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = subject;
    this->university = university;
    this->email = email;
}



Student::Student(std::string *fullName, std::string* course, std::string* subject, std::string* university)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = subject;
    this->university = university;
    this->email = NULL;
}

Student::Student(std::string *fullName, std::string* course, std::string* subject)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = subject;
    this->university = NULL;
    this->email = NULL;
}

Student::Student(std::string *fullName, std::string *course)
{
    this->fullName = fullName;
    this->course = course;
    this->subject = NULL;
    this->university = NULL;
    this->email = NULL;
}



Student::Student(std::string *fullName)
{
    this->fullName = fullName;
    this->course = NULL;
    this->subject = NULL;
    this->university = NULL;
    this->email = NULL;
}


Student::~Student()
{
}

int main(int argc, char const *argv[])
{

    Student student = Student();
    std::cout<<student.fullName<<'\n'; 

    return 0;
}
