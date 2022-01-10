#include<iostream>
using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;
public:
  void create(int size,int length)
  {
    this->size=size;
    A=new int[size];
    this->length=length;
  }

  void fill()
  { cout<<"Enter the elements"<<endl;
    for(int i=0;i<length;i++)
    {
      cin>>A[i];
    }
  }

  void display()
  {
      for(int i=0;i<length;i++)
    {
      cout<<"Element "<<i+1<<": "<<A[i]<<endl;
    }
  }

  int ADD(int x)
  {
    A[length++]=x;
    return x;
  }

  int Insert(int index,int x)
  { if(index>=0 && index<=length)
    {for(int i=length;i>index;i--)
    {
      A[i]=A[i-1];
    }
    A[index]=x;
    length++;
    return x;
  }
  return -1;
}

  int del(int index)
  {
      if(index>=0 && index<length)
      {
        int x=A[index];
        for(int i=index;i<length-1;i++)
        {
          A[i]=A[i+1];
        }
        length--;
        return x;
      }
      return -1;
  }

  int LSearch(int key)
  {
   for(int i=0;i<length;i++)
   {
     if(A[i]==key)
     return i;
   }
   return -1;
  }

  int BSearch(int key)
  {
    int l=0,h=length,mid;
    while(l<h)
    {
      mid=(l+h)/2;
      if(A[mid]==key)
       return mid;
      else if(A[mid]<key)
       h=mid-1;
       else
       l=mid+1;
    }
    return -1;
  }

  int Get(int index)
  {
    if(0<=index && index,length)
      return A[index];
      return -1;
  }

  void Set(int index,int x)
  {
    if(0<=index && index<length)
      A[index]=x;
  }

  int Max()
  {
     int max=A[0];
    for(int i=1;i<length;i++)
    {Array arr;
  arr.create(10,5);
  arr.display();
  cout<<endl;
  arr.ADD(10);
  arr.display();
  cout<<endl;
  arr.Insert(4,50);
  arr.display();
  cout<<endl;
  arr.del(3);
  arr.display();
  cout<<endl;
  cout<<"Search Results: "<<endl;
  cout<<arr.LSearch(50)<<endl;
  cout<<arr.BSearch(50)<<endl;
  cout<<"Sum ="<<arr.Sum()<<endl;
  cout<<"Average is ="<<arr.Avg()<<endl;
      if(max<A[i])
        max=A[i];
    }
    return max;
  }

  int Min()
  {
    int min=A[0];
    for(int i=1;i<length;i++)
    {
      if(A[i]<min)
      min=A[i];
    }
    return min;Array arr;
  arr.create(10,5);
  arr.display();
  cout<<endl;
  arr.ADD(10);
  arr.display();
  cout<<endl;
  arr.Insert(4,50);
  arr.display();
  cout<<endl;
  arr.del(3);
  arr.display();
  cout<<endl;
  cout<<"Search Results: "<<endl;
  cout<<arr.LSearch(50)<<endl;
  cout<<arr.BSearch(50)<<endl;
  cout<<"Sum ="<<arr.Sum()<<endl;
  cout<<"Average is ="<<arr.Avg()<<endl;
  }

  int Sum()
  {
    int sum=0;
    for(int i=0;i<length;i++)
    {
      sum+=A[i];
    }
    return sum;
  }

  float Avg()
  {
    return (float)Sum()/length;
  }

  Array merge(Array &B)
  {
    Array C;
    C.create(size+B.size,length +B.length);
        int i=0,j=0,k=0;    //initial index
        while(i<length && j<B.length)
        {
          if(A[i]<B.Get(j))
            {C.Set(k++,A[i++]);}
          else
            {C.Set(k++,B.Get(j++));}
        }
            while(i<length)
            {
              C.Set(k++,A[i++]);
            }
            while(j<B.length)
            {
              C.Set(k++,B.Get(j++));
            }

        return C;
  }

  Array Union(Array &B)
  {
    Array C;
    C.create(length+B.length,size+B.size);
    int i=0,j=0,k=0;
    while(i<length && j<B.length)
    {
      if(A[i]==B.Get(j))
        {C.Set(k++,A[i++]);
        j++;}
      else if(A[i]<B.Get(j))
        {C.Set(k++,A[i++]);}
      else
        {C.Set(k++,B.Get(j++));}
    }

    while(i<length)
    {C.Set(k++,A[i]);}
    while(j<B.length)
    {C.Set(k++,B.Get(j++));}
    return C;
  }


};

int main()
{ Array A;
  int s,l,ch,index,value;
  cout<<"Enter the size and length of the array: "<<endl;
  cin>>s>>l;
  A.create(s,l);

do{
  cout<<endl<<endl<<endl;
  cout<<"Menu"<<endl;
  cout<<endl;
  cout<<"1.Fill"<<endl;
  cout<<"2.Insert"<<endl;
  cout<<"3.Delete"<<endl;
  cout<<"4.Search"<<endl;
  cout<<"5.Min"<<endl;
  cout<<"6.Max"<<endl;
  cout<<"7.Get"<<endl;
  cout<<"8.Set"<<endl;
  cout<<"9.Display"<<endl;
  cout<<"Enter your choice: "<<endl;
  cout<<endl;
  cin>>ch;

  switch(ch)
  {
    case 1:
      cout<<"To fill the complete Array"<<endl;
      A.fill();
      cout<<"Array has filled"<<endl;
      break;
    case 2:
      cout<<"To insert an element "<<endl;
      cout<<"Index =";
      cin>>index;
      cout<<"Value =";
      cin>>value;
      A.Insert(index,value);
      break;
    case 3:
      cout<<"To delete an element at index= "<<endl;
      cin>>index;
      cout<<"Deleted element is"<<A.del(index);
      break;
    case 4:
      cout<<"Enter the key to search:"<<endl;
      cin>>value;
      cout<<"Key found at "<<A.BSearch(value)<<endl;
      break;
    case 5:
      cout<<"Minimum value in the array is: "<<A.Min()<<endl;
      break;
    case 6:
      cout<<"Maximum value in the array is: "<<A.Max()<<endl;
      break;
    case 7:
      cout<<"Index of the element you want to get: "<<endl;
      cin>>index;
      cout<<"Value at index"<<index<<" is: "<<A.Get(index)<<endl;
      break;
    case 8:
      cout<<"To set a value at index="<<endl;
      cin>>index;
      cout<<"Value="<<endl;
      cin>>value;
      A.Set(index,value);
      cout<<"Value set"<<endl;
      break;
    case 9:
      cout<<"Elements are as follows: "<<endl;
      A.display();
      break;


  }
}while(ch<10);
  return 0;
}
