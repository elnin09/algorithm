#include "bits/stdc++.h"

using namespace std;

int main(int argc, char* argv[])
{
  int t;
  cin>>t;
  while(t--)
  {
      long long c;
      long long g;
      cin >>g>>c;
      long long h = (c*c)/(2*g);
      cout<<h<<endl;
  }  

  return 0;
}