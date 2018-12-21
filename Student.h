//
//  Student.hpp
//  SIS
//
//  Created by Theron Fereday on 11/30/18.
//  Copyright © 2018 Theron Fereday. All rights reserved.
//

#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <stdio.h>
#include <cstring>

class Student
{
private:
    std::string studentId;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int numberOfDays[3];
    std::string degreeType;
    
public:
    // Constructors
    Student(std::string studentId,
            std::string firstName,
            std::string lastName,
            std::string emailAddress,
            int age,
            int* numberOfDays[3],
            std::string degreeType);
    
    //(studentId, firstName, lastName, emailAddress, age, numberOfDays, degreeType)
    
    Student(std::string studentId,
             std::string firstName,
             std::string lastName,
             std::string emailAddress,
             int age,
             int *numberOfDays,
             std::string degreeType);
    // Destructor
    ~Student();
    // accessor functions
    std::string getStudentId();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    int* getNumberOfDays();
    virtual std::string getDegreeProgram() = 0;
    
    // mutator functions
    void setStudentId(std::string Id);
    void setFirstName(std::string fname);
    void setLastName(std::string lname);
    void setEmailAddress(std::string emailAddr);
    void setAge(int newAge);
    void setNumberOfDays(int days);
    void setDegreeType(std::string degreeType);
    
    // other functions
    virtual void print();
};


#endif /* Student_hpp */
