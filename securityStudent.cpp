
/*
 Author : Theron Fereday
 Date : 12/1/2018
 Desc : SecurityStudent.cpp defines the SecurityStudent interface of the
 Student class.
 */
#include <cstring>
#include <iostream>
#include "securityStudent.h"
#include "roster.h"

// constructor
SecurityStudent::SecurityStudent(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int *numberOfDays, std::string degreeType)
: Student (studentId, firstName, lastName, emailAddress, age, numberOfDays, degreeType)
{
    this->setDegreeType(degreeType);
}

// destructor
SecurityStudent::~SecurityStudent() { }

// getters
std::string SecurityStudent::getDegreeProgram()
{
    return this->degreeType;
}

void SecurityStudent::print()
{
    std::cout   << this->getStudentId() << "    "
    << "First Name: " << this->getFirstName() << "    "
    << "Last Name: " << this->getLastName() << "    "
    << "Age: " << this->getAge() << "    "
    << "daysInCourse: " << this->getNumberOfDays() << "    "
    << "Degree Program: " << this->getDegreeProgram() << std::endl;
}
