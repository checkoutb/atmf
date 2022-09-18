
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


// D

// 不需要二分。  知道 可以的区间后，在这个区间中 直接 sum/t 。




// tle 。。。

// 感觉好像挺简单的， 因为 可以瞬间就把 溢出的水 移到 下一个 水闸。
// bububu ,,, 如果最后一个 lock 满了，那么 会 排到 河里。 所以不能 直接 移动所有的 pipe 到 第一个lock
//          但 肯定是 优先 把 前面的 pipe 打开的。
void fun1()
{

    int sz1;
    cin>>sz1;

    myvi vi(sz1);
    ll sum2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>vi[i];
        sum2 += vi[i];
    }

    int sz2;
    cin>>sz2;

    int mntm = 0;

    int l = 1, r = 1e9;     // time
    while (l <= r)
    {
        int md = (l + r) / 2;
        ll t2 = 0LL;
        for (int i = 0; i < sz1 && t2 >= 0LL; ++i)
        {
            t2 = t2 + md - vi[i];
        }
        if (t2 >= 0)
        {
            mntm = md;
            r = md - 1;
        }
        else
        {
            l = md + 1;
        }
    }

    while (sz2-- > 0)
    {
        int tm;
        cin>>tm;

        if (tm >= sum2)
        {
            cout<<1<<endl;
            continue;
        }
        if (tm < mntm)
        {
            cout<<-1<<endl;
            continue;
        }

        int ans = -1;

        int l = 1, r = sz1;

        while (l <= r)
        {
            int md = (l + r) / 2;
            ll t2 = 0LL;        // remain water

            for (int i = 0; i < sz1 && t2 >= 0LL; ++i)
            {
                if (i < md)         // pipe open
                {
                    t2 = t2 + tm - vi[i];
                }
                else
                {
                    t2 -= vi[i];
                }
            }
            if (t2 >= 0)
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

        //cout<<endl;
    }


    return 0;
}
