#include <iostream>
using namespace std;

int main() {
    int slot[10];

    for (int i = 0; i < 10; i++)
        slot[i] = -1;

    int n, reg;
    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter registration number: ";
        cin >> reg;

        int index = reg % 10;
        int count = 0;

        while (slot[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }

        if (count == 10) {
            cout << "Parking lot is full. Vehicle " << reg
                 << " cannot be parked.\n";
        } else {
            slot[index] = reg;
            cout << "Vehicle " << reg << " parked at slot "
                 << index << endl;
        }
    }

    cout << "\nFinal parking slots:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";
        if (slot[i] == -1)
            cout << "Empty";
        else
            cout << slot[i];
        cout << endl;
    }

    return 0;
}

