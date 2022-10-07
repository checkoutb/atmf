
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


// D D

// 有环：必然满足 kk
// 无环：拓扑sort，计算 dp[v] - 以v开始的最长path。
//       




// tle

// 老是 emoji 或 unicode。 得手动删除 中文 才能提交。

// 1有向图  oriented graph   dirtected graph
// some： 一些，少量，某个。
// 1没有 loop 和 重复边。
//
// binary search， 大于xx的点我不进去。
// dfs：child从小到大处理， 然后保存一个 stack/vector 来记录 最大值 序列。。降序
//   1每个node记录下 最小值和长度。 最小值就行。 是 到达这个node时 最小ans值
//
// 1不是说 不包含 loop 么。。 example 1 就是有loop 的。。
//      It's guaranteed that graph doesn't contain loops and multi-edges.
//  。。。loop 是 自环。。。
int mxdeptha1(myvi& vi, myvvi& vvi, vector<bool>& vst, int node, int depth, int lmt, int kk);

void fun1()
{
    ll sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2 >> kk;
    int r = 0;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
        r = max(vi[i], r);
    }

    //vector<pair<int, int>> vp(sz2);
    vector<vector<int>> vvi(sz1);
    int st, en;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> st >> en;
        --st, --en;
        vvi[st].push_back(en);
    }

    //if (kk > sz1)
    //{
    //    cout << -1 << endl;
    //    return;
    //}
    
    int l = 1;
    ++r;
    int ans = -1;
    while (l <= r)
    {
        int md = (l + r) / 2;

        //vector<bool> vst(sz1);
        int mxdep = 0;
        for (int i = 0; i < sz1 && mxdep < kk; ++i)
        {
            if (vi[i] <= md)
            {
                vector<bool> vst(sz1);
                int t2 = mxdeptha1(vi, vvi, vst, i, 1, md, kk);
                if (t2 > mxdep)
                    mxdep = t2;
            }
        }
        if (mxdep >= kk)
        {
            ans = md;
            r = md - 1;
        }
        else
        {
            l = md + 1;
        }

    }

    cout << ans << endl;
    
}

// no circle, so there is an end.
// 2种选择， 遍历出最大深度，  深度大于kk就返回。。  不能混用。。
int mxdeptha1(myvi& vi, myvvi& vvi, vector<bool>& vst, int node, int depth, int lmt, int kk)
{
    if (vvi[node].empty())
    {
        return depth;
    }
    if (vst[node])
    {
        //return depth;
        return INT_MAX;     // 有loop 长度必然大于 kk。
    }
    vst[node] = true;
    //if (depth >= kk)
    //    return depth;

    int ans = depth;
    for (int chd : vvi[node])
    {
        if (vi[chd] <= lmt)
        {
            ans = max(ans, mxdeptha1(vi, vvi, vst, chd, depth + 1, lmt, kk));
        }
    }
    return ans;
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
