#include<iostream>
using namespace std;

void Heapify(int arr[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
      int j=2*i+1;
        while(j<n-1)
        {
          if(arr[j]<arr[j+1])
            j=j+1;

        if(arr[i]<arr[j])
          {
            swap(arr[i],arr[j]);
            i=j;
            j=i*2+1;
          }
        else
         break;
       }
    }
}

void del(int arr[],int n)
{
  int i=0,j=2*i+1,x;
  x=arr[0];
  arr[0]=arr[n-1];
  while(j<n-1)
  {  if(arr[j]<arr[j+1])
        j=j+1;
      if(arr[i]<arr[j])
        {
          swap(arr[i],arr[j]);
          i=j;
          j=2*i+1;
        }
      else
        break;
    }
  arr[n-1]=x;
}

void display(int arr[],int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int H[7]={5,10,30,20,35,40,15};
  Heapify(H,7);
  display(H,7);
  int n=7;
  for(int i=7;i>0;i--)
    {del(H,i);}
  display(H,7);
}
