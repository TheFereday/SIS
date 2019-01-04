
#include <iostream>
#include <cstring>
#include <string.h>
#include <string>
#include <array>
#include "roster.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "degree.h"

using std::string;
using std::cout;
using std::endl;
using std::stoi;

//Global variables
int NUMSTUDENTS = 5;

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
    
    Degree degType = (Degree)0;
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    //cout << "Inside add: " << degType << "  " << degreeType <<endl;
    
    if(degreeType.compare("NETWORK") == 0)
    {
        degType = (Degree)1;
        //cout << "Inside NETWORK if: " << degType << endl;
        classRosterArray[arrayPosition] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degType);
    }

    if(degreeType.compare("SECURITY") == 0)
    {
        degType = (Degree)2;
        //cout << "Inside SECURITY if: " << degType << endl;
        classRosterArray[arrayPosition] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degType);
    }

    if(degreeType.compare("SOFTWARE") == 0)
    {
        degType = (Degree)3;
        //cout << "Inside SOFTWARE if: " << degType << endl;
        classRosterArray[arrayPosition] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degType);
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
            while((i + count) < (NUMSTUDENTS-1))
            {
                classRosterArray[i+count] = classRosterArray[i+count+1];
                count++;
            }
            //TODO decrease size of array
        }
    }
    
    if(count == 0)
        cout << "Student with Id " << studentId << " not found." << endl;
    
    NUMSTUDENTS--;
}

// public void printAll() that prints a complete tab-separated list of student data using accessor functions with the provided format: 1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all  the students in classRosterArray and call the print() function for each student.

void Roster::printAll()
{
    for(int i = 0; i < NUMSTUDENTS; i++)
        classRosterArray[i]->print();
    
    cout << endl;
}

//public void printDaysInCourse(string studentID) that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.


void Roster::printDaysInCourse(string studentId)
{
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
        if(classRosterArray[i]->getStudentId().compare(studentId) == 0)
        {
            int averageDays = 0;
            
            for(int j = 0; j < 3; j++)
                averageDays += classRosterArray[i]->numberOfDays[j];
            
            averageDays /= 3;
            
            cout << "The student with Id " << classRosterArray[i]->getStudentId()
            << " Has an average days in 3 courses of " << averageDays << endl;
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
        //cout << "Checking: " << emailToCheck << endl;
        
        size_t at = emailToCheck.find('@');
        size_t dot = emailToCheck.find('.', at + 1);
        size_t space = emailToCheck.find(' ');
        
        if(space != string::npos)
            cout << emailToCheck << " has a space." << endl;
        
        else if (at == string::npos)
            cout << emailToCheck << " is missing @ sign." << endl;
        
        else if (dot == string::npos)
            cout << emailToCheck <<  " is missing . after the @." << endl;
        
        else
            continue;
    }
    cout << endl;
}

// that prints out student information for a degree program specified by an enumerated type
void Roster::printDegreeProgram(std::string degreeProgram)
{
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
//        if(classRosterArray[i]->getDegreeProgram().compare(degreeProgram) == 0)
//            classRosterArray[i]->print();
    }
}

/*  FUNCTIONS   */
void Introductions();

int main()
{
    // assigning value to string s
    //const string s = "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY";
    
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
        
        //cout << studentId << firstName << lastName << emailAddress << age << daysInCourse1 << daysInCourse2 << daysInCourse3 << degreeType << endl;
        
        classRoster->add(studentId, firstName, lastName, emailAddress, age,
                         daysInCourse1, daysInCourse2, daysInCourse3, degreeType);
    }
    
    Introductions();
    
    // TESTS //
    cout << "Print class roster" << endl;
    classRoster->printAll();
    
    // prints out emails that are not xxx@xxx.xxx
    cout << "The following students have invalid emails" << endl;
    classRoster->printInvalidEmails();
    
    //loop through classRosterArray and for each element:
    for(int i = 0; i < NUMSTUDENTS; i++)
    {
        classRoster->printDaysInCourse(classRoster->classRosterArray[i]->getStudentId());
    }
    
    cout << endl;
    
    //TODO this function currently has string parameters, how do we use enum?
//    classRoster->printDegreeProgram(SOFTWARE);
    
    cout << "Removing student with Id A3\n" << endl;
    classRoster->remove("A3");
    
    cout << "Re-print class roster with A3 removed." << endl;
    classRoster->printAll();
    
    cout << "Removing student with Id A3, this should output an error." << endl;
    classRoster->remove("A3");
    classRoster->~Roster();
    
    return 0;
}

void Introductions()
{
    cout << "SCRIPTING AND PROGRAMMING APPLICATIONS — C867" << endl;
    cout << "Programming language: C++11" << endl;
    cout << "Theron Fereday, ID: 699550" << endl;
    cout << endl << endl;
}
