#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <cstring>
#include "Student.h"

class SecurityStudent : public Student
{
private:
    Degree degreeType;
    
public:
    SecurityStudent();
    SecurityStudent(std::string studentId, std::string firstName, std::string lastName,
                   std::string emailAddress, int age, int *numberOfDays, Degree degreeType);
    ~SecurityStudent();
    
    Degree getDegreeProgram();
    void print();
    
};

#endif
