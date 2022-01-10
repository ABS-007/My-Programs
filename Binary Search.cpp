//ASHISH BIBYAN
//196301016
#include<iostream>
using namespace std;

int BSearch(int A[],int n,int key)
{
  int l=0,h=n-1,mid;
  while(l<h)
  { mid=(l+h)/2;
    if(key==A[mid])
    { cout<<"Key found at index: "<<mid<<endl;
      return 0;
    }
    else if(key>A[mid])
    l=mid+1;
    else
    h=mid-1;
  }
  cout<<"Key not found"<<endl;
  return -1;
}


int main()
{
  int n,key;
  cout<<"Enter the no. of Elements: "<<endl;
  cin>>n;
  int arr[n];
  cout<<"Enter the Elements: "<<endl;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  cout<<"Enter the Element to search: "<<endl;
  cin>>key;
  BSearch(arr,n,key);
}
