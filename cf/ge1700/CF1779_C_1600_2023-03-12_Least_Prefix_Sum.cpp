
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
#include <queue>
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







// 197044161 	Mar/12/2023 18:13UTC+8 	Ouha 	1779C - Least Prefix Sum 	GNU C++17 	Accepted 	451 ms 	8600 KB
// 9344


// after m prefix must > 0/sum0-m
// element < m must be negative, no, neg tail/m -> head
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    int m;
    cin >> m;
    
    int ans = 0;
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    //priority_queue<ll, vector<ll>, std::greater<>> priq(begin(vi), end(vi));

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, std::greater<>> priq;
    ll sum2 = 0LL;

    vector<ll> v2(m);
    v2[0] = vi[0];
    for (int i = 1; i < m; ++i)
    {
        v2[i] = v2[i - 1] + vi[i];
    }
    sum2 = v2[m - 1];
    for (int i = m - 1; i >= 0; --i)
    {
        while (sum2 > v2[i])
        {
            sum2 += priq.top().first * 2;
            vi[priq.top().second] = priq.top().first;
            priq.pop();
            ++ans;
        }
        priq.push(make_pair(-vi[i], i));                            // below the while
    }

    //for (int i = 0; i < m; ++i)
    //{
    //    sum2 += vi[i];
    //    priq.push(std::make_pair(sum2, i));
    //}
    //int idx = m - 1;
    //while (!priq.empty() && sum2 > priq.top().first)
    //{
    //    if (priq.top().second > idx)
    //    {
    //        priq.pop();
    //        continue;
    //    }
    //    else
    //    {
    //        if (vi[idx] > 0)
    //        {
    //            sum2 -= vi[idx] * 2;
    //            vi[idx] = -vi[idx];
    //            ++ans;
    //        }
    //        --idx;
    //    }
    //}

    while (!priq.empty())
        priq.pop();

    sum2 = 0LL;
    for (int i = m; i < sz1; ++i)
    {
        priq.push(std::make_pair(vi[i], i));
        sum2 += vi[i];

        while (sum2 < 0)
        {
            sum2 += priq.top().first * -2;
            vi[priq.top().second] = -vi[priq.top().second];
            priq.pop();
            ++ans;
        }
    }

    cout << ans << endl;
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
