#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <cstring>
#include "Student.h"

class SoftwareStudent : public Student
{
private:
    Degree degreeType;
    
public:
    SoftwareStudent();
    SoftwareStudent(std::string studentId, std::string firstName, std::string lastName,
                    std::string emailAddress, int age, int *numberOfDays, Degree degreeType);
    ~SoftwareStudent();
    
    std::string getDegreeProgram();
    void print();
    
};

#endif
