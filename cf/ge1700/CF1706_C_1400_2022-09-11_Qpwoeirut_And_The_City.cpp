
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
#include <cmath>

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

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE








// 171668907 	Sep/11/2022 11:07UTC+8 	Ouha 	1706C - Qpwoeirut And The City 	GNU C++17 	Accepted 	358 ms 	1600 KB

// 奇数 只有一种，
// 偶数的话， 找到一个 点来 split。
void fun1()
{
    int sz1;
    cin>>sz1;

    vector<long long> vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin>>vi[i];
    }

    long long ans = 0;
    if (sz1 % 2 == 1)
    {
        for (int i = 1; i < sz1 - 1; i += 2)
        {
            ans += max(0LL, 1LL + max(vi[i - 1] - vi[i], vi[i + 1] - vi[i]));
        }
        cout<<ans<<endl;
        return;
    }

    vector<long long> v2(sz1);
    v2[1] = max(0LL, 1LL + max(vi[0] - vi[1], vi[2] - vi[1]));
    for (int i = 3; i < sz1 - 1; i += 2)
    {
        v2[i] = v2[i - 2] + max(0LL, 1LL + max(vi[i - 1] - vi[i], vi[i + 1] - vi[i]));
    }

    ans = v2[sz1 - 3];
    long long sum2 = 0;
    for (int i = sz1 - 2; i > 0; i -= 2)
    {
        sum2 += max(0LL, 1LL + max(vi[i - 1] - vi[i], vi[i + 1] - vi[i]));
        ans = min(ans, sum2 + (i > 3 ? v2[i - 3] : 0));

        #ifdef __test
        cout<<ans<<" , "<<i<<endl;
        #endif // __test

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


