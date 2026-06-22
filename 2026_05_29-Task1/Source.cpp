#include <iostream>
#include <string>

using namespace std;

struct Student {
	string Id;
	string Name;
	string Course;
	int Age;
};

int main() {
	Student student[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "---------------------------" << endl;
        cout << "Enter name : ";
        cin >> student[i].Name;
        cout << "Enter id : ";
        cin >> student[i].Id;
        cout << "Enter course : ";
        cin >> student[i].Course;
        cout << "Enter age : ";
        cin >> student[i].Age;
        cout << "---------------------------" << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "---------------------------" << endl;
        cout << "Name : " << student[i].Name << endl;
        cout << "ID : " << student[i].Id << endl;
        cout << "Course : " << student[i].Course << endl;
        cout << "Age : " << student[i].Age << endl;
        cout << "---------------------------" << endl;
    }

    return 0; 
}