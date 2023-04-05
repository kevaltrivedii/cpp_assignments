
#include <iostream>
#include <string>
using namespace std;
//declare class as cricketer
class Cricketer {
    private:
        string name;
        int age;
    
    public:// take user input data for name and age
        void input_data() {
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
        }
          //diplay name and age
        void display_data() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
};

//public the cricketer class into batsman class to access objects of it
class Batsman : public Cricketer {
    private:
        int total_runs;
        double avg_runs;
        int best_performance;
    //derived public class for total runs and best performer
    public:
        void input_data() {
            Cricketer::input_data();
            cout << "Enter total runs: ";
            cin >> total_runs;
            cout << "Enter best performance: ";
            cin >> best_performance;
        }

        void calculate_avg_runs() {
            // Calculate average runs per innings
            // (Assuming 20 innings played)
            avg_runs = (double)total_runs / 20.0;
        }

        void display_data() {
            Cricketer::display_data();
            cout << "Total runs: " << total_runs << endl;
            cout << "Average runs per innings: " << avg_runs << endl;
            cout << "Best performance: " << best_performance << endl;
        }
};

int main() {
    Batsman b1;
    b1.input_data();
    b1.calculate_avg_runs();
    b1.display_data();
    return 0;
}
