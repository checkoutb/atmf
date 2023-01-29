
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








// 189797163 	Jan/20/2023 10:37UTC+8 	Ouha 	1648A - Weird Sum 	GNU C++17 	Accepted 	265 ms 	17500 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;

    //vector<int> vi(100001);
    //vector<int> v2(100001);

    //int t2 = 0;
    //for (int i = 0; i < sz1; ++i)
    //{
    //    for (int j = 0; j < sz2; ++j)
    //    {
    //        cin >> t2;
    //        ++vi[i];
    //    }
    //}
    
    map<int, map<int, int>> map2;
    map<int, map<int, int>> map3;
    
    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            cin >> t2;
            ++map2[t2][i];
            ++map3[t2][j];
        }
    }
    long long ans = 0LL;
    for (auto& p : map2)
    {
        map<int, int>& mp = p.second;
        long long sum2 = 0LL;
        long long cnt = 0;
        int i = 0;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++, ++i)
        {
            ans += (1LL * it->first * cnt - sum2) * it->second;
            sum2 += it->first * it->second;
            cnt += it->second;
#ifdef __test
            cout << ans << " - " << sum2 << " - " << cnt << endl;
#endif
        }
    }
    for (auto &[_k, mp] : map3)
    //for (auto& p : map3)
    {
        //map<int, int>& mp = p.second;
        long long sum2 = 0LL;
        long long cnt = 0;
        int i = 0;
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++, ++i)
        {
            ans += (1LL * it->first * cnt - sum2) * it->second;
            sum2 += it->first * it->second;
            cnt += it->second;
        }
    }
    
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
