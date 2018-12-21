#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <cstring>
#include "Student.h"

class SoftwareStudent : public Student
{
private:
    std::string degreeType;
    
public:
    SoftwareStudent();
    SoftwareStudent(std::string studentId, std::string firstName, std::string lastName,
                    std::string emailAddress, int age, int *numberOfDays, std::string degreeType);
    ~SoftwareStudent();
    
    std::string getDegreeProgram();
    void print();
    
};

#endif
