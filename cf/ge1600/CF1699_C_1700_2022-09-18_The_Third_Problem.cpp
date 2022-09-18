
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


//    l = r = pos[0];
//
//    for(ll i=1;i<n;i++){
//        if(pos[i]<l) l = pos[i];
//
//        else if(pos[i]>r) r = pos[i];
//
//        else ans=ans*(r-l+1-i)%MOD;
//    }
//
// seat状态的变化，我的是 每次都会 seat-- 或者 +x-1。 并且 加的话 就是 r-l




// 172554326 	Sep/18/2022 19:46UTC+8 	Ouha 	1699C - The Third Problem 	GNU C++17 	Accepted 	140 ms 	400 KB

// 0 - 0
// [0,a,b,1] - [0,b,a,1]
// 升序的话 只可能一种。
// 降序的话 也只能一种。
// 所以 下一个大值 在 外部的话， 就 代表 那个值的 下标 是确定的。
// 在内部的话 可以随便选。
void fun1()
{

    int sz1;
    cin>>sz1;

    myvi vi(sz1);
    int t2;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>t2;
        vi[t2] = i;
    }

    int l = vi[0];
    int r = l;
    ll ans = 1LL;
    const ll MOD = 1e9 + 7;
    int seat = 0;
    for (int i = 1; i < sz1; ++i)
    {
        t2 = vi[i];
        if (t2 > l && t2 < r)
        {
            ans = (ans * seat) % MOD;
            --seat;
        }
        else
        {
            if (t2 < l)
            {
                seat += (l - t2 - 1);
                l = t2;
            }
            else
            {
                seat += (t2 - r - 1);
                r = t2;
            }
        }
    }

    cout<<ans<<endl;
}


int main()
{
    int w = 1;
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
