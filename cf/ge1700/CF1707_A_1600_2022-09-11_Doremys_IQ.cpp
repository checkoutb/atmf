
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
#include <unordered_map>
//#include <string.h>       // memset

using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = vector<vector<int>>;
using myvi = vector<int>;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

// D

//    int current = 0;
//    for (int i = n - 1; 0 <= i; i--)
//    {
//        if (current < q)
//        {
//            ans[i] = '1';
//            if (current < as[i])
//                current++;
//        }
//        else if (as[i] <= current)
//            ans[i] = '1';
//    }

//......?
// 最后的 都选， current 是 指 最后的iq 变成了0。
// 所以 如果 cur < as[i]， 说明 要降低iq， 。 因为倒序， 所以 之前 就是 ++。






// 171666284 	Sep/11/2022 09:41UTC+8 	Ouha 	1707A - Doremy's IQ 	GNU C++17 	Accepted 	171 ms 	400 KB


// 看后面有没有 和 IQ 相同的 test， 有就不参加降智的test
// 记录最后一次出现，或count。
// bu ,这样的话，iq会有剩余的。  需要反推回去。
// 不如直接： 小于等于初始iq 的全部参加 。 然后 从后往前，
// 。。。 所以关联了 二分搜索。。 mid之后的全部参与，之前的只参与 <= iq 的。
// 11111112111 初始iq=1 。。
void fun1()
{

    int sz1, iq;
    cin>>sz1>>iq;

    myvi vi(sz1);


    for (int i = 0; i < sz1; ++i)
    {
        cin>>vi[i];
    }
    if (iq >= sz1)
    {
        for (int i = 0; i < sz1; ++i)
        {
            cout<<1;
        }
        cout<<endl;
        return;
    }

    int cnt = 0;
    int ans = sz1;        // < ans , >= ans
//    for (int i = 0; i < sz1; ++i)
//    {
//        if (iq >= vi[i])
//            cnt++;
//    }

    int l = 0, r = sz1 - 1;
    int t2 = 0;
    int iq2 = iq;
    while (l <= r)
    {
        iq = iq2;
        int md = (l + r) / 2;
        t2 = 0;                 // number of test
        for (int i = 0; i < md; ++i)       // prefix sum ...
        {
            if (iq >= vi[i])
                t2++;
        }
        for (int i = md; i < sz1; ++i)
        {
            if (iq >= vi[i])
                ++t2;
            else
                iq--;
//                if (iq > 0)
//                {
//                    ++t2;
//                }
        }

        #ifdef __test
        //cout<<t2<<" ,, "<<cnt<<endl;
        cout<<"           "<<iq<<", "<<md<<" ----------- "<<l<<", "<<r<<endl;
        #endif // __test

//        if (t2 > cnt)
//        {
//            cnt = t2;
//        }
        if (iq >= 0)
        {
            ans = md;
            r = md - 1;
        }
        else
        {
            l = md + 1;
        }

//        if (iq >= 0)
//        {
//            ans = md;
//            r = md - 1;
//        }
//        else
//        {
//            l = md + 1;
//        }
    }
    iq = iq2;
    for (int i = 0; i < ans && i < sz1; ++i)
    {
        if (iq >= vi[i])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    for (int i = ans; i < sz1; ++i)
    {
        if (iq >= vi[i])
            cout<<1;
        else
            if (iq > 0)
            {
                cout<<1;
                --iq;
            }
            else
            {
                cout<<0;
            }
    }
    cout<<endl;

//    unordered_map<int, int> map2;
//
//    for (int i = sz1 - 1; i >= 0; --i)
//    {
//        if (map2.find(vi[i]) == map2.end())
//            map2[vi[i]] = i;
//    }
//
//    for (int i = 0; i < sz1; ++i)
//    {
//        if (vi[i] <= iq)
//        {
//            vi[i] = 1;
//        }
//        else
//        {
//            if (map2.find(iq))
//        }
//    }


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
