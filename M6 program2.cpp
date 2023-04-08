// //module6 Q-2  Define a class to represent lecture details. Include the following members and the program should handle at least details of 5 lecturer.
// Data members:
// a) Name of the lecturer
// b) Name of the subject
// c) Name of course
// d) Number of lecturers
// Data functions:
// a) To assign initial values
// b) To add a lecture details
// c) To display name and lecture details


#include <iostream>
#include <string>
using namespace std;

class Lecture {
private:
    string lecturerName;
    string subjectName;
    string courseName;
    int numLecturers;
public:
    // Default constructor
    Lecture() {
        lecturerName = "";
        subjectName = "";
        courseName = "";
        numLecturers = 0;
    }

    // Function to assign initial values
    void setInitialValues(string lecturer, string subject, string course, int num) {
        this->lecturerName = lecturer;
        this->subjectName = subject;
        this->courseName = course;
       this-> numLecturers = num;
    }

    // Function to add a lecture detail
    void addLectureDetails() {
        cout << "Enter the lecturer's name: ";
        getline(cin, lecturerName);
        cout << "Enter the subject name: ";
        getline(cin, subjectName);
        cout << "Enter the course name: ";
        getline(cin, courseName);
        cout << "Enter the number of lecturers: ";
        cin >> numLecturers;
        cin.ignore(); // ignore the '\n' character left in the input stream
    }

    // Function to display name and lecture details
    void display() {
        cout << "Lecturer's name: " << lecturerName << endl;
        cout << "Subject name: " << subjectName << endl;
        cout << "Course name: " << courseName << endl;
        cout << "Number of lecturers: " << numLecturers << endl;
    }
};

int main() {
    // Create an array of Lecture objects to handle details of 5 lecturers
    const int Num_Lecturers = 5;
    Lecture lecturers[Num_Lecturers];

    // Assign initial values to the lecturers
    lecturers[0].setInitialValues("Jhon", "Mathematics", "Calculus I", 1);
    lecturers[1].setInitialValues("Jane", "English", "American Literature", 2);
    lecturers[2].setInitialValues("Tom ", "History", "World War II", 3);
    lecturers[3].setInitialValues("Sarah", "Biology", "Human Anatomy", 4);
    lecturers[4].setInitialValues("Davis", "Computer Science", "Data Structures", 5);

    // Add lecture details for each lecturer
    for (int i = 0; i < Num_Lecturers; i++) {
        cout << "Lecturer ." << i+1 << ":" << endl;
        lecturers[i].addLectureDetails();
        cout << endl;
    }

    // Display the name and lecture details for each lecturer
    for (int i = 0; i < Num_Lecturers; i++) {
        cout << "Details for lecturer ." << i+1 << ":" << endl;
        lecturers[i].display();
        cout << endl;
    }

    return 0;
}
