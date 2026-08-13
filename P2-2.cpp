#include<iostream>
using namespace std;
void iterativeSearch(int book[], int n, int target)
    {
        int low = 0, high = n - 1, mid;
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            if(book[mid] == target)
            {
                cout << "Book ID found at position: " << mid + 1;
                return;
            }
            else if(book[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << "Book ID not found.";
    }
int recursiveBinarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return recursiveBinarySearch(arr, mid + 1, right, target);
    else
        return recursiveBinarySearch(arr, left, mid - 1, target);
}
int main()
{
    int n;
    cout<<"Enter the no of books:";
    cin>>n;
    int book[n];
    cout << "Enter the book IDs in sorted order: ";
    for(int i = 0; i < n; i++)
    {
        cin >> book[i];
    }
    int target;
    cout<<"Enter the book ID to search:";
    cin>>target;
     int low = 0, high = n - 1, mid;
    int choice;
    cout<<"Enter 1 for iterative search and 2 for recursive search:";
    cin>>choice;
    switch(choice)
    {
        case 1:
            iterativeSearch(book, n, target);
            break;
        case 2:
            int result = recursiveBinarySearch(book, 0, n - 1, target);
            break;
        default:
            cout << "Invalid choice.";
            break;
    }
    return 0;
}