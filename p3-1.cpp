#include<iostream>
using namespace std;

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
   cout<<"Your sorted marks are"<<endl;
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int n;
    cout<<"How many sheets  do you have? : "<<endl;
    cin>>n;

    int arr[n];
     cout<<"Enter marks of sheet:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
     selectionSort(arr,n);

     return 0;

}