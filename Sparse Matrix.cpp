#include<iostream>
using namespace std;

class Element{
public:
  int i;
  int j;
  int x;
};

class Sparse{
private:
  int m;
  int n;
  int num;
  Element *ele;
public:
  Sparse(int m,int n,int num)
  {
    this->m=m;
    this->n=n;
    this->num=num;
    ele=new Element[this->num];
  }

  friend istream & operator>>(istream &is,Sparse &s);
  friend ostream & operator<<(ostream &os,Sparse &s);

  ~Sparse()
  {
    delete [] ele;
  }

};

istream & operator>>(istream &is,Sparse &s)
{
  cout<<"Enter the Row, Column, element: "<<endl;
  for(int i=1;i<=s.num;i++)
  {cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;}
  return is;
}

ostream & operator<<(ostream &os,Sparse &s)
{
  cout<<"Matrix is: "<<endl;
  int k=1;
  for(int i=1;i<=s.m;i++)
  {
    for(int j=1;j<=s.n;j++)
    {
      if(i==s.ele[i].i && j==s.ele[i].j)
        cout<<s.ele[i].x<<" ";
      else
        cout<<"0 ";
    }
    cout<<endl;
  }
  return os;
}


int main()
{
  Sparse s1(3,3,3);
  cin>>s1;
  cout<<s1;
}
