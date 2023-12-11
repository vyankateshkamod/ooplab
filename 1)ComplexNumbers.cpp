//Name:Piyush Manoj Jain||Roll no:36||Div:SE-A
//Problem Statement:Implement a class complex which represents the complex number data type.
//Implement the following operations:
//1)Constructor(including a default constructor which creates the complex number  0+0i.
//2)overloaded operator + to add two complex numbers.
//3)overloaded operator * two multiply two complex numbers.
//4)overloaded << and >> to print and read complex numbers.

#include <iostream>
using namespace std;

class Complex {
    float real, img;

public:
    Complex() {
        real = 0.0;
        img = 0.0;
    }

    friend istream &operator>>(istream &, Complex &);
    friend ostream &operator<<(ostream &, const Complex &);

    void getdata() {
        cout << "Enter the real part: ";
        cin >> real;
        cout << "Enter the imaginary part: ";
        cin >> img;
    }

    void putdata() {
        cout << "Result:" << real << "+" << img << "i" << endl;
    }

    Complex operator+(Complex ob) {
        Complex answer;
        answer.real = real + ob.real;
        answer.img = img + ob.img;
        return answer;
    }

    Complex operator*(Complex ob) {
        Complex answer;
        answer.real = (real * ob.real) - (img * ob.img);
        answer.img = (real * ob.img) + (img * ob.real);
        return answer;
    }
};

istream &operator>>(istream &in, Complex &obj) {
    cout << "Enter the real part: ";
    in >> obj.real;
    cout << "Enter the imaginary part: ";
    in >> obj.img;
    return in;
}

ostream &operator<<(ostream &out, const Complex &obj) {
    out << "Result: " << obj.real << "+" << obj.img << "i" << endl;
    return out;
}

int main() {
    Complex ob1, ob2, result;
    int ch;
    do {
        cout << "***Welcome to Complex Calculator***" << endl;
        cout << "\t 1.Addition of Complex number.\n\t 2.Multiplication of Complex Numbers.\n\t 3.Exit" << endl;
        cout << "\t Make Your Choice:";
        cin >> ch;
        cout << endl;

        switch (ch) {
        case 1:
            cout << "***First Complex Number***" << endl;
            cin >> ob1;
            cout << "***Second Complex Number***" << endl;
            cin >> ob2;
            result = ob1 + ob2;
            cout << result << endl;
            cout << endl;
            break;

        case 2:
            cout << "***First Complex Number***" << endl;
            cin >> ob1;
            cout << "***Second Complex Number***" << endl;
            cin >> ob2;
            result = ob1 * ob2;
            cout << result << endl;
            cout << endl;
            break;
        }
    } while (ch != 3);

    cout << "Thank You for using Complex Calculator!!";
    return 0;
}
