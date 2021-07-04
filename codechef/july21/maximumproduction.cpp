#include "bits/stdc++.h"

using namespace std;

int maxnum(int a,int b)
{
    if(a>b) return a;
    return b;
}

int main(int argc, char* argv[])
{
  int t;
  cin>>t;
  while(t--)
  {
    int d;
    int x;
    int y;
    int z;
    cin>>d>>x>>y>>z;
    //cout<<d<<x<<y<<z<<endl;
    int profa = 7*x;
    int profb = (y*d)+(z*(7-d));
    cout<<maxnum(profa,profb)<<endl;

  }  

  return 0;
}