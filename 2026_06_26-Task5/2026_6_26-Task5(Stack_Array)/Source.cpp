#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

class Stack {
public:
    static const int MAX = 100;
    static string stack[MAX];
    static int top;

    // Push
    static void push(string value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        top++;
        stack[top] = value;
    }

    // Pop
    static void pop() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Removed: " << stack[top] << endl;
        top--;
    }

    // Peek
    static void peek() {
        if (top == -1)
            cout << "Stack is empty!" << endl;
        else
            cout << "Top = " << stack[top] << endl;
    }

    // Display
    static void display() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

// Static member definitions
string Stack::stack[Stack::MAX];
int Stack::top = -1;

int main() {

    Stack::push("Aimar");
    Stack::push("Ahmad");
    Stack::push("Anajana");
    Stack::push("Jessy");

    Stack::peek();

    cout << endl;

    Stack::display();

    Stack::pop();

    cout << endl;

    Stack::display();

    return 0;
}