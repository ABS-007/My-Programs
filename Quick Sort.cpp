#include<iostream>
using namespace std;

int partition(int arr[],int low,int high)
{
  int pivot=arr[low];
  int i=low,j=high;
  do{ do{i++;}while(arr[i]<=pivot);
      do{j--;}while(arr[j]>pivot);
      if(i<j)
      swap(arr[i],arr[j]);
  }while(i<j);
  swap(arr[low],arr[j]);
  return j;
}


void QuickSort(int arr[],int low,int high)
{
  int j;

  if(low<high)
  {
    j=partition(arr,low,high);
    QuickSort(arr,low,j);
    QuickSort(arr,j+1,high);
  }
}


int main()
{
  int A[5]={2,5,3,6,1};

  QuickSort(A,0,5);

  for(int i=0;i<5;i++)
  {
    cout<<A[i]<<" ";
  }

}
