#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

class Queue {
public:
    string name;
    Queue* next = NULL;

    // Enqueue (Insert at Rear)
    static void enqueue(Queue*& front, Queue*& rear, string value) {
        Queue* newNode = new Queue();
        newNode->name = value;
        newNode->next = NULL;

        if (rear == NULL) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue (Remove from Front)
    static void dequeue(Queue*& front, Queue*& rear) {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Queue* temp = front;
        cout << "Removed: " << temp->name << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    // Peek
    static void peek(Queue* front) {
        if (front == NULL)
            cout << "Queue is empty!" << endl;
        else
            cout << "Front = " << front->name << endl;
    }

    // Display
    static void display(Queue* front) {
        Queue* current = front;

        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {

    Queue* front = NULL;
    Queue* rear = NULL;

    Queue::enqueue(front, rear, "Aimar");
    Queue::enqueue(front, rear, "Ahmad");
    Queue::enqueue(front, rear, "Anajana");
    Queue::enqueue(front, rear, "Jessy");

    Queue::peek(front);

    cout << endl;

    Queue::display(front);

    Queue::dequeue(front, rear);

    cout << endl;

    Queue::display(front);

    return 0;
}