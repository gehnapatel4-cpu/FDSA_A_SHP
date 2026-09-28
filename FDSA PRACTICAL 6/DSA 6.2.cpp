#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

void visit(string page) {
    Node* newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;

    cout << "Current page: " << top->page << endl;
}

void back() {
    if (top == NULL || top->next == NULL) {
        cout << "No previous page" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;

    cout << "Current page: " << top->page << endl;
}

int main() {
    int choice;
    string page;

    while (true) {
        cout << "\n1. Visit page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter page: ";
            cin >> page;
            visit(page);
        }

        else if (choice == 2) {
            back();
        }

        else if (choice == 3) {
            break;
        }

        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
