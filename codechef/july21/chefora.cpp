#include "bits/stdc++.h"
#define M 1000000007
#define ll unsigned long long

using namespace std;


//memoization optimization


ll power(ll a, ll b)
{
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }

    ll powb2 = power(a, b / 2);
    if (b % 2 == 0)
        return (powb2 * powb2)%M;
    return ((powb2 * powb2) % M * a)%M;
}

ll reverse(ll a)
{
    ll retval = 0;
    while (a)
    {
        retval = 10 * (retval) + (a % 10);
        a = a / 10;
    }
    return retval;
}

ll numberofDigits(ll a)
{
    ll digits = 0;
    while (a)
    {
        digits++;
        a = a / 10;
    }
    return digits;
}

ll chefor(ll a)
{
    //if(cheforaMap.count(a)) return cheforaMap[a];
    //cheforaMap[a] =
    return a * power(10, numberofDigits(a) - 1) + reverse(a / 10);
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    ll precomputedchefora[100001];
    ll sumchefora[100001];


    for (int i = 0; i < 100001; i++)
    {
        precomputedchefora[i] = chefor(i);
    }
   
    sumchefora[1]=precomputedchefora[1];
    for (int i = 2; i < 100001; i++)
    {
        sumchefora[i] = sumchefora[i-1] + chefor(i);
    }

    while (t--)
    {
        /*
      int n;
      cin>>n;
      cout<<chefor(n)<<endl;
     */
        ll l, r;
        cin >> l >> r;

        ll chefl = precomputedchefora[l]%M;
        ll outval = sumchefora[r]-sumchefora[l];

        /**
     for(ll i = l+1; i<=r;i++)
     {
         outval = (outval*(power(chefl,chefor(i)))%M)%M;
     }
     **/

        cout << power(chefl, outval) << endl;
    }

    return 0;
}