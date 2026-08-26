#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};


void insertEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void deleteByValue(Node*& head, int value) {
    if (head == nullptr)
        return;


    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next != nullptr && temp->next->data != value) {
        temp = temp->next;
    }


    if (temp->next == nullptr) {
        cout << "Patient not found!" << endl;
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;
    delete deleteNode;
}


void displayForward(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


void displayReverse(Node* head) {
    if (head == nullptr)
        return;

    displayReverse(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 101);
    insertEnd(head, 102);
    insertEnd(head, 103);
    insertEnd(head, 104);

    cout << "Queue from front to back: ";
    displayForward(head);

    deleteByValue(head, 102);

    cout << "After deleting 102: ";
    displayForward(head);

    cout << "Queue from last to first: ";
    displayReverse(head);
    cout << endl;

    return 0;
}
