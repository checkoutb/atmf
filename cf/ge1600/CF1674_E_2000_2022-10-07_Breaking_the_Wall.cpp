
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

//#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <cmath>
//#include <limits.h>   // INT_MAX

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset

using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = vector<vector<int>>;
using myvi = vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE






// g

// 7 6 6 8 5 8
// 1轰4下， 2轰2下。。。



// 3 zhong keneng ?
// 1 - 完全不相关的2个
// 2 - 一直这个点，直到轰出2个
// 3 - 这个点 和 右侧的点。    // 。
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);

    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int mn1 = 1234567;
    int mn2 = mn1 + 1;      // durability

    int typ2 = mn1;     // number of bomb
    int typ3 = mn1;

    for (int i = 0; i < sz1; ++i)
    {
        int t2 = vi[i];
        if (t2 <= mn1)
        {
            mn2 = mn1;
            mn1 = t2;
        }
        else if (t2 < mn2)
        {
            mn2 = t2;
        }

        int a = i == 0 ? 1234567 : vi[i - 1];
        int c = i == sz1 - 1 ? 1234567 : vi[i + 1];
        int b = (t2 & 1) + (t2 >> 1);

        if (a > b)
        {
            if (b > c)
            {
                if (b < typ2)
                {
                    typ2 = b;
                }
            }
            else
            {
                if (a > c)
                {
                    if (c < typ2)
                    {
                        typ2 = c;
                    }
                }
                else
                {
                    if (a < typ2)
                    {
                        typ2 = a;
                    }
                }
            }
        }
        else
        {
            if (b < c)
            {
                if (b < typ2)
                {
                    typ2 = b;
                }
            }
            else
            {
                if (a < c)
                {
                    if (c < typ2)
                        typ2 = c;
                }
                else
                {
                    if (a < typ2)
                        typ2 = a;
                }
            }
        }

        int d;
        if (i != sz1 - 1)
        {
            a = i == 0 ? 1234567 : vi[i - 1];
            b = vi[i];
            c = vi[i + 1];
            d = i == sz1 - 2 ? 1234567 : vi[i + 2];

            int atb = min(min(a, c), (b & 1) + (b >> 1));

            b -= atb * 2;
            c -= atb;

            //int atc = min(min(b + 1234567, d), (c & 1) + (c >> 1));
            if (a <= 0)
            {
                ;
            }
            else
            {
                if (b <= 0)
                {
                    b += 1234567;
                }
                else
                {
                    c += 1234567;
                }
            }
            int atc = min(min(b, d), (c & 1) + (c >> 1));
            atc = max(atc, 0);
            if ((atb + atc) < typ3)
                typ3 = atb + atc;
        }

    }
    
    int ans = min({typ2, typ3, (mn1 & 1) + (mn1 >> 1) + (mn2 & 1) + (mn2 >> 1)});
    
    cout << ans << endl;
}


int main()
{
    int w = 1;
    //cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
