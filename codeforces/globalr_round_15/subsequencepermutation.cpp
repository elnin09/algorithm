#include "bits/stdc++.h"

using namespace std;

int main(int argc, char* argv[])
{
  int t;
  cin>>t;
  while(t--)
  {
   int l;string s;
   int count = 0;
   cin>>l>>s;

   string scopy = s;

   sort(scopy.begin(),scopy.end());
  
   for(int i=0;i<l;i++)
   {
       if(scopy[i]!= s[i])
       {
          count++;
       }

   }
   cout<<count<<endl;
  }  
  return 0;
}