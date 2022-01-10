#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
public:
  Node *lchild;
  int data;
  int Nodeheight;
  Node *rchild;
};

class Btree{
private:
  Node *root=NULL;
public:
  void create();
  void precreate(int pre[],int n);
  void display(){display(root);}
  void setroot(Node *p){root=p;}
  Node* getroot(){return root;}
  void insert(int key);
  void display(Node *p);
  Node* rinsert(Node *p,int key);
  void del(int key){del(root,key);}
  Node* del(Node *p,int key);
  int Height(Node *p);
  int Balancefactor(Node *p);
  Node*Inpre(Node *p);
  Node*Insucc(Node *p);
  Node* LLrotation(Node *p);
  Node* RRrotation(Node *p);
  Node* LRrotation(Node *p);
  Node* RLrotation(Node *p);

};


void Btree::create()
{ int x;
  Node *temp,*p;
  queue <Node *> q;
  cout<<"Enter the value of root: "<<endl;
  cin>>x;
  root=new Node;
  root->data=x;
  root->lchild=root->rchild=NULL;
  p=root;
  q.push(p);
  while(!q.empty())
  { p=q.front();
    q.pop();
    cout<<"Enter the value of lchild "<<p->data<<": "<<endl;
    cin>>x;
    if(x!=-1)
    {
      temp=new Node;
      temp->data=x;
      temp->rchild=temp->lchild=NULL;
      p->lchild=temp;
      q.push(p->lchild);
    }
    cout<<"Enter the value of rchild "<<p->data<<": "<<endl;
    cin>>x;
    if(x!=-1)
    {
      temp=new Node;
      temp->data=x;
      temp->rchild=temp->lchild=NULL;
      p->rchild=temp;
      q.push(p->rchild);
    }
}
}

void Btree::precreate(int pre[],int n)
{
  Node *p,*t=NULL;
  int i=0;
  stack<Node *> st;
  root=new Node;
  root->data=pre[i++];
  root->lchild=root->rchild=NULL;
  p=root;

  while(i<n)
  {
    if(pre[i] < p->data)
    {
      t=new Node;
      t->data=pre[i++];
      t->lchild=t->rchild=NULL;
      p->lchild=t;
      st.push(p);
      p=t;
    }
    else
    {
      if(p->data<pre[i] && pre[i]<st.top()->data)
      {
        t=new Node;
        t->data=pre[i++];
        t->lchild=t->rchild=NULL;
        p->rchild=t;
        p=t;
      }
      else
       {
         p=st.top();
         st.pop();
       }
    }
  }
}

void Btree::display(Node *p)
{ if(p)
  {
    display(p->lchild);
    cout<<p->data<<" ";
    display(p->rchild);
  }
}

void Btree::insert(int key)
{
  Node *p=root,*q=NULL,*t;
  if(p==NULL)
  {
    p=new Node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    root=p;
  }
  else
  {
  while(p)
  { q=p;
    if(p->data>key) p=p->lchild;
    else if(p->data<key) p=p->rchild;
  }

  t=new Node;
  t->data=key;
  t->lchild=t->rchild=NULL;

  if(q->data>key) q->lchild=t;
  else if(q->data<key) q->rchild=t;
  cout<<"Key inserted"<<endl;
  }
}

Node* Btree::rinsert(Node *p,int key)
{
  if(p==NULL)
  {
    p=new Node;
    p->data=key;
    p->Nodeheight=1;
    p->lchild=p->rchild=NULL;
    return p;
  }

  if(key<p->data) p->lchild=rinsert(p->lchild,key);
  else if(key>p->data) p->rchild=rinsert(p->rchild,key);
  p->Nodeheight=Height(p);
  if(Balancefactor(p)==2 && Balancefactor(p->lchild)==1)
   LLrotation(p);
  else if(Balancefactor(p)==-2 && Balancefactor(p->rchild)==-1)
   RRrotation(p);
  else if(Balancefactor(p)==2 && Balancefactor(p->lchild)==-1)
   LRrotation(p);
  else if(Balancefactor(p)==-2 && Balancefactor(p->rchild)==1)
   RLrotation(p);
  cout<<"Key inserted"<<endl;
  return p;
}

int Btree::Height(Node *p)
{
  int x,y;
  if(p==NULL)
   return 0;
  else
  {
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
  }
}

int Btree::Balancefactor(Node *p)
{
  return Height(p->lchild)-Height(p->rchild);
}

Node *Btree::Inpre(Node *p)
{
  while(p && p->rchild)
  {
    p=p->rchild;
  }
  return p;
}

Node * Btree::Insucc(Node *p)
{
  while(p && p->lchild)
  {
    p=p->lchild;
  }
  return p;
}

Node * Btree::del(Node* p,int key)
{ Node *q;
  if(p==NULL)
  return NULL;
  if(p->lchild==NULL && p->rchild==NULL)
  {
    if(p==root)
    {
      root=NULL;
      delete p;
    }
    return NULL;
  }

  if(key<p->data) p->lchild=del(p->lchild,key);
  else if(key>p->data) p->rchild=del(p->rchild,key);
  else
  {
    if(Height(p->lchild)>=Height(p->rchild))
    {
      q=Inpre(p->lchild);
      p->data=q->data;
      p->lchild=del(p->lchild,q->data);
    }
    else if(Height(p->lchild)<Height(p->rchild))
    {
      q=Insucc(p->rchild);
      p->data=q->data;
      p->rchild=del(p->rchild,q->data);
    }
  }
  return p;
}

Node* Btree::LLrotation(Node* p)
{
  Node *q=NULL;
    q=p->lchild;
    if(q!=NULL)
    {
    p->lchild=q->rchild;
    q->rchild=p;
    p->Nodeheight=Height(p);
    q->Nodeheight=Height(p);
    if(root==p)
      root=q;
    }
    return q;
}

Node* Btree::RRrotation(Node* p)
{
  Node *q=p->rchild;
  if(q==NULL)
  return NULL;
  else
  {
  p->rchild=q->lchild;
  q->lchild=p;
  p->Nodeheight=Height(p);
  q->Nodeheight=Height(q);
  if(root==p)
    root=q;
  }
  q=NULL;
  delete q;
  return q;
}

Node* Btree::LRrotation(Node* p)
{
  Node *q=p->lchild,*r=p->lchild->rchild;

  p->lchild=r->rchild;
  q->rchild=r->lchild;
  r->lchild=q;
  r->rchild=p;
  p->Nodeheight=Height(p);
  q->Nodeheight=Height(q);
  q->Nodeheight=Height(q);
  if(root==p)
    root=r;
  q=r=NULL;
  delete q,r;
  return r;
}

Node* Btree::RLrotation(Node* p)
{
  Node *q=p->rchild,*r=p->rchild->lchild;

  p->rchild=r->lchild;
  q->lchild=r->rchild;
  r->lchild=p;
  r->rchild=q;
  r->Nodeheight=Height(r);
  p->Nodeheight=Height(p);
  q->Nodeheight=Height(q);
  if(root==p)
    root=r;
  q=r=NULL;
  delete q,r;
  return p;
}
int main()
{ Btree B;
  B.setroot(B.rinsert(B.getroot(),10));
  B.rinsert(B.getroot(),30);
  B.rinsert(B.getroot(),20);
  B.display();
}
