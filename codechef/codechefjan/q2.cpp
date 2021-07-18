/*The first line of the input contains an integer T, denoting the number of test cases.
The first line of each test case contains an integer N, the length of the encoded string.
The second line of each test case contains the encoded string S.*/


#include"bits/stdc++.h"
using namespace std;
int main()
{
 int t;
 cin>>t;
 char map[16] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};
 while(t--)
 {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int offset=0;
    string encodedstring = "";
    for(int i=0;i<n;i+=4)
    {
       offset=0;
       s[i]=='1' ? offset+=8:offset+=0;
       s[i+1]=='1'? offset+=4:offset+=0;
       s[i+2]=='1'? offset+=2:offset+=0;
       s[i+3]=='1'? offset+=1:offset+=0;
       encodedstring+=map[offset];
    } 
    cout<<encodedstring<<endl;
 }
 return 0;   
}