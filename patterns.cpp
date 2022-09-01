#include<iostream>
using namespace std;

void patterns(int n)
{
  for(int rows=1;rows<2*n;rows++)
  {
    for(int col=1;col<=n;col++)
    {
      int x=n-min(min(rows,col),min(2*n-rows,2*n-col))+1;
      cout<<x<<" ";
    }
    cout<<endl;
  }
}


int main()
{
  patterns(5);
  return 0;
}
