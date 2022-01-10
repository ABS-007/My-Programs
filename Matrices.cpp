#include<iostream>
using namespace std;

class Node
{public:
  int data;
  int column;
  Node *next;
};

class Sparse{

public:
  Sparse(int n)
  {
    Node *B[n],*temp, *p;
    Node *last;
    int r,c,x,y;
    for(int i=0;i<n;i++)
    { B[i]=new Node;
      B[i]->data=i+1;
      B[i]->next=NULL;
    }
    cout<<"No. of non zero Elements: "<<endl;
    cin>>x;
    for(int i=0;i<x;i++)
    { cout<<"Row No. ,Column No. and element: "<<endl;
      cin>>r>>c>>y;
      last=B[r-1];
      while(last->next!=NULL)
      {last=last->next;}
      temp=new Node;
      temp->data=y;
      temp->column=c;
      temp->next=NULL;
      last->next=temp;
    }
    cout<<B[1]->next->data;
    cout<<"program finished"<<endl;

    for(int i=0;i<n;i++)
    { p=B[i];
      for(int j=0;j<n;j++)
      {
        if(j==p->column)
        {
          cout<<p->data<<" ";
          p=p->next;
        }
        else
        cout<<"0 ";
      }
      cout<<endl;
    }
}
};


int main()
{
  Sparse A(3);

}
