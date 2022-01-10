#include<iostream>
#include<math.h>
using namespace std;

class Element{
public:
  int coe;
  int exp;
};


class Poly{
private:
  int num;
  Element *ele;
public:
  Poly()
  {this->num=10;
    ele=new Element[num];}
  Poly(int num)
  {
    this->num=num;
    ele=new Element[num];
  }
    Poly add(Poly &p2)
  { int i,j,k;
    i=j=k=0;
    Poly *p3;
    p3=new Poly(num+p2.num);
    while(i<num && j<p2.num)
    {

      if(ele[i].exp>p2.ele[j].exp)
      p3->ele[k++]=ele[i++];
      else if(ele[i].exp<p2.ele[j].exp)
      p3->ele[k++]=p2.ele[j++];
        else if(ele[i].exp==p2.ele[j].exp)
        {p3->ele[k].coe=ele[i].coe+p2.ele[j++].coe;
          p3->ele[k++].exp=ele[i++].exp;
        }
    }
    for(;i<num;i++)
    {p3->ele[k++]=ele[i++];}

    for(;j<p2.num;j++)
    {p3->ele[k++]=p2.ele[j++];}
    p3->num=k;

    return *p3;
  }
  friend ostream & operator<<(ostream &os,Poly &P);
  friend istream & operator>>(istream &is,Poly &P);
};


 istream & operator>>(istream &is,Poly &P)
{ cout<<"enter the coefficient and exponent"<<endl;
  for(int i=0;i<P.num;i++)
  {
    cin>>P.ele[i].coe>>P.ele[i].exp;
  }
  return is;
}
ostream & operator<<(ostream &os,Poly &P)
{ int sum=0,x=2;
  for(int i=0;i<P.num;i++)
  {
    cout<<P.ele[i].coe<<"* x"<<P.ele[i].exp<<" + " ;
    sum+=P.ele[i].coe*pow(x,P.ele[i].exp);
  }
    cout<<endl<<sum<<endl;
  return os;
}

int main()
{
  Poly p(3);
  cin>>p;
  cout<<p;
  cout<<"Poly 2"<<endl;
  Poly p2(3);
  cin>>p2;
  cout<<p2;
  Poly p3;
    cout<<"poly 3: "<<endl;
  p3=p.add(p2);


  cout<<p3;
}
