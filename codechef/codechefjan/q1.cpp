#include"bits/stdc++.h"
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
    int n,k,d;
    cin>>n>>k>>d;
    if(k==0)
    {
        cout<<"0"<<endl;
        continue;
    }
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int sum = accumulate(a,a+n,0); 
    cout<<min(d,sum/k)<<endl;

 }
 return 0;   
}