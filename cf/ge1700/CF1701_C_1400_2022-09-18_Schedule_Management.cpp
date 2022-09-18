
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
//#include <numeric>
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






// 172525957 	Sep/18/2022 14:47UTC+8 	Ouha 	1701C - Schedule Management 	GNU C++17 	Accepted 	249 ms 	800 KB

void fun1()
{
    int sz1, sz2;
    cin>>sz1>>sz2;

    myvi vi(sz1 + 1);       // worker
//    myvi v2(sz2);       // task

//    for (int i = 0; i < sz1; ++i)
//        cin>>vi[i];

    int t2;
    for (int i = 0; i < sz2; ++i)
    {
//        cin>>v2[i];
        cin>>t2;
        vi[t2]++;
    }



    int l = 1, r = 800105;
    int ans = r;
    while (l <= r)
    {
        int md = (l + r) / 2;
        ll t2 = 0LL;     // remain task

        for (int i = 1; i <= sz1; ++i)
        {
            if (vi[i] > md)
            {
                t2 += vi[i] - md;
            }
            else
            {
                t2 -= (md - vi[i]) / 2;         // 溢出了。  r 的问题， 400000 就可以了  或 sz2*2
            }
        }

        if (t2 <= 0LL)
        {
            ans = md;
            r = md - 1;
        }
        else
        {
            l = md + 1;
        }

    }

    cout<<ans<<endl;
}


int main()
{
    int w = 0;
    cin>>w;



    for (int _ = w; _ < w; ++_)
    {

    }

    for (int _ = 0; _ < w; ++_)
    {


        fun1();

        //cout<<endl;
    }


    return 0;
}
