//
//  Student.cpp
//  SIS
//
//  Created by Theron Fereday on 11/30/18.
//  Copyright © 2018 Theron Fereday. All rights reserved.
//

#include <cstring>
#include <iostream>
#include "Student.h"

//using namespace std;

// Constructors
Student::Student(std::string studentId,
                 std::string firstName,
                 std::string lastName,
                 std::string emailAddress,
                 int age,
                 int numberOfDays[3],
                 Degree degreeType)
{
    studentId = this->studentId;
    firstName = this->firstName;
    lastName = this->lastName;
    emailAddress = this->emailAddress;
    age = this->age;
    numberOfDays = this->numberOfDays;
};

//(studentId, firstName, lastName, emailAddress, age, numberOfDays, degreeType)

//Student::Student(std::string studentId,
//                 std::string firstName,
//                 std::string lastName,
//                 std::string emailAddress,
//                 int age,
//                 int* numberOfDays,
//                 std::string degreeType)
//{
////    studentId = this->studentId;
////    firstName = this->firstName;
////    lastName = this->lastName;
////    emailAddress = this->emailAddress;
////    age = this->age;
////    numberOfDays = this->numberOfDays;
//};

// Destructor
Student::~Student(){};

// accessor functions
std::string Student::getStudentId()
{
    return studentId;
}

std::string Student::getFirstName()
{
    return firstName;
}

std::string Student::getLastName()
{
    return lastName;
}

std::string Student::getEmailAddress()
{
    return emailAddress;
}

int Student::getAge()
{
    return age;
}

// getNumberOfDays returns average number of days for the courses
int* Student::getNumberOfDays()
{
    
    
    return numberOfDays;
}

// mutator functions
void Student::setStudentId(std::string Id)
{
    studentId = Id;
}

void Student::setFirstName(std::string fname)
{
    firstName = fname;
}

void Student::setLastName(std::string lname)
{
    lastName = lname;
}

void Student::setEmailAddress(std::string emailAddr)
{
    emailAddress = emailAddr;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

void Student::setNumberOfDays(int numberOfDays)
{
    numberOfDays = numberOfDays;
}

