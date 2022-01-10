#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
};



class Llist{
private:
  Node *Head=NULL;
public:
  Llist(int A[],int size)
  { Node *t,*last;
    Head=new Node;
    Head->data=A[0];
    Head->next=NULL;
    last=Head;
    for(int i=1;i<size;i++)
    {
      t=new Node;
      t->data=A[i];
      t->next=NULL;
      last->next=t;
      last=t;
    }
  }

  void Reverse()
  {
    Node *p,*q,*r;
    p=Head;
    r=q=NULL;
    while(p)
    { r=q;
      q=p;
      p=p->next;
      q->next=r;
    }
    Head=q;
  }

  void display()
  { Node *p=Head;
    while(p)
    {
      cout<<p->data<<" ";
      p=p->next;
    }

  }
};


int main()
{
  int A[5]={1,10000000,36,4,5};
  Llist list(A,5);
  list.display();
  cout<<endl;
  list.Reverse();
  cout<<endl;
  list.display();
}
