
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







// 。。。全是 overflow
// 172534362 	Sep/18/2022 16:21UTC+8 	Ouha 	1700C - Helping the Nature 	GNU C++17 	Accepted 	374 ms 	1600 KB

// ？ 是要 变成 升序， 然后再 + [sz1 - 1]
// 首先变得没有负数，然后 上面的操作。 不不不。 非降，+ [sz1-1]-(min(0,[0]))
void fun1()
{
    int sz1;
    cin>>sz1;

    vector<ll> vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin>>vi[i];
    }

    ll ans = 0;        // no ll ?
    ll mn = vi[0];
    for (int i = 1; i < sz1; ++i)
    {
        if (vi[i - 1] > vi[i])
        {
            ans += (vi[i - 1] - vi[i]);
            mn -= (vi[i - 1] - vi[i]);
        }
    }

    ans = ans + vi[sz1 - 1] - mn + abs(mn);          // overflow

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
