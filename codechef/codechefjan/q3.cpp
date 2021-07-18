/*
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains M space-separated integers B1,B2,…,BM.
*/

#include"bits/stdc++.h"
using namespace std;

long long acculmulatesum(long long arr[],int n)
{
    long long retval =0;
    for(int i=0;i<n;i++)
    {
        retval+=arr[i];
    }
    return retval;
}

bool sorthelper(long long a,long long b)
{
   bool retval = a<b ?  false : true;
   return retval;
}
int main()
{
 int t;
 cin>>t;

 while(t--)
 {
    int m,n;
    cin>>n>>m;
    long long a[n]; //votes for John
    long long b[m]; //votes for Jack

    for(int i=0;i<n;i++)
    {
       cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
       cin>>b[i];
    }
    int swaps=0;
    long long  sumjohn = acculmulatesum(a,n);
    long long sumjack = acculmulatesum(b,m);
    int i=0;
    sort(a,a+n);
    sort(b,b+m,sorthelper);
    while(i<m && i<n)
    {
        //cout<<sumjohn<<sumjack<<endl;
        if(sumjohn>sumjack)
        {
            break;
        }
        else
        {
            if(a[i]>b[i])
            {
              break;
            }
            else
            {
                sumjohn+=b[i]-a[i];
                sumjack-=b[i]-a[i];
                swaps++;
                i++;
            }
            
        }

    }
    if(sumjohn>sumjack)
    {
        cout<<swaps<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    

 }
 return 0;   
}