#include<iostream>
using namespace std;

struct Array
{
  int *A;
  int size;
  int length;
};

void create(struct Array *arr,int x,int y)
{
  arr->size=x;
  arr->length=y;
  arr->A=new int[arr->size];
}

void insert(struct Array *arr)
{
  for(int i=0;i<arr->length;i++)
  {
    cin>>arr->A[i];
  }
}

void display(struct Array arr)
{ cout<<"Elements are: "<<endl;
  for(int i=0;i<arr.length;i++)
  {
    cout<<arr.A[i]<<endl;
  }
}

void swap(int *x,int *y)
{ int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}

void Sorted(struct Array arr)
{
  int i=0;
  for(int i=0;i<arr.length-1;i++)
  {
    if(arr.A[i]>arr.A[i+1])
    cout<<"list is not Sorted"<<endl;
  }
    cout<<"list is sorted"<<endl;
}

void nsort(struct Array *arr)
{
  int i=0,j=arr->length-1;
  while(i<j)
  {
    while(arr->A[i]<0){i++;}
    while(arr->A[j]>=0){j--;}
    if(i<j)
    {swap(&arr->A[i],&arr->A[j]);
    }
  }
}

int main()
{
  Array arr;
  create(&arr,10,5);
  insert(&arr);
  nsort(&arr);
  display(arr);
}
