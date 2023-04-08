// Module 6 Q-6  Write a program of two concatenate the two strings using Operator Overloading


#include <iostream>
#include <cstring>

// Creating a class named String
class String {
    private:
        char *str; // Pointer to char to store string
    
    public:
        // Default constructor which initializes str pointer to NULL
        String() {
            str = NULL;
        }

        // Parameterized constructor which accepts a const char pointer as argument
        String(const char *s) {
            // Memory allocation for str depending on the size of s
            str = new char[strlen(s) + 1];
            // Copying the value of s to str
            strcpy(str, s);
        }

        // Destructor to deallocate memory allocated to str
        ~String() {
            if (str != NULL)
                delete[] str;
        }

        // Function to display the value of str
        void display() {
            cout << str << endl;
        }
        
        // Overloading the + operator to concatenate two strings
        String operator+(const String& s2) const {
            String result;
            if (s2.str == NULL) {
                result = *this;
            } else if (str == NULL) {
                result = s2;
            } else {
                // Memory allocation for result.str depending on the size of s1 and s2
                result.str = new char[strlen(str) + strlen(s2.str) + 1];
                // Concatenating s1 and s2 to result.str using strcat
                strcpy(result.str, str);
                strcat(result.str, s2.str);
            }
            return result;
        }
};

int main() {
    // Creating three instances of String class
    String s1 = "Hello";
    String s2 = " world!";
    // Concatenation operator overloaded
    String s3 = s1 + s2; 
    // Displaying the values of s1, s2 and s3
    cout << "s1 = ";
    s1.display();
    cout << "s2 = ";
    s2.display();
    cout << "s3 = ";
    s3.display();
    return 0;
}
