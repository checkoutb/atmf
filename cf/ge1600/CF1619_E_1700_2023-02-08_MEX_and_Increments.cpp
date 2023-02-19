
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

// D D

//int n;
//std::cin >> n;
//
//std::vector<int> cnt(n + 1);
//for (int i = 0; i < n; i++) {
//    int x;
//    std::cin >> x;
//    cnt[x]++;
//}
//
//i64 ans = 0;
//std::vector<int> s;
//for (int v = 0; v <= n; v++) {
//    if (ans == -1) {
//        std::cout << "-1" << " \n"[v == n];
//        continue;
//    }
//    std::cout << ans + cnt[v] << " \n"[v == n];
//
//    while (cnt[v]--) {
//        s.push_back(v);
//    }
//
//    if (s.empty()) {
//        ans = -1;
//    }
//    else {
//        ans += v - s.back();
//        s.pop_back();
//    }
//}







//192739427 	Feb / 08 / 2023 21:21UTC + 8 	Ouha 	1619E - MEX and Increments 	GNU C++17 	Accepted 	312 ms 	2400 KB
// 7259

// tle ..      vp.erase(begin(vp) + ivp); then Accepted.

// no == target, and the count of number (less than target) must >= target.   0... 
//      because min operation, so count == target..no, ,, so not sum - prefix_sum¡£
//                  [0,1,2,2,2,2,3]  MEX=4, 0 operation.  [0,1,2,2] MEX=4, 1 operation.
// (0+n)*(n-1)/2 - prefix_sum;
// after sort, if [i] > i, no way to get MEX=i ,, after [i]>i£¬ always no way 
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    std::sort(std::begin(vi), end(vi));

    int cnt0 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (vi[i] == 0)
            ++cnt0;
        else
            break;
    }
    cout << cnt0 << ' ';

    int idx = 0;
    int mx = -1;
    ll ans = 0LL;
    ll psum = 0LL;
    vector<pair<int, int>> vp;      // <number, count>
    int tar = 1;
    for (; tar <= sz1; ++tar)
    {
        while (idx < sz1 && vi[idx] < tar)
        {
            if (!vp.empty() && vp.back().first == vi[idx])
                ++vp.back().second;
            else
                vp.emplace_back(make_pair(vi[idx], 1));
            ++idx;
        }

        if (idx < tar)
            break;

        //if (idx < sz1 && vi[idx] == tar)
        //{
        //    cout << -1 << ' ';
        //    continue;
        //}

        while (idx < sz1 && vi[idx] == tar)     // ==
        {
            if (!vp.empty() && vp.back().first == vi[idx])
                ++vp.back().second;
            else
                vp.emplace_back(make_pair(vi[idx], 1));
            ++idx;
        }

        // tar -> tar + 1
        int t2 = vp.back().first == tar ? vp.back().second : 0;

        int ivp = vp.size() - 1;
        for (int i = tar - 1; i > mx; --i)
        {
            while (ivp >= 0 && (vp[ivp].first > i
                //|| vp[ivp].second == 0
                ))           // will < 0 ? i think not
            {
                --ivp;
            }
            //if (vp[ivp].first == i)     // --second
            //    continue;

            ans += i - vp[ivp].first;
            if (vp[ivp].second == 1)
            {
                vp.erase(begin(vp) + ivp);
            }
            else
                --vp[ivp].second;
        }

        mx = tar - 1;
        cout << ans + t2 << ' ';
    }
    while (tar++ <= sz1)
    {
        cout << -1 << ' ';
    }
    cout << endl;
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
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
