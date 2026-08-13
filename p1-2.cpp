#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of borrow records: ";
    cin >> n;

    int book[100];

    cout << "Enter book IDs:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> book[i];
    }

    cout << "Books borrowed more than once are:"<<endl;

    bool found = false;

    for(int i = 0; i < n; i++)
    {
        int count = 1;

        for(int j = i + 1; j < n; j++)
        {
            if(book[i] == book[j])
            {
                count++;
            }
        }

        bool printed = false;
        for(int k = 0; k < i; k++)
        {
            if(book[k] == book[i])
            {
                printed = true;
                break;
            }
        }

        if(count > 1 && !printed)
        {
            cout << book[i] << " ";
            found = true;
        }
    }

    if(!found)
    {
        cout << "No duplicate book IDs found.";
    }

    return 0;
}