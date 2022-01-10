#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
} *Head2=NULL;

Node *Head=NULL;


void insert(int pos,int x)
{
  Node *t,*p;

  if(pos==0)
  { t=new Node;
    t->data=x;
    t->next=Head;
    Head=t;
  }
  else if(pos>0)
  {
    p=Head;
    for(int i=0;i<pos-1;i++)
    {p=p->next;}
    if(p)
    {
    t=new Node;
    t->data=x;
    t->next=p->next;
    p->next=t;
    }
  }
}

void insert2(int pos,int x)
{
  Node *t,*p;

  if(pos==0)
  { t=new Node;
    t->data=x;
    t->next=Head2;
    Head2=t;
  }
  else if(pos>0)
  {
    p=Head2;
    for(int i=0;i<pos-1;i++)
    {p=p->next;}
    if(p)
    {
    t=new Node;
    t->data=x;
    t->next=p->next;
    p->next=t;
    }
  }
}


void create(int A[],int n)
{ for(int i=0;i<n;i++)
  insert(i,A[i]);
}

void create2(int B[],int n)
{ for(int i=0;i<n;i++)
  insert2(i,B[i]);
}


int count(Node *p)
{ int count=0;
  while(p)
  {
    p=p->next;
    count++;
  }
  return count;
}

int Rcount(Node *p)
{
  if(p!=0)
  return Rcount(p->next)+1;
  else
  return 0;
}


void display(Node *p)
{
  while(p!=0)
  {
    cout<<p->data<<" ";
    p=p->next;
  }
  cout<<endl;
}



int max(Node *p)
{ int m=0;
  while(p)
  {
  if(m<p->data)
  {
  m=p->data;
  p=p->next;
  }
  else
   p=p->next;
  }
  return m;
}

int Rmax(Node *p)
{ int x;
  if(p==0)
  return x;
  x=Rmax(p->next);
  if(p->data>x)
  return p->data;
  else return x;
}

Node * Lsearch(Node *p,int key)
{
  Node *q;
   while(p)
  {
    if(p->data==key)
    {
      q->next=p->next;
      p->next=Head;
      Head=p;

      return p;
    }
    q=p;
    p=p->next;
  }
  return NULL;
}

Node * RLsearch(Node *p,int key)
{ if(p==0)
  return nullptr;
  else if(p->data==key)
  return p;
  else
  return RLsearch(p->next,key);
}


void Sortedinsert(Node *p,int x)
{
  Node *t,*q=NULL;
  t=new Node;
  t->data=x;
  t->next=NULL;

  if(Head==NULL)
    Head=t;
  else
    {
      while(p && p->data<x)
      { q=p;
        p=p->next;
      }

      if(p==Head)
      { t->next=Head;
        Head=t;
      }
      else
      {
        t->next=q->next;
        q->next=t;
      }
    }
}

int delet(Node *p,int pos)
{
  Node *q=NULL;
  int x=-1,i;
  if(pos==1)
  {
    p=Head;
    Head=Head->next;
    x=p->data;
    delete p;
  }
  else
  {
    for(i=0;i<pos-1 && p;i++)
    { q=p;
      p=p->next;
    }
    if(p)
    {
      q->next=p->next;
      x=p->data;
      delete p;
    }
    }
    return x;
}

int issorted(Node *p)
{
  int x=0;
  for(int i=0;i<count(p) && p;i++)
  {
    if(x<p->data)
    {x=p->data;
    p=p->next;}
    else
    return -1;
  }
  return 0;
}

void dupli(Node *p)
{
  Node *q;
  q=Head->next;

  while(q)
  {
    if(p->data!=q->data)
      {p=q;
      q=q->next;}
    else
     p->next=q->next;
     delete q;
     q=p->next;
  }

}

void Reverse(struct Node *p)
{ struct Node *q=p;
  int i=0;
  int A[6];
  while(q)
  {
    A[i]=q->data;
    q=q->next;
    i++;
  }
  q=p;
  i--;
  while(q)
  {
    q->data=A[i];
    q=q->next;
    i--;
  }
}

void Reverse2(struct Node *p)
{
  struct Node *q=NULL,*r=NULL;
  while(p)
  {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  Head=q;
}

void Reverse3(Node *q,Node *p)
{
  if(p)
  {
    Reverse3(p,p->next);
    p->next=q;
  }
  else
  Head=q;
}


Node * Merge(Node *p,Node *q)
{
  Node *third;
  Node *last;

  if(p->data<=q->data)
  {
    third=last=p;
    p=p->next;
    last=NULL;
  }
  else
  {
    third=last=q;
    q=q->next;
    last->next=NULL;
  }

  while(p && q)
  {
    if(p->data<=q->data)
    {
      last->next=p;
      last=p;
      p=p->next;
      last->next=NULL;
    }
    if(p->data>q->data)
    {
      last->next=q;
      last=q;
      q=q->next;
      last->next=NULL;
    }
  }
  if(p)
  {
    last->next=p;
    last=NULL;}
  else
  {
    last->next=q;
    last=NULL;
  }
  return third;
}

int isLoop(Node *Head)
{
  Node *p=NULL,*q=NULL;
  q=p=Head;
  do
  {
    p=p->next;
    q=q->next;
    q=q?q->next:q;
  }while(p && q && p!=q);
  if(p==q)
  return 1;
  else
  return-1;
}

int main()
{
  int A[]={10,30,40,50,60};
  create(A,6);
  Node *p=Head;
  Node *p1,*p2;
  //  p1=Head->next->next;
  //  p2=Head->next->next->next->next->next;
  //  p2->next=p1;
  cout<<isLoop(Head);
  return 0;
}
