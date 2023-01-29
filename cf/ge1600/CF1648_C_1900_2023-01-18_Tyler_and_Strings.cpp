
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
#include <map>
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


void fun1()
{
    int sz1, sz2;
    cin >> sz1 >> sz2;

    //vector<long long> sarr(200001);
    vector<int> tarr(sz2);
    map<int, int> maps;

    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        ++maps[t2];
    }
    for (int i = 0; i < sz2; ++i)
    {
        cin >> tarr[i];
    }
    const int MOD = 998244353;
    
    vector<int> fact(200001);
    fact[0] = 1;
    for (long long i = 1; i < 200001; ++i)
        fact[i] = (i * fact[i - 1]) % MOD;

    long long ans = 0LL;
    for (int i = 0; i < sz2; ++i)
    {
        t2 = tarr[i];
        unordered_map<int, int> map2;

        for (map<int, int>::iterator it = maps.begin(); it != maps.end(); it++)
        {
            if (it->first >= t2)
                break;
            int t3 = it->second;
            if (map2.find(t3) == map2.end())
            {
                long long t5 = 1LL;
                int tsz = sz1 - i - 1;

                for (auto& p : maps)
                {
                    //t5 +   // .... 无法直接用 mod后的阶乘值 来计算组合。
                }


                map2[t3] = (int) t5;
            }
            ans = (ans + map2[t3]) % MOD;
        }
        if (maps[t2] == 0)
        {
            break;
        }
        --maps[t2];
    }

    cout << ans << endl;
}

// g. 这个不是全排列。。是 Csz1取x * C(sz1-x)取y * C(sz1-x-y)取z ...
// bu,想到一个方法。

// 应该要BIT之类的来做range sum/query。不然TLE的。
void fun1_()
{
    int sz1, sz2, kk;
    cin >> sz1 >> sz2;
    
    //long long sarr[20'0001] = { 0LL };
    vector<long long> sarr(200001);
    //int tarr[20'0001] = { 0 };
    vector<int> tarr(sz2);
    
    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        ++sarr[t2];
    }
    
    for (int i = 0; i < sz2; ++i)
        cin >> tarr[i];
    
    const int MOD = 998244353;

    int fact[20'0001] = { 1 };

    for (long long i = 1; i < 20'0001LL; ++i)
    {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    
    map<int, int> map2;     // ~=BIT, removed, prefix of t

    for (int i = 1; i <= 200000; ++i)
    {
        sarr[i] += sarr[i - 1];
    }

    long long ans = 0LL;
//    int used[200001] = { 0 };
    vector<int> used(200001);
    for (int i = 0; i < sz2; ++i)
    {
        long long t3 = sarr[tarr[i] - 1];      // < t[i]

        map<int, int>::iterator it = map2.lower_bound(tarr[i]);

        if (it == map2.begin())
        {
            ;
        }
        else
        {
            it = std::prev(it);
            t3 -= it->second;
        }

        ans = ans + t3 * fact[sz1 - i - 1];

        // -------------
        t3 = sarr[tarr[i]] - sarr[tarr[i] - 1] - used[tarr[i]];
        if (t3 == 0LL)
            break;


        for (map<int, int>::iterator it = map2.upper_bound(tarr[i]); it != map2.end(); it++)
        {
            it->second++;
        }
        if (map2[tarr[i]] != 0)
        {
            ++map2[tarr[i]];
        }
        else
        {
            map<int, int>::iterator it = map2.lower_bound(tarr[i]);    // value = 0

            if (it != map2.begin())
            {
                map2[tarr[i]] = std::prev(it)->second;
            }

            ++map2[tarr[i]];
        }

        ++used[tarr[i]];
    }


    cout << ans << endl;
}


// 273
//10 5
//1 2 2 1 1 2 3 1 2 2
//1 2 2 1 1


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
