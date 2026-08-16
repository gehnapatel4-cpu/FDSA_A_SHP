#include <iostream>
using namespace std;


int iterativeBinarySearch(int arr[], int n, int target)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == target)
            return mid;

        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}


int recursiveBinarySearch(int arr[], int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == target)
        return mid;

    else if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, high, target);

    else
        return recursiveBinarySearch(arr, low, mid - 1, target);
}

int main()
{
    int n;

    cout << "Enter number of book codes: ";
    cin >> n;

    int arr[n];

    cout << "Enter the sorted book codes:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "Enter target book code: ";
    cin >> target;


        int result1 = iterativeBinarySearch(arr, n, target);

    if (result1 != -1)
        cout << "\nIterative Search: Book code found at position " << result1 + 1 << endl;
    else
        cout << "\nIterative Search: Book code not found." << endl;


    int result2 = recursiveBinarySearch(arr, 0, n - 1, target);

    if (result2 != -1)
        cout << "Recursive Search: Book code found at position " << result2 + 1 << endl;
    else
        cout << "Recursive Search: Book code not found." << endl;

    return 0;
}
