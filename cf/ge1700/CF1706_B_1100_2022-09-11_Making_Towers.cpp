
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

//    vint last(n, -1);
//    vint cnt(n);
//    vint ans(n);
//    range(i, n) {
//        if (last[c[i]] == -1) {
//            last[c[i]] = i;
//            cnt[c[i]] = 1;
//            ans[c[i]] = 1;
//        } else if ((i - last[c[i]]) & 1) {
//            ++cnt[c[i]];
//            ans[c[i]] = max(ans[c[i]], cnt[c[i]]);
//            last[c[i]] = i;
//        } else {
//            last[c[i]] = i;
//        }
//    }

//        vector prev(n, -1), len(n, 0);
//        rep(i, n) {
//            if (prev[c[i]] == -1)
//                prev[c[i]] = i, len[c[i]] = 1;
//            else if ((i - prev[c[i]]) % 2)
//                ++len[c[i]], prev[c[i]] = i;
//        }

//... 为什么舍弃了一半 。




// 171671242 	Sep/11/2022 12:13UTC+8 	Ouha 	1706B - Making Towers 	GNU C++17 	Accepted 	280 ms 	2900 KB

// 好像可以 部分悬空？
void fun1()
{
    int sz1;
    cin>>sz1;

    myvvi vvi(sz1 + 1);
    int t2;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>t2;
        vvi[t2].push_back(i);
    }

    int cnt1 = 0;
    int cnt0 = 0;
    for (int i = 1; i <= sz1; ++i)
    {
        if (vvi[i].empty())
        {
            cout<<0<<' ';
            continue;
        }
        cnt1 = cnt0 = 0;
        for (int j : vvi[i])
        {
            if ((j + 1) % 2 == 0)
            {
                cnt0 = max(cnt0, cnt1 + 1);
            }
            else
            {
                cnt1 = max(cnt1, cnt0 + 1);
            }
        }
        cout<<max(cnt1, cnt0)<<' ';
    }

    cout<<endl;
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
