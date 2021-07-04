#include "bits/stdc++.h"

using namespace std;

int main(int argc, char* argv[])
{
  int t;
  cin>>t;
  while(t--)
  {
    int k,n;
    cin>>n>>k;
    vector<int> array(n);
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
        //cout<<array[i];
    }
    int numberOfOperations=0;
    for(int i=0;i<=30;i++)
    {
       int currentCount = 0;
       int currentNumber = pow(2,i);
       
       //cout<<currentCount<<" "<<currentNumber<<endl;
       for(int j=0;j<n;j++)
       {
           if(currentNumber & array[j])
           {
               currentCount++;
           }
       }
      
       numberOfOperations += ceil(float(currentCount)/float(k));
    }
    cout<<numberOfOperations<<endl;
    
  }
  return 0;
}