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

// DISPLAY FUNCTION
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

// INSERT AT END
void insertEnd(Node*& head, string name) {
    Node* newNode = new Node(name);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// DELETE BY NAME
void deleteNode(Node*& head, string name) {
    if (head == NULL) return;

    Node* current = head;

    // search node
    while (current != NULL && current->name != name) {
        current = current->next;
    }

    // not found
    if (current == NULL) return;

    // CASE 1: deleting head
    if (current->prev == NULL) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    // CASE 2: middle or last node
    else {
        current->prev->next = current->next;

        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
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