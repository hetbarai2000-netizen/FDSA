#include<iostream>
using namespace std;
void iterativeSearch(int lplates[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(lplates[i]==target)
        {
            cout<<"License plate found at position: "<<i+1;
            return;
        }
    }
    cout<<"License plate not found.";
}
void recursiveSearch(int lplates[],int target,int n)
{
    if(n<0)
    {
        cout<<"License plate not found.";
        return;
    }
    if(lplates[n]==target)
    {
        cout<<"License plate found at position: "<<n+1;
        return;
    }
    recursiveSearch(lplates,target,n-1);
}
int main()
{
    int n;
    cout<<"Enter the no of license plates:";
    cin>>n;
    int lplates[n];
    cout<<"Enter the plates:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>lplates[i];
    }
    int target;
    cout<<"Enter the license plate to search:";
    cin>>target;
    iterativeSearch(lplates, n, target);
    cout << endl;
    recursiveSearch(lplates, target, n - 1);

    return 0;
}