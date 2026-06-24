#include <iostream>
#include <string>

using namespace std;

//Create a structure
struct Student {
    int id;
    string name;
    int age;
    string course;
};

int main() {
    //Declare an array 
    Student A[5];

    //Save 5 students records in array
    //Student #1 records
    A[0].id = 24001;
    A[0].name = "Ali";
    A[0].age = 18;
    A[0].course = "CS";

    //Student #2 records
    A[1].id = 24002;
    A[1].name = "Abu";
    A[1].age = 19;
    A[1].course = "CS";

    //Student #3 records
    A[2].id = 24003;
    A[2].name = "Hasan";
    A[2].age = 18;
    A[2].course = "CS";

    //Student #4 records
    A[3].id = 24004;
    A[3].name = "Wafiey";
    A[3].age = 20;
    A[3].course = "CS";

    //Student #5 records
    A[4].id = 24005;
    A[4].name = "Adi";
    A[4].age = 18;
    A[4].course = "CS";


    //Display all records of students
    for (int i = 0; i < 5; i++) {
        cout << "Student #" << i + 1 << " details:" << endl;
        cout << "Id :" << A[i].id << endl;
        cout << "Name :" << A[i].name << endl;
        cout << "Age :" << A[i].age << endl;
        cout << "Course :" << A[i].course << endl;
        cout << endl;
    }


    //Search student by id
    int searchId;
    cout << "Enter student's id for search :";
    cin >> searchId;

    for (int i = 0; i < 5; i++) {
        if (A[i].id == searchId) {
            cout << "Student #" << i + 1 << " details:" << endl;
            cout << "Id :" << A[i].id << endl;
            cout << "Name :" << A[i].name << endl;
            cout << "Age :" << A[i].age << endl;
            cout << "Course :" << A[i].course << endl;
            cout << endl;
        }
    }


    //Update one student record
    int option;
    cout << "Choose which student record to update(1-5) :";
    cin >> option;
    cout << endl;

    cout << "Please enter the #" << option << " student's new id :";
    cin >> A[option - 1].id;
    cout << "Please enter the #" << option << " student's new name :";
    cin >> A[option - 1].name;
    cout << "Please enter the #" << option << " student's new age :";
    cin >> A[option - 1].age;
    cout << "Please enter the #" << option << " student's new course :";
    cin >> A[option - 1].course;
    cout << endl;

    cout << "Student #" << option << " new details:" << endl;
    cout << "Id :" << A[option - 1].id << endl;
    cout << "Name :" << A[option - 1].name << endl;
    cout << "Age :" << A[option - 1].age << endl;
    cout << "Course :" << A[option - 1].course << endl;
}