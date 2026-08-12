#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of borrow records: ";
    cin >> n;

    int books[n];

    cout << "Enter book IDs: ";
    for (int i = 0; i < n; i++)
    {
        cin >> books[i];
    }

    cout << "Book IDs borrowed more than once are: ";

    for (int i = 0; i < n; i++)
    {
        int count = 1;


        bool alreadyPrinted = false;

        for (int k = 0; k < i; k++)
        {
            if (books[i] == books[k])
            {
                alreadyPrinted = true;
                break;
            }
        }

        if (alreadyPrinted)
        {
            continue;
        }


        for (int j = i + 1; j < n; j++)
        {
            if (books[i] == books[j])
            {
                count++;
            }
        }

        if (count > 1)
        {
            cout << books[i] << " ";
        }
    }

    return 0;
}
