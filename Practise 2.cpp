#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
public:
  Node *lchild;
  int data;
  Node *rchild;
};

class Btree
{
private:
  Node *root;
public:
  Btree();
  void create();
  void inorder(Node *p);
  void inorder(){inorder(root);}
  void preorder(Node *p);
  void preorder(){preorder(root);}
  void postorder(Node *p);
  void postorder(){postorder(root);}
  void levelorder(Node *p);
  void levelorder(){levelorder(root);}
  void make(int A[],int B[],int asize,int bsize);
};

Btree::Btree()
{ root=NULL;
}

void Btree::create()
{
  queue <Node*> q;                             //For storing addresses of node
  cout<<"Enter the value of root: "<<endl;
  root=new Node;
  cin>>root->data;
  root->lchild=root->rchild=NULL;
  q.push(root);
  Node *p=NULL,*temp=NULL;
  int x;
  while(!q.empty())
  { p=q.front();
    q.pop();
    cout<<"Enter the value of left child of "<<p->data<<" : "<<endl;
    cin>>x;
    if(x!=-1)
    {
      temp=new Node;
      temp->data=x;
      temp->lchild=temp->rchild=NULL;
      p->lchild=temp;
      q.push(temp);
    }
    cout<<"Enter the value of right child of "<<p->data<<" : "<<endl;
    cin>>x;
    if(x!=-1)
    {
      temp=new Node;
      temp->data=x;
      temp->lchild=temp->rchild=NULL;
      p->rchild=temp;
      q.push(temp);
    }
  }
}

void Btree::preorder(Node *p)
 { stack <Node *>st;
   while(p || !st.empty())
   {  if(p)
      {
        cout<<p->data<<", ";
        st.push(p);
        p=p->lchild;
      }
     else
     {
      p=st.top();
      st.pop();
      p=p->rchild;
     }
   }
 }

 void Btree::inorder(Node *p)
 {
   stack <Node *> st;

   while(p || !st.empty())
   {
     if(p)
     { st.push(p);
       p=p->lchild;
     }
     else
     {
       p=st.top();
       st.pop();
       cout<<p->data<<" ,";
       p=p->rchild;
     }
   }
 }

 void Btree::postorder(Node *p)
 {
   stack <long int> st;
   long int temp;
   while(p || !st.empty())
   {
     if(p)
     {
       st.push((long int)p);
       p=p->lchild;
     }
     else
     {
       temp=st.top();
       st.pop();
       if(temp>=0)
       {
        st.push(-temp);
        p=((Node*)temp)->rchild;
       }
       else
       {
         cout<<((Node*)(-1*temp))->data<<" ";
         p=NULL;
       }
     }
   }
 }

 void Btree::levelorder(Node *p)
 {
   queue<Node*>q;
   q.push(p);
   cout<<p->data<<" ";
   while(!q.empty())
   {  p=q.front();
      q.pop();
     if(p->lchild)
     {
       cout<<p->lchild->data<<" ";
       q.push(p->lchild);
     }
     if(p->rchild)
     {
       cout<<p->rchild->data<<" ";
       q.push(p->rchild);
     }
   }
 }

 void Btree::make(int A[],int B[],int asize,int bsize)
 { int x=0;
   int *a,*b;
   Node *temp=NULL;
   Node *p=new Node;
   p->data=B[0];
   p->lchild=p->rchild=NULL;
   root=p;
   for(int i=0;i<bsize;i++)
   {
     for(int j=0;j<asize;j++)
     {
       if(b[i]==a[j] && x<j)
       {
         x=j;
         temp=new Node;
         temp->data=x;
         temp->lchild=temp->rchild=NULL;
         p->lchild=temp;
       }
       else if(b[i]==a[j] && x>j)
       {
         x=j;
         temp=new Node;
         temp->data=x;
         temp->lchild=temp->rchild=NULL;
         p->rchild=temp;
       }

     }
   }


 }

int main()
{ int A[9]={4,7,9,6,3,2,5,8,1};
  int B[9]={7,6,9,3,4,5,8,2,1};
  Btree D;
  D.make(A,B,9,9);

  D.preorder();
}
