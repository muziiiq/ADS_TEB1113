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
    static const int MAX = 100;
    static string queue[MAX];
    static int front;
    static int rear;

    // Enqueue (Insert)
    static void enqueue(string value) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
    }

    // Dequeue (Remove)
    static void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Removed: " << queue[front] << endl;
        front++;

        // Reset when queue becomes empty
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    // Peek
    static void peek() {
        if (front == -1)
            cout << "Queue is empty!" << endl;
        else
            cout << "Front = " << queue[front] << endl;
    }

    // Display
    static void display() {
        if (front == -1) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << queue[i] << endl;
        }
    }
};

// Static member definitions
string Queue::queue[Queue::MAX];
int Queue::front = -1;
int Queue::rear = -1;

int main() {

    Queue::enqueue("Aimar");
    Queue::enqueue("Ahmad");
    Queue::enqueue("Anajana");
    Queue::enqueue("Jessy");

    Queue::peek();

    cout << endl;

    Queue::display();

    Queue::dequeue();

    cout << endl;

    Queue::display();

    return 0;
}