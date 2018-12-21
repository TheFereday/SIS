#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <cstring>
#include "Student.h"

class SecurityStudent : public Student
{
private:
    std::string degreeType;
    
public:
    SecurityStudent();
    SecurityStudent(std::string studentId, std::string firstName, std::string lastName,
                   std::string emailAddress, int age, int *numberOfDays, std::string degreeType);
    ~SecurityStudent();
    
    std::string getDegreeProgram();
    void print();
    
};

#endif
