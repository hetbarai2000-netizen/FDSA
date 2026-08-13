#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no of items:";
    cin>>n;
    vector<int> items(n);
     cout << "Enter the bakery items: ";
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }
    int h;
    cout<<"Enter the no of hours:";
    cin>>h; 
    h=h%n;
     for (int i = h; i < n; i++) {
        cout << items[i] << " ";
    }
    for (int i = 0; i < h; i++) 
    {
        cout << items[i] << " ";
    }
    return 0;
}