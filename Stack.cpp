#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

class StackL{
private:
  Node *Top=NULL;
public:
  void push(int x);
  int pop();
  void display();
  int peek(int pos);
};

void StackL::push(int x)
{
  Node *t=new Node;
  if(t==NULL)
    cout<<"stack overflow"<<endl;
  else
    {
      t->data=x;
      t->next=Top;
      Top=t;
    }
}
int StackL::pop()
{ int x=-1;
  Node *t=Top;
  if(t==NULL)
    return x;
  else
    {
      Top=Top->next;
      x=t->data;
      delete t;
      return x;
    }
}
void StackL::display()
{
  Node *p=Top;
  while(p)
  {
    cout<<p->data<<" ";
    p=p->next;
  }
}
int StackL::peek(int pos)
{
  int i;
  Node *p=Top;
  for(i=0;p && i<pos-1;i++)
  p=p->next;
  if(p!=NULL)
    return p->data;
  return -1;
}

class Stack{
private:
  int Top;
  int *A;
  int size;
public:
  Stack(int size)
  {
    this->size=size;
    A=new int[size];
    Top=-1;
  }

  void push(int x);
  int pop();
  void display();
  int peek(int pos);
  bool isFull();
  bool isEmpty();

};

void Stack::push(int x)
{
    if(Top==size-1)
    cout<<"Stack overflow "<<endl;
    else
    {
      Top++;
      A[Top]=x;
    }
}

int Stack::pop()
{ int x=-1;
  if(Top==-1)
  {
    cout<<"Stack Underflow "<<endl;
    return x;
  }
  else
  {
    x=A[Top-1];
    Top--;
    return x;
  }
}

void Stack::display()
{
  for(int i=Top;i>-1;i--)
  {
    cout<<A[i]<<" ";
  }
}

int Stack::peek(int pos)
{ if(Top-pos+1<0)
  return -1;
  else
  return A[Top-pos+1];
}

bool Stack::isFull()
{
  if(Top==size-1)
    return 1;
  else
    return 0;
}

bool Stack::isEmpty()
{
  if(Top==-1)
  return 1;
  else
  return 0;
}


int main()
{
  StackL s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.pop();
  cout<<s.peek(3)<<endl;
  s.display();
}
