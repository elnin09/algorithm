/*
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers H1,H2,…,HN.
*/

/*
1≤T≤5
1≤N,K≤4,000
1≤Hi≤105 for each valid i
*/

bool comparator(int a, int b)
{
    if (a >= b)
    {
        return true;
    }
    return false;
}

#include "bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int tarheight = k;
        int height[n];
        for (int i = 0; i < n; i++)
        {
            cin >> height[i];
        }

        int boxesmike = 0;
        int boxestracey = 0;

        sort(height, height + n, comparator);

        int mike = 0;
        int tracey = 0;

        for (int i = 0; i < n; i++)
        {
            if (mike >= tarheight)
            {
                break;
            }
            else
            {
                if (mike + height[i] <= tarheight)
                {
                    mike += height[i];
                    boxesmike++;
                    height[i] = -1;
                }
                else
                {
                    if (i < n - 1 && mike + height[i + 1] >= tarheight)
                    {
                        //skip operation
                    }
                    else
                    {
                        mike += height[i];
                        boxesmike++;
                        height[i] = -1;
                    }
                }
            }
        }

        // new tracey
        for (int i = 0; i < n; i++)
        {
            if (tracey >= tarheight)
            {
                break;
            }
            else
            {
                if (height[i] != -1)
                {
                    tracey += height[i];
                    boxestracey++;
                    height[i] = -1;
                }
                /*
                else
                {
                    if (i < n - 1 && tracey + height[i + 1] >= tarheight) // no need to check this as mike is already done with his task
                    {
                        //skip operation
                    }
                    else
                    {
                        tracey += height[i];
                        boxesmike++;
                        height[i] = -1;
                    }
                }
                */
            }
        }

        if(mike>=tarheight && tracey>=tarheight)
        {
            cout<<boxesmike+boxestracey<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
    }
    return 0;
}