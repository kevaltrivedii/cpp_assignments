// Module 6 Q-8 Create a class person having members name and age.
// Derive a class student having member percentage.
// Derive another class teacher having member salary. Write necessary member function to initialize, read and write data.
// Write also Main function (Multiple Inheritance)


#include<iostream>
using namespace std;

// Base Class Person
class Person {
    protected:
        string name;
        int age;
    public:
        void readData() {
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter Age: ";
            cin>>age;
        }
        void printData() {
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
        }
};

// Derived Class Student from Person
class Student : public Person {
    private:
        float percentage;
    public:
        void readData() {
            Person::readData(); // Call Base Class function to read data
            cout<<"Enter Percentage: ";
            cin>>percentage;
        }
        void printData() {
            Person::printData(); // Call Base Class function to print data
            cout<<"Percentage: "<<percentage<<endl;
        }
};

// Derived Class Teacher from Person
class Teacher : public Person {
    private:
        int salary;
    public:
        void readData() {
            Person::readData(); // Call Base Class function to read data
            cout<<"Enter Salary: ";
            cin>>salary;
        }
        void printData() {
            Person::printData(); // Call Base Class function to print data
            cout<<"Salary: "<<salary<<endl;
        }
};

int main() {
    Student s;
    cout<<"Enter Student Data:\n";
    s.readData();
    cout<<"\nStudent Data:\n";
    s.printData();

    Teacher t;
    cout<<"\nEnter Teacher Data:\n";
    t.readData();
    cout<<"\nTeacher Data:\n";
    t.printData();

    return 0;
}
