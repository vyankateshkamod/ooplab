//Name:Piyush Manoj Jain||Roll no:36||Div:SE-A
//Problem Statement: CREATE A DATABASE OF THE PERSONAL INFORMATION CONTAINING THE FOLLLOWING INFORMATION: NAME, DATE OF BIRTH,
//BLOOD GROUP, HEIGHT, WEIGHT, INSURANCE POLICY NUMBER, CONTACT ADDRESS, TELEPHONE NUMBER, DEFAULT CONSTRUCTOR,DESTRUCTOR,
//INITIALIZING AND DESTROYING DATA, FRIEND CLASS, THIS POINTER, INLINE CODE AND DYNAMIC MEMORY ALLOCATION OPERATORS NEW AND
//DELETE AS WELL AS EXCEPTION HANDLING.
#include <iostream>
#include <string>

using namespace std;

class ContactInfo; // Forward declaration

class PersonalInfo {
private:
    string name;
    string dateOfBirth;
    string bloodGroup;
    double height;
    double weight;
    int insurancePolicyNumber;

public:
    PersonalInfo() : height(0.0), weight(0.0), insurancePolicyNumber(0) {
        // Default constructor
    }

    PersonalInfo(const string& n, const string& dob, const string& bg, double h, double w, int policy)
        : name(n), dateOfBirth(dob), bloodGroup(bg), height(h), weight(w), insurancePolicyNumber(policy) {
        // Initializing constructor
    }

    // Inline function to display personal information
    void displayPersonalInfo() const {
        cout << "Name: " << name << "\n";
        cout << "Date of Birth: " << dateOfBirth << "\n";
        cout << "Blood Group: " << bloodGroup << "\n";
        cout << "Height: " << height << " cm\n";
        cout << "Weight: " << weight << " kg\n";
        cout << "Insurance Policy Number: " << insurancePolicyNumber << "\n";
    }

    // Friend class to access ContactInfo's private members
    friend class ContactInfo;

    // Member function using "this" pointer
    void updateWeight(double newWeight) {
        this->weight = newWeight;
    }

    // Exception handling for negative weight
    void setWeight(double newWeight) {
        if (newWeight < 0) {
            throw invalid_argument("Weight cannot be negative");
        }
        this->weight = newWeight;
    }

    // No need for dynamic memory allocation using new operator
};

class ContactInfo {
private:
    string contactAddress;
    long long phoneNumber;

public:
    ContactInfo() : phoneNumber(0) {
        // Default constructor
    }

    ContactInfo(const string& address, long long phone) : contactAddress(address), phoneNumber(phone) {
        // Initializing constructor
    }

    // Inline function to display contact information
    void displayContactInfo() const {
        cout << "Contact Address: " << contactAddress << "\n";
        cout << "Telephone Number: " << phoneNumber << "\n";
    }
};

int main() {
    string name, dob, bloodGroup, address;
    double height, weight;
    int policy, choice;
    long long phoneNumber;

    cout << "\t------WELCOME TO STUDENT DATABASE------";

    PersonalInfo individual;  // Declare outside the loop
    ContactInfo contact;      // Declare outside the loop

    do {
        cout << "\n   MENU\n";
        cout << "1. Enter Personal Information\n";
        cout << "2. Display Information\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout<<endl;

        switch (choice) {
            case 1:
                try {
                    // Taking input from the user
                    cout << "Enter name: ";
                    cin.ignore(); // Clear the newline from the buffer
                    getline(cin, name);

                    cout << "Enter date of birth: ";
                    getline(cin, dob);

                    cout << "Enter blood group: ";
                    getline(cin, bloodGroup);

                    cout << "Enter height (in cm): ";
                    cin >> height;

                    cout << "Enter weight (in kg): ";
                    cin >> weight;

                    // Exception handling for negative weight
                    individual.setWeight(weight);

                    cout << "Enter insurance policy number: ";
                    cin >> policy;

                    cin.ignore(); // Clear the newline from the buffer

                    cout << "Enter contact address: ";
                    getline(cin, address);

                    cout << "Enter telephone number: ";
                    cin >> phoneNumber;

                    // Update the objects inside the loop
                    individual = PersonalInfo(name, dob, bloodGroup, height, weight, policy);
                    contact = ContactInfo(address, phoneNumber);

                    break;
                } catch (const exception& e) {
                    cerr << "Exception: " << e.what() << "\n";
                }
            case 2:
                // Displaying the information
                individual.displayPersonalInfo();
                contact.displayContactInfo();
                break;
            case 3:
                cout << "Exiting the program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
