#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = NULL;
        prev = NULL;
    }
};

// DISPLAY (circular safe)
void display(Node* head) {
    if (head == NULL) return;

    Node* temp = head;

    do {
        cout << temp->name << endl;
        temp = temp->next;
    } while (temp != head);
}

// INSERT AT END
void insertEnd(Node*& head, string name) {
    Node* newNode = new Node(name);

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    Node* tail = head->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = head;
    head->prev = newNode;
}

// DELETE BY NAME
void deleteNode(Node*& head, string name) {
    if (head == NULL) return;

    Node* current = head;

    // search node (circular traversal)
    do {
        if (current->name == name) break;
        current = current->next;
    } while (current != head);

    // not found
    if (current->name != name) return;

    // CASE 1: only one node
    if (current->next == current) {
        delete current;
        head = NULL;
        return;
    }

    // reconnect neighbors
    current->prev->next = current->next;
    current->next->prev = current->prev;

    // update head if needed
    if (current == head) {
        head = current->next;
    }

    delete current;
}

int main() {
    Node* head = NULL;

    insertEnd(head, "Aimar");
    insertEnd(head, "Ahmad");
    insertEnd(head, "Anajana");
    insertEnd(head, "Jessy");

    cout << "Original List:\n";
    display(head);

    deleteNode(head, "Ahmad");

    cout << "\nAfter Deletion:\n";
    display(head);

    return 0;
}