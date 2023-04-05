#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
        char *str;
    
    public:
        String() {
            str = NULL;
        }

        String(const char *s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }

        ~String() {
            if (str != NULL)
                delete[] str;
        }

        void display() {
            cout << str << endl;
        }
        
        String operator+(const String& s2) const {
            String result;
            if (s2.str == NULL) {
                result = *this;
            } else if (str == NULL) {
                result = s2;
            } else {
                result.str = new char[strlen(str) + strlen(s2.str) + 1];
                strcpy(result.str, str);
                strcat(result.str, s2.str);
            }
            return result;
        }
};

int main() {
    String s1 = "Hello";
    String s2 = " world!";
    // Concatenation operator overloaded
    String s3 = s1 + s2; 
    cout << "s1 = ";
    s1.display();
    cout << "s2 = ";
    s2.display();
    cout << "s3 = ";
    s3.display();
    return 0;
}