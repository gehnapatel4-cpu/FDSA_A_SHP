#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        int swapped = 0;

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {78, 45, 90, 62, 55};
    int n = sizeof(arr) / sizeof(arr[0]);

    int b[n], s[n], in[n];

    // Copy original array
    for (int i = 0; i < n; i++) {
        b[i] = arr[i];
        s[i] = arr[i];
        in[i] = arr[i];
    }

    // Bubble Sort
    bubbleSort(b, n);
    cout << "Bubble Sort: ";
    printArray(b, n);

    // Selection Sort
    selectionSort(s, n);
    cout << "Selection Sort: ";
    printArray(s, n);

    // Insertion Sort
    insertionSort(in, n);
    cout << "Insertion Sort: ";
    printArray(in, n);

    return 0;
}
