#include "bits/stdc++.h"
#define int long long

using namespace std;

int gcd(int a, int b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}
 
main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> array(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> array[i];
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 2 << endl;
            continue;
        }

        vector<int> prefixGCD(n);
        vector<int> suffixGCD(n);

        prefixGCD[0] = array[0];
        suffixGCD[n - 1] = array[n - 1];

        for (int i = 1; i < n; i++)
        {
            prefixGCD[i] = gcd(prefixGCD[i - 1], array[i-1]);
        }

        for (int i = n-2; i >=0; i--)
        {
            suffixGCD[i] = gcd(suffixGCD[i + 1], array[i+1]);
        }

        int max_gcd = max(prefixGCD[n-1],suffixGCD[0]);

        for(int i = 1;i<n-1;i++)
        {
            max_gcd = max(max_gcd,gcd(prefixGCD[i],suffixGCD[i]));
        }

        sort(array.begin(),array.end());

        int denominations = 0;
        bool changedDenomination = false;

        for(int i=0;i<n;i++)
        {
            if(i==n-1 && !changedDenomination)
            {
                denominations+=1;
                break;
            }
            if(array[i]%max_gcd==0)
            {
                denominations += array[i]/max_gcd;
            }
            else
            {
                denominations+=1;
                changedDenomination = true;
            }
        }

        cout<<denominations<<endl;
    }
    return 0;
}