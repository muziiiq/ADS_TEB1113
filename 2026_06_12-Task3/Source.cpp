#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

struct Node {
    string name;
    Node* next = NULL;
};


// DISPLAY FUNCTION
void display(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->name << endl;
        temp = temp->next;
    }
}

// INSERT AT END FUNCTION
void insertEnd(Node*& head, string name) {
    Node* newNode = new Node();
    newNode->name = name;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// DELETE BY NAME FUNCTION
void deleteNode(Node*& head, string name) {
    if (head == NULL) return;

    Node* current = head;
    Node* previous = NULL;

    // search node
    while (current != NULL && current->name != name) {
        previous = current;
        current = current->next;
    }

    // not found
    if (current == NULL) return;

    // CASE 1: delete head node
    if (previous == NULL) {
        head = current->next;
    }
    // CASE 2: delete middle/last node
    else {
        previous->next = current->next;
    }

    delete current;
}

int main() {
    Node* head = NULL;

    // INSERT NODES
    insertEnd(head, "Aimar");
    insertEnd(head, "Ahmad");
    insertEnd(head, "Anajana");
    insertEnd(head, "Jessy");

    cout << "Original List:\n";
    display(head);

    // DELETE A NODE
    deleteNode(head, "Ahmad");

    cout << "\nAfter Deletion:\n";
    display(head);

    return 0;
}

//int main() {
//    Node* node1 = new Node(); //0x251732e0
//    Node* node2 = new Node(); //0x251732e1
//    Node* node3 = new Node(); //0x251732e2
//    Node* node4 = new Node(); //0x251732e3
//
//    node1->name = "Aimar";
//    node1->next = node2; //0x251732e1
//
//    node2->name = "Ahmad";
//    node2->next = node3; //0x251732e2
//
//    node3->name = "Anajana";
//    node3->next = node4; //0x251732e3
//
//    node4->name = "Jessy";
//
//    Node* display_node = node1;
//    for (int i = 0; i < 4; i++) {
//        cout << display_node->name << endl; // 0x251732e2
//        display_node = display_node->next; //  0x251732e3
//    }
//
//    return 0;
//}