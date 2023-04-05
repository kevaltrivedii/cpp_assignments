#include <iostream>
using namespace std;
//class name matrix with constructor
class Matrix {
    private:
        int rows, cols;
        int **data;

    public:
        Matrix(int r, int c) {
            rows = r;
            cols = c;
            data = new int*[rows];
            for(int i=0; i<rows; i++) {
                data[i] = new int[cols];
            }
        }

        ~Matrix() {
            for(int i=0; i<rows; i++) {
                delete [] data[i];
            }
            delete [] data;
        }

        void read() {
            cout << "Enter the elements of the matrix:\n";
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                   cin >> data[i][j];
                }
            }
        }

        void display() {
            cout << "The matrix is:\n";
            for (int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    cout << data[i][j] << "\t";
                }
                cout << endl;
            }
        }

        Matrix operator +(Matrix const &obj) {
            Matrix res(rows, cols);
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    res.data[i][j] = data[i][j] + obj.data[i][j];
                }
            }
            return res;
        }
};

int main() {
    int r, c;
    cout << "Enter size of matrices (rows and columns): ";
    cin >> r >> c;

    Matrix m1(r, c);
    m1.read();
    m1.display();

    Matrix m2(r, c);
    m2.read();
    m2.display();

    Matrix sum = m1 + m2;
    cout << "\nAddition of matrices:\n";
    sum.display();

    return 0;
}