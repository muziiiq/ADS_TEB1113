#include <iostream>
#include <string>

using namespace std;

// Define the Student structure
struct Student {
    string ID;
    string name;
    string course;
    int age;
};

int main() {

    Student student[5];

    // Input 5 students
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter details for Student " << i + 1 << endl;

        cout << "ID: ";
        cin >> student[i].ID;

        cout << "Name: ";
        cin >> student[i].name;

        cout << "Course: ";
        cin >> student[i].course;

        cout << "Age: ";
        cin >> student[i].age;
    }

    // Display all records
    cout << "===== ALL STUDENT RECORDS =====\n";

    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << endl;
        cout << "ID     : " << student[i].ID << endl;
        cout << "Name   : " << student[i].name << endl;
        cout << "Course : " << student[i].course << endl;
        cout << "Age    : " << student[i].age << endl;
    }


    // Search by Student ID
    string searchID;
    cout << "\nEnter Student ID to search: ";
    cin >> searchID;

    int index = -1;

    for (int i = 0; i < 5; i++) {
        if (student[i].ID == searchID) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        cout << "\nRecord Found\n";
        cout << "ID     : " << student[index].ID << endl;
        cout << "Name   : " << student[index].name << endl;
        cout << "Course : " << student[index].course << endl;
        cout << "Age    : " << student[index].age << endl;


        // Update Record
        int choice;

        cout << "\nWhat do you want to change?\n";
        cout << "1. Name\n";
        cout << "2. Course\n";
        cout << "3. Age\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter new name: ";
            cin >> student[index].name;
            break;

        case 2:
            cout << "Enter new course: ";
            cin >> student[index].course;
            break;

        case 3:
            cout << "Enter new age: ";
            cin >> student[index].age;
            break;

        default:
            cout << "Invalid choice.\n";
        }

        // Display updated record
        cout << "\n===== UPDATED RECORD =====\n";
        cout << "ID     : " << student[index].ID << endl;
        cout << "Name   : " << student[index].name << endl;
        cout << "Course : " << student[index].course << endl;
        cout << "Age    : " << student[index].age << endl;
    }
    else {
        cout << "Student ID not found.\n";
    }

    return 0;
}