//Name: Piyush Manoj Jain ||Roll no:36||Div:SE-A
//Problem Statement:-WRITE A C++ CODE THAT CREATES AN OUTPUT FILE, WRITES INFORMATION TO IT, CLOSES THE FILE
//AND OPEN OT AGAIN AS AN INPUT FILE AND READ THE INFORMATION FROM THE FILE.

#include <iostream>
#include <fstream>
using namespace std;

class Employee
{
    string name, designation;
    int id;
    float salary;

public:
    Employee()
    {
        name = "None";
        designation = "None";
        id = 0;
        salary = 0;
    }

    void getdata(int n)
    {
        ofstream out("Employee_data.txt", ios::app); // Open file in append mode
        for (int i = 0; i < n; i++)
        {
            cout << "\n\t****Employee No. " << i + 1 << " details****";
            cout << "\nEnter the Employee name: ";
            cin >> name;
            cout << "Enter the Employee ID: ";
            cin >> id;
            cout << "Enter the designation of Employee: ";
            cin >> designation;
            cout << "Enter the Salary of the Employee: Rs.";
            cin >> salary;
            cout << endl;

            // Write data to file
            out << "\n\t****Employee No. " << i + 1 << " details****";
            out << "\nEmployee Name: " << name;
            out << "\nEmployee ID: " << id;
            out << "\nEmployee designation: " << designation;
            out << "\nEmployee Salary: " << salary;
        }
        out.close(); // Close the file after writing
    }

    void putdata()
    {
        ifstream in("Employee_data.txt");
            string line;
            while (getline(in, line))
            {
                cout << line << endl;
            }
            in.close(); // Close the file after reading
    }
};

int main()
{
    Employee obj;
    int ch, eno;
    cout << "\t***WELCOME TO EMPLOYEE DATABASE!!***" << endl;
    do
    {
        cout << "\n\t**MENU**";
        cout << "\n1) Write Employee details into file.\n2) Read Employee details from file.\n3) Exit." << endl;
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "How many employee records you would like to enter? ";
            cin >> eno;
            obj.getdata(eno);
            cout << "--------Data recorded successfully!--------" << endl;
            break;
        case 2:
            obj.putdata();
            cout << "\n--------Reading Operation was a Success!!--------" << endl;
            break;
        case 3:
            cout << "";
            break;
        default:
            cout << "Enter a valid choice!" << endl;
        }
    } while (ch != 3);
    cout << "Thank You. Visit Again!!";

    return 0;
}
