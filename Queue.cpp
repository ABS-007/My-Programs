#include<iostream>
using namespace std;

class Queue
{
private:
  int *A;
  int size;
  int rear;
  int front;
public:
    Queue(int size)
    {
      this->size=size;
      A=new int[size];
      front=rear=0;
    }
    void insert(int x)
    {
      if(front==(rear+1)%size)
        cout<<"Queue Full"<<endl;
      else
        { rear=(rear+1)%size;
          A[rear]=x;
        }
    }
    int del()
    { int x=0;
      if(front==rear)
        cout<<"Queue Empty"<<endl;
      else
        {
          front=(front+1)%size;
          x=A[front];
        }
      return x;
    }
    void display()
    {
      int i=front+1;

      do
      {
        cout<<A[i]<<" ";
        i=(i+1)%size;
      }while(i!=(rear+1)%size);
    }
};


class Stack{
private:
  int size;
  int Top;
  int *A;
public:
  Stack(int size)
  {
    this->size =size;
    Top=-1;
    A=new int[this->size];
  }

  void push(int x)
  {
    if(Top>=size-1)
    cout<<"Stack Full";
    else
    {
      Top++;
      A[Top]=x;
    }
  }

  int pop()
  { int x=-1;
    if(Top==-1) cout<<"Stack Empty"<<endl;
    else
    { x=A[Top];
      Top--;
    }
    return x;
  }

  int Stacktop()
  {return Top;}

};


int main()
{
  Stack s1(5);
  Stack s2(5);
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50);
  for(int i=s1.Stacktop();i>-1;i--)
    s2.push(s1.pop());
  for(int i=s2.Stacktop();i>-1;i--)
    cout<<s2.pop()<<" ";
}
