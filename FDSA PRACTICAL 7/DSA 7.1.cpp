#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int q[1000];
    int front = -1, rear = -1;

    for (int i = 0; i < m; i++) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            int token;
            cin >> token;

            if ((rear + 1) % n == front) {
                cout << "Error: Queue is Full" << endl;
            } else {
                if (front == -1)
                    front = rear = 0;
                else
                    rear = (rear + 1) % n;

                q[rear] = token;
                cout << "Front: " << q[front] << endl;
            }
        }
        else if (choice == 2) {
            if (front == -1) {
                cout << "Error: Queue is Empty" << endl;
            } else {
                cout << "Served: " << q[front] << endl;

                if (front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % n;

                if (front != -1)
                    cout << "Front: " << q[front] << endl;
                else
                    cout << "Front: Empty" << endl;
            }
        }
    }

    return 0;
}

