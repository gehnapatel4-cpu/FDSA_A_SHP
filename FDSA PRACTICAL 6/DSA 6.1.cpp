#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of stack: ";
    cin >> n;

    int stack[100];
    int top = -1;

    int choice, tray;

    while (true) {
        cout << "\n1. Place tray";
        cout << "\n2. Take tray";
        cout << "\n3. Display top";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter tray number: ";
            cin >> tray;

            if (top == n - 1) {
                cout << "Error: Stack is full" << endl;
            } else {
                top++;
                stack[top] = tray;
                cout << "Tray placed" << endl;
                cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 2) {
            if (top == -1) {
                cout << "Error: Stack is empty" << endl;
            } else {
                cout << "Tray taken: " << stack[top] << endl;
                top--;

                if (top == -1)
                    cout << "Stack is now empty" << endl;
                else
                    cout << "Top tray: " << stack[top] << endl;
            }
        }

        else if (choice == 3) {
            if (top == -1)
                cout << "Stack is empty" << endl;
            else
                cout << "Top tray: " << stack[top] << endl;
        }

        else if (choice == 4) {
            break;
        }

        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
