/*
 Author : Theron Fereday
 Date : 12/1/2018
 Desc : networkStudent.cpp defines the networkStudent interface of the
        Student class.
 */
#include <cstring>
#include <iostream>
#include "networkStudent.h"
#include "roster.h"

using namespace std;

// constructor
NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, int age, int *numberOfDays, string degreeType)
: Student (studentId, firstName, lastName, emailAddress, age, numberOfDays, degreeType)
{
    this->setDegreeType(degreeType);
}


NetworkStudent::~NetworkStudent() {}

string NetworkStudent::getDegreeProgram()
{
    return this->degreeType;
}

void NetworkStudent::print()
{
    std::cout   << this->getStudentId() << "    "
    << "First Name: " << this->getFirstName() << "    "
    << "Last Name: " << this->getLastName() << "    "
    << "Age: " << this->getAge() << "    "
    << "daysInCourse: " << this->getNumberOfDays() << "    "
    << "Degree Program: " << this->getDegreeProgram() << std::endl;
}
