#include<iostream>
using namespace std;

void patterns(int n)
{
  for(int rows=0;rows<=2*n;rows++)
  {
    for(int col=0;col<=2*n;col++)
    {
      int x=n-min(min(rows,2*n-rows),min(col,2*n-col));
      cout<<x<<" ";
    }
    cout<<endl;
  }
}


int main()
{
  patterns(4);
  return 0;
}
