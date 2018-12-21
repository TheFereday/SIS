#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <string>
#include "Student.h"

class NetworkStudent : public Student
{
    private:
    std::string degreeType;
    
    public:
        // Default constructor
        NetworkStudent();
    
        // Constructor receiving all class variables
        NetworkStudent(std::string studentId, std::string firstName, std::string lastName,
                       std::string emailAddress, int age, int *numberOfDays, std::string degreeType);
    
        // Destructor
        ~NetworkStudent();
    
        std::string getDegreeProgram();
        void print();

};

#endif
