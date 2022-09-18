
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
#include <unordered_map>
//#include <string.h>       // memset
#include <limits.h>

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


//        for (int i = 1; i <= n; i++) {
//            read(a[i]);
//            while (a[i] % 2 == 0) a[i] /= 2;
//        }
//        for (int i = 1; i <= n; i++) {
//            read(b[i]);
//            while (b[i] < 1000000000) b[i] *= 2;
//        }
//        sort(a + 1, a + n + 1);
//        sort(b + 1, b + n + 1);
//        for (int i = n; i >= 1; i--) q1.push(b[i]);
//        ans = 1;
//        for (int i = n; i >= 1; i--) {
//            while (1) {
//                int v1 = -1, v2 = 1, val;
//                if (!q1.empty()) v1 = q1.front();
//                if (!q2.empty()) v2 = q2.front();
//                if (v1 > v2) val = v1, q1.pop();
//                else val = v2, q2.pop();
//                if (val == a[i]) break;
//                if (val < a[i]) {
//                    fprintf(stderr, "i = %d, val = %d, a[i] = %d\n", i, val, a[i]);
//                    ans = 0;
//                    break;
//                }
//                q2.push(val / 2);
//            }
//            if (!ans) break;
//        }
//        printf("%s\n", ans ? "YES" : "NO");
//
//---------------
//        sort(a + 1, a + n + 1);                  // ... int a[N] . [+1, +n+1] ...
//                                          // .. 不， 第一个元素的 下标就是 1 ， 下标0 被跳过了。 看 代码的 for 循环
// 用 2个 queue + sort ， 做 priq ?   priq 能替代 这2个queue， 但是 这2个queue 无法替代 priq。



// 172510907 	Sep/18/2022 10:17UTC+8 	Ouha 	1702F - Equate Multisets 	GNU C++17 	Accepted 	733 ms 	5700 KB

// 都 /2 直到 最小不失真的数字。 。 这个必须完全相等。 bu ,a /2 到最小不失真， b (/2) 直到 map 中存在。
void fun1()
{
    int sz1;
    cin>>sz1;
    unordered_map<int, int> map2;
    int t2;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>t2;

        #ifdef __test
        cout<<"in : "<<t2<<" -> ";
        #endif // __test

        while (t2 % 2 == 0)
        {
            t2 /= 2;
        }

        #ifdef __test
        cout<<t2<<endl;
        #endif // __test

        map2[t2]++;
    }
    bool ans = true;
    for (int i = 0; i < sz1; ++i)
    {
        cin>>t2;

        if (!ans)
            continue;

        while (t2 > 0)
        {
            if (map2.find(t2) != map2.end() && map2[t2] > 0)
            {
                map2[t2]--;
                goto AAA;
            }

            t2 /= 2;
        }
        ans = false;

        AAA:
        continue;

//        #ifdef __test
//        cout<<" --- in "<<t2<<" -> ";
//        #endif // __test
//
//        while (t2 % 2 == 0)
//            t2 /= 2;
//
//        #ifdef __test
//        cout<<t2<<endl;
//        #endif // __test
//
//        map2[t2]--;
    }

    cout<<(ans ? "yes" : "no")<<endl;

//    for (auto& p : map2)
//    {
//        if (p.second != 0)
//        {
//            cout<<"no"<<endl;
//            return;
//        }
//    }
//    cout<<"yes"<<endl;

}



// *2 不会丢失信息。 是可以rollback的。
// {12,24} {12,25}
// {24} {25}
void fun1_error()
{
    int sz1;
    cin>>sz1;

    myvi v1(sz1);
    myvi v2(sz1);

    for (int i = 0; i < sz1; ++i)
    {
        cin>>v1[i];
    }
    for (int i = 0; i < sz1; ++i)
    {
        cin>>v2[i];
    }

    unordered_map<int, int> map2;
    for (int i : v1)
        map2[i]++;

    //sort(begin(v2), end(v2), std::greater<int>());
    sort(begin(v2), end(v2));

    #ifdef __test
    for (int i : v2)
    {
        cout<<i<<", ";
    }
    cout<<endl;
    #endif // __test

    constexpr int MX = INT_MAX >> 1;
    for (int i = 0; i < sz1; ++i)
    {
        int t2 = v2[i];
        int mx = t2;
        t2 = -1;
        while (mx < MX)
        {
            if (map2.find(mx) != map2.end() && map2[mx] > 0)
            {
                t2 = mx;
            }
            mx *= 2;
        }
        if (t2 != -1)
        {
            v2[i] = -1;
            map2[t2]--;
        }
    }

    for (int i = sz1 - 1; i >= 0; --i)
    {
        if (v2[i] == -1)
        {
            continue;
        }
        int t2 = v2[i];
        while (t2 >= 1)
        {
            if (map2.find(t2) != map2.end() && map2[t2] > 0)
            {
                v2[i] = -1;
                map2[t2]--;
                goto AAA;
            }
            t2 /= 2;
        }

        #ifdef __test
        cout<<" ================ "<<endl;
        cout<<v2[i]<<", "<<endl;
        for (auto& p : map2)
        {
            cout<<p.first<<" : "<<p.second<<endl;
        }
        #endif // __test

        cout<<"NO"<<endl;
        return;

        AAA:
        continue;
    }


    cout<<"yes"<<endl;
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
