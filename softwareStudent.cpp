
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
SoftwareStudent::SoftwareStudent (std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int *numberOfDays, std::string degreeType)
: Student (studentId, firstName, lastName, emailAddress, age, numberOfDays, degreeType)
{
    this->setDegreeType(degreeType);
}

// destructor
SoftwareStudent::~SoftwareStudent() { }

// getters
std::string SoftwareStudent::getDegreeProgram()
{
    return this->degreeType;
}

void SoftwareStudent::print()
{
    std::cout   << this->getStudentId() << "    "
    << "First Name: " << this->getFirstName() << "    "
    << "Last Name: " << this->getLastName() << "    "
    << "Age: " << this->getAge() << "    "
    << "daysInCourse: " << this->getNumberOfDays() << "    "
    << "Degree Program: " << this->getDegreeProgram() << std::endl;
}
