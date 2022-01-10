#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};

class CLL{
private:
  Node *Head;
public:
  CLL()
  { Head=new Node;
    Head->next=Head;
  }
  CLL(int *A,int n)
  {
    Head=new Node;
    Head->data=A[0];
    Head->next=Head;
    Node *temp,*last;
    last=Head;
    for(int i=1;i<n;i++)
    {
      temp=new Node;
      temp->data=A[i];
      temp->next=last->next;

      last->next=temp;
      last=temp;
    }
  }

  Node * getHead()
  {
    return Head;
  }

  int count()
  { Node *p=Head;
    int count=0;
    do{
      count++;
      p=p->next;
    }while(p!=Head);
    return count;
  }

  void display()
  {
    Node *p;
    p=Head;
    do
    {
      cout<<p->data<<" ";
      p=p->next;
    }while(p && p!=Head);
    cout<<endl;
  }

  void Rdisplay(Node *p)
  {   static int flag=0;
     if(p!=Head || flag==0 )
      { flag=1;
        cout<<p->data<<" ";
        Rdisplay(p->next);}
    flag=0;
  }

  void insert(int pos,int x)
  { Node *t;
    Node *p=Head;
    if(pos==0)
    { t=new Node;
      t->data=x;
      if(Head==NULL)
      {
        Head=t;
        Head->next=Head;
      }
      else
      {
        while(p->next!=Head) p=p->next;
        p->next=t;
        t->next=Head;
        Head=t;
      }
    }
    else
    {  t=new Node;
       t->data=x;
      for(int i=0;i<pos-1;i++) p=p->next;
      t->next=p->next;
      p->next=t;
    }
  }

  int del(int pos)
  { Node *p=Head,*q;
    int i,x;
    if(0>=pos || pos>count()) return -1;
    else
    {
      if(pos==1)
      {
        while(p->next!=Head) p=p->next;
        p->next=Head->next;
        { if(Head==p)
          {
            x=Head->data;
            delete Head;
            Head=NULL;
          }
          else
          {
          x=Head->data;
          delete Head;
          Head=p->next;
          }
        }
      }
      else
      {
        for(i=0;i<pos-2;i++) p=p->next;
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
        q=NULL;
      }
    }
    return x;
  }
};

int main()
{ int A[]={100,200,300,400,500,600};
  CLL C(A,6);
  cout<<C.count()<<endl;
  C.insert(4,2000);
  cout<<C.del(1)<<endl;

  C.display();
}
