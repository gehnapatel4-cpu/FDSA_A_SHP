#include <iostream>
using namespace std;

int main()
{
    int n, h;

    cout << "Enter number of bakery items: ";
    cin >> n;

    string items[n];

    cout << "Enter the items: ";
    for(int i = 0; i < n; i++)
    {
        cin >> items[i];
    }

    cout << "Enter number of hours: ";
    cin >> h;


    int k = h % n;

    cout << "Final display order: ";


    for(int i = k; i < n; i++)
    {
        cout << items[i] << " ";
    }


    for(int i = 0; i < k; i++)
    {
        cout << items[i] << " ";
    }

    return 0;
}
