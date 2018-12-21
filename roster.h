
#ifndef roster_h
#define roster_h

#include<cstring>
#include"Student.h"

class Roster {
private:
    Student* classRosterArray[5];
    int arrayPosition;
//    std::string studentId;
//    std::string firstName;
//    std::string lastName;
//    std::string emailAddress;
//    int age;
//    int daysInCourse[3];
//    std::string degreeType;
    
public:
    //Constructor
    Roster();
    
    //Destructor
    ~Roster();
    
    void add(std::string studentId,
             std::string firstName,
             std::string lastName,
             std::string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             std::string degreeType);
    void remove(std::string studentId);
    void printAll();
    void printDaysInCourse(std::string studentId);
    void printInvalidEmails();
    void printDegreeProgram(std::string degreeProgram);
};

#endif
