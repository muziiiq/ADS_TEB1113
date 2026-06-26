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
    string name;
    Stack* next = NULL;
    Stack* top = NULL;

    //push 
    static void push(Stack*& top, string value) {
        Stack* newNode = new Stack();
        newNode->name = value;
        newNode->next = top;
        top = newNode;
    }
    //pop
    static void pop(Stack*& top) {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }

        Stack* temp = top;
        cout << "Removed: " << temp->name << endl;
        top = top->next;
        delete temp;
    }

    //peek
    static void peek(Stack*& top) {
        if (top == NULL)
            cout << "Stack is empty!" << endl;
        else
            cout << "Top = " << top->name << endl;
    }

    //display
    static void display(Stack*& top) {
        Stack* display_node = top;
        while (display_node != NULL) {
            cout << display_node->name << endl;
            display_node = display_node->next;
        }
    }
};

int main() {

    Stack* top = NULL;

    Stack::push(top, "Aimar");
    Stack::push(top, "Ahmad");
    Stack::push(top, "Anajana");
    Stack::push(top, "Jessy");

    Stack::peek(top);

    cout << endl;

    Stack::display(top);

    Stack::pop(top);

    cout << endl;

    Stack::display(top);

    return 0;

};