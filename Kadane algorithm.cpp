#include<iostream>
#include<stdio.h>
using namespace std;


int maxsubarraysum(int arr[],int n)
{
  int lastsum=-2147483647,currentsum=0;

  for(int i=0;i<n;i++)
  { currentsum+=arr[i];
    if(currentsum>lastsum)
    lastsum=currentsum;
    if(currentsum<0)
    currentsum=0;
  }
 return lastsum;
}

int main()
{
  int size;
  cout<<"Enter the size of array "<<endl;
  cin>>size;
  int arr[size];
  cout<<" Enter the elements of array"<<endl;
  for(int i=0;i<size;i++)
  cin>>arr[i];
  cout<<"sum of Subarray with max sum is "<<maxsubarraysum(arr,size)<<endl;
  return 0;
}
