#include<iostream>
using namespace std;

class Node{
public:
  Node *prev;
  int data;
  Node *next;
};

class Double
{
private:
  Node *Head;
public:
  Double(int A[],int n)
  {
    Node *t,*last;
    Head =new Node;
    Head->prev=Head->next=NULL;
    Head->data=A[0];
    last=Head;
    for(int i=1;i<n;i++)
    {
      t=new Node;
      t->data=A[i];
      last->next=t;
      t->prev=last;
      last=t;
    }
  }

  void display()
  {
    Node *p=Head;
   while(p)
   {
     cout<<p->data<<" ";
     p=p->next;
   }
  }

  int length()
  { Node *p;
    int count=0;
    while(p)
    { count++;
      p=p->next;
    }
    return count;
  }

  void insert(int pos,int x)
  {
    Node *p=Head,*t;
        t=new Node;
        t->next=t->prev=NULL;
        t->data=x;
        if(pos==0)
        {
          if(Head==NULL)
          Head=t;
          else
          {
            t->next=Head;
            Head->prev=t;
            Head=t;
          }
        }
        else
        {
          for(int i=0;i<pos-1;i++)
          p=p->next;
          t->next=p->next;
          t->prev=p;
          if(p->next)
            p->next->prev=t;
          p->next=t;
        }
  }


  int del(int pos)
  {
    Node *p=Head;
    int x,i;
    if(pos==0)
    {
      Head=Head->next;
      x=p->data;
      delete p;
      if(Head)
        Head->prev=NULL;
    }
    else
    {
      for(i=0;i<pos-1;i++)
      p=p->next;
      p->prev->next=p->next;
      if(p->next)
      p->next->prev=p->prev;
      x=p->data;
      delete p;
    }
    return x;
  }

  void reverse()
  {
    Node *p=Head,*temp;
    while(p)
    {
      temp=p->next;
      p->next=p->prev;
      p->prev=temp;
      p=p->prev;
      if(p && p->next==NULL)
        Head=p;
    }
  }
};


int main()
{
  int A[5]={10,20,30,40,50};
  Double D(A,5);
  D.reverse();
  D.display();

}
