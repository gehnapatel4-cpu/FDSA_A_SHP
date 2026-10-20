
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* front = NULL;
    Node* rear = NULL;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            int patient;
            cin >> patient;

            Node* newNode = new Node;
            newNode->data = patient;
            newNode->next = NULL;

            if (rear == NULL) {
                front = rear = newNode;
            } else {
                rear->next = newNode;
                rear = newNode;
            }

            cout << "Front: " << front->data << endl;
        }
        else if (choice == 2) {
            if (front == NULL) {
                cout << "Error: Queue is Empty" << endl;
            } else {
                cout << "Attended: " << front->data << endl;

                Node* temp = front;
                front = front->next;
                delete temp;

                if (front == NULL)
                    rear = NULL;

                if (front != NULL)
                    cout << "Front: " << front->data << endl;
                else
                    cout << "Front: Empty" << endl;
            }
        }
    }

    return 0;
}
