
#include<iostream>
using namespace std;

void Isort(int *arr,int n)
{ int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
  Isort(arr,n);
  cout<<"Sorted Array: "<<endl;
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
}
