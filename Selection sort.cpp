//ASHISH BIBYAN
//196301016
#include<iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min])
            min = j;

        swap(arr[min], arr[i]);
    }
}

int main()
{
  int n;
  cout<<"Enter the no. of Elements: "<<endl;
  cin>>n;
  int arr[n];
  cout<<"Enter the Elements: "<<endl;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  selectionSort(arr,n);
  cout<<"Sorted Array: "<<endl;
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
