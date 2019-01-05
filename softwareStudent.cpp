
/*
 Author : Theron Fereday
 Date : 12/1/2018
 Desc : SoftwareStudent.cpp defines the SoftwareStudent interface of the
 Student class.
 */
#include <cstring>
#include <iostream>
#include "softwareStudent.h"
#include "roster.h"

// constructor
SoftwareStudent::SoftwareStudent (std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int *numberOfDays, Degree degreeType)
: Student (studentId, firstName, lastName, emailAddress, age, numberOfDays, degreeType)
{
    this->setStudentId(studentId);
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->setEmailAddress(emailAddress);
    this->setAge(age);
    this->numberOfDays[0] = numberOfDays[0];
    this->numberOfDays[1] = numberOfDays[1];
    this->numberOfDays[2] = numberOfDays[2];
    this->degreeType = SOFTWARE;
}

// destructor
SoftwareStudent::~SoftwareStudent() { }

// getters
std::string SoftwareStudent::getDegreeProgram()
{
    return "SOFTWARE";
}

void SoftwareStudent::print()
{
    std::cout << this->getStudentId() << "    "
    << "First Name: " << this->getFirstName() << "    "
    << "Last Name: " << this->getLastName() << "    "
    << "Age: " << this->getAge() << "    "
    
    << "daysInCourse: { " << this->numberOfDays[0] << ", " << this->numberOfDays[1] << ", " << this->numberOfDays[2] << " }"
    
    << "    " << "Degree Program: " << this->getDegreeProgram() << std::endl;
}
