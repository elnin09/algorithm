/*
The first line of the input contains an integer T, the number of testcases.
Each testcase contains a single line of input, which has four space separated integers - N, K, x, y, denoting the size of the board, the number of collisions to report the answer for, and the starting coordinates.
*/


#include"bits/stdc++.h"
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
    long long n,k,x,y;
    cin>>n>>k>>x>>y;
    long long offset=0;
    long c ;
    if(x==y)
    {
       cout<<n<<" "<<n<<endl;
    }
    else if(x>y)
    {
        c=x-y;
        long long dx[4]={c,n,n-c,0};
        long long dy[4]={0,n-c,n,c};
        long long offset = k-(k/4)*4;
        cout<<dx[offset]<<" "<<dy[offset]<<endl;
    }
    else
    {
        c=y-x;
        long long dx[4]={0,n-c,n,c};
        long long dy[4]={c,n,n-c,0};
        long long offset = k-(k/4)*4;
        cout<<dx[offset]<<" "<<dy[offset]<<endl;
    }
    
 }
 return 0;   
}