
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <array>
#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"

using std::string;
using std::cout;
using std::endl;
using std::stoi;

//Global variables
const int NUMSTUDENTS = 5;

//Constructor
Roster::Roster()
{
    Student* classRosterArray[NUMSTUDENTS];
};

//Destructor
Roster::~Roster(){};

//   public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, <degree program>) that sets the instance variables from part D1 and updates the roster

void Roster::add(string studentId, string firstName, string lastName, string emailAddress,
            int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeType)
{
    // TODO: Generate new students of below types by creating array out of days and passing that array into the constructor.  Also, grab the firstname to name the object.
    
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    if(degreeType == "NETWORK")
    {
        classRosterArray[arrayPosition] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeType);
    }

    if(degreeType == "SECURITY")
    {
        classRosterArray[arrayPosition] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeType);
    }

    if(degreeType == "SOFTWARE")
    {
        classRosterArray[arrayPosition] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degreeType);
    }

    this->arrayPosition++;
}


// public void remove(string studentID) that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.

void Roster::remove(string studentId)
{
    int count = 0;
    
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
        //loop through array to find student
        if(classRosterArray[i]->getStudentId().compare(studentId) == 0)
        {
            while((i + count) < NUMSTUDENTS)
            {
                classRosterArray[i] = classRosterArray[i+1];
                count++;
            }
            // Does the last member of array need nulled?
        }
    }
    
    if(count == 0)
        cout << "Student with Id " << studentId << " not found." << endl;
    
    //classRosterArray.array::size()-1;
}

// public void printAll() that prints a complete tab-separated list of student data using accessor functions with the provided format: 1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all  the students in classRosterArray and call the print() function for each student.

void Roster::printAll()
{
    for(int i = 0; i < NUMSTUDENTS; i++)
        classRosterArray[i]->print();
}

//public void printDaysInCourse(string studentID) that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.


void Roster::printDaysInCourse(string studentId)
{
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
        if(classRosterArray[i]->getStudentId().compare(studentId) == 0)
        {
            cout << "The student with Id: " << classRosterArray[i]->getStudentId() << endl;
            cout << "Has an average days in 3 courses of: " << classRosterArray[i]->getNumberOfDays() << endl;
        }
    }
}

//verifies student email addresses and displays all invalid email addresses to the user
// Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').

void Roster::printInvalidEmails()
{
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
        string emailToCheck = classRosterArray[i]->getEmailAddress();
        
        if(emailToCheck.find(" ") < 0) // no spaces
            if(emailToCheck.find("@") > 0) // @ symbol
                if(emailToCheck.find(".") > emailToCheck.find("@")) // . at end
                    continue;
        else
            cout << "The email " << emailToCheck << " is invalid." << endl;
    }
}

// that prints out student information for a degree program specified by an enumerated type
void Roster::printDegreeProgram(string degreeProgram)
{
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
        if(classRosterArray[i]->getDegreeProgram().compare(degreeProgram) == 0)
            classRosterArray[i]->print();
    }
}

/*  FUNCTIONS   */
void Introductions();

int main()
{
    // assigning value to string s
    const string s = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY";
    
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Theron,Fereday,tfereda@wgu.edu,31,10,20,30,SOFTWARE"
    };
    
    // keeps position of tokens for find
    int startingPos = 0;
    string strDelimiter = ",";
    string parsedData[NUMSTUDENTS][9];
    Roster* classRoster = new Roster();   // holds student objects
    
    
/* PARSE OUT STUDENT DATA */
    
    for(int i = 0; i < 5; i++)
    {
        size_t found = studentData[i].find(strDelimiter);
        //cout << "[" << i << "] = [" << studentData[i] << "], Length= " << studentData[i].length() << endl;
        
        int field = 0;
        do
        {
            // Grab the intermediate parsed fields
            parsedData[i][field] = studentData[i].substr(startingPos, found-startingPos);
            field++;
            
            startingPos = found+1;
            found = studentData[i].find(strDelimiter, startingPos);
            
        } while(found < studentData[i].length());
        
        // Grab the last parsed field
        parsedData[i][field] = studentData[i].substr(startingPos, found-startingPos);
        field++;
        
        startingPos = found+1;
        found = studentData[i].find(strDelimiter, startingPos);
        
        cout << endl;
        
        /* ADD STUDENTS TO ROSTER */
        
        string studentId = parsedData[i][0];
        string firstName = parsedData[i][1];
        string lastName= parsedData[i][2];
        string emailAddress = parsedData[i][3];
        int age = stoi(parsedData[i][4]);
        int daysInCourse1 = stoi(parsedData[i][5]);
        int daysInCourse2 = stoi(parsedData[i][6]);
        int daysInCourse3 = stoi(parsedData[i][7]);
        string degreeType = parsedData[i][8];
        
        classRoster->add(studentId, firstName, lastName, emailAddress, age,
                         daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
    }
    
    
    // TESTS //
//    cout << "Print class roster" << endl;
//    cout << classRoster->classRosterArray.printAll() << endl;
//    cout << "Print invalid emails" << endl;
//    cout << classRoster->printInvalidEmails() << endl;
//    //loop through classRosterArray and for each element:
//    cout << "Print class roster /n" << endl;
//    cout << classRoster->printAverageDaysInCourse(/*current_object's student id*/) << endl;
//    cout << "Print class roster /n" << endl;
//    cout << classRoster->printByDegreeProgram(SOFTWARE) << endl;
//    cout << "Print class roster /n" << endl;
//    cout << classRoster->remove("A3") << endl;
//    cout << "Print class roster /n" << endl;
//    cout << classRoster->remove("A3") << endl;
    
    return 0;
}

void Introductions()
{
    std::cout << "SCRIPTING AND PROGRAMMING APPLICATIONS — C867" << std::endl;
    std::cout << "Programming language: C++" << std::endl;
    //std::cout << student ID & name;
}
