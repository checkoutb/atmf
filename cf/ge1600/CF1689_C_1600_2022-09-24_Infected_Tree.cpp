
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

//void dfs(int x, int y) {
//    int t = 0, a[2] = { 0,0 }, b[2] = { 0,0 };
//    for (int i : v[x])if (i != y)dfs(i, x), a[t] = f[i], b[t++] = g[i];
//    if (t == 0)f[x] = 0, g[x] = 1;
//    if (t == 1)f[x] = b[0] - 1, g[x] = b[0] + 1;
//    if (t == 2)f[x] = max(a[0] + b[1] - 1, b[0] + a[1] - 1), g[x] = b[0] + b[1] + 1;
//}







// 173377201 	Sep/25/2022 09:46UTC+8 	Ouha 	1689C - Infected Tree 	GNU C++17 	Accepted 	826 ms 	11500 KB


// ...binary tree 所以 每次可以 保护 一个叉。 只能保护 一个叉。
// 这样 到最后 就是  一条 从root 到 leaf 的 path。 最短
// 也不是， 倒V 。。  是到 第一个 null 节点？
// 对， null 节点 是死路，  就是要把 病毒 引到 死路上去。

void fun1()
{
    int sz1;
    cin >> sz1;

    myvvi vvi(sz1 + 1);
    int a, b;
    for (int i = 1; i < sz1; ++i)
    {
        cin >> a >> b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }

    vector<bool> vb(sz1 + 1, false);
    vb[1] = true;

    vector<int> vi;
    vi.push_back(1);
    int depth = 0;
    while (!vi.empty())
    {
        ++depth;
        vector<int> v2;


        // ... 4  1-2, 1-4, 3-4 .. need delete 4. not 2
        sort(begin(vi), end(vi), [&](int i, int j) { return vvi[i].size() < vvi[j].size(); });


        for (int i = 0, mxi = vi.size(); i < mxi; ++i)
        {
            int t2 = vi[i];
            if ((vvi[t2].size() <= 2 && t2 != 1) || (vvi[t2].size() == 1 && t2 == 1))         // .
            {
                int ans = sz1 - depth - depth + 1;
                if ((t2 != 1 && vvi[t2].size() == 2) || (t2 == 1))
                {
                    --ans;
                }
                cout << ans << endl;
                return;
            }
            else
            {
                for (int chd : vvi[t2])
                {
                    if (vb[chd] == false)
                    {
                        vb[chd] = true;
                        v2.push_back(chd);
                    }
                }
            }
        }
        swap(vi, v2);
    }
    cout << -1 << endl;
}



pair<int, int> dfsa1(myvvi& vvi, myvvi& vv2, int node, int parent);

// error
void fun1_error()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvvi vvi(sz1 + 1);
    int a, b;
    for (int i = 1; i < sz1; ++i)
    {
        cin >> a >> b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }
    
    //vector<pair<int, int>> vp(sz1 + 1);
    vector<vector<int>> vv2(sz1 + 1);

    dfsa1(vvi, vv2, 1, -1);
    myvi vi;
    vi.push_back(1);

    int ans = 0;
    vector<bool> vst(sz1 + 1, false);
    vst[1] = true;

    while (!vi.empty())
    {
        myvi v2;
        for (int i = 0; i < vi.size(); ++i)
        {
            for (int chd : vvi[vi[i]])
            {
                if (vst[chd] == false)
                {
                    vst[chd] = true;
                    v2.push_back(chd);
                }
            }
        }
        if (v2.empty())
            break;

        int idx = 0;
        for (int i = 1; i < v2.size(); ++i)
        {
            if (vv2[v2[i]][0] > vv2[v2[idx]][0])
            {
                idx = i;
            }
            else if (vv2[v2[i]][0] == vv2[v2[idx]][0])
            {
                if (vv2[v2[i]][1] > vv2[v2[idx]][1])
                {
                    idx = i;
                }
            }
        }
        ans += vv2[v2[idx]][1] - 1;

        v2.erase(begin(v2) + idx);

        swap(vi, v2);
    }
    cout << ans << endl;
}

// leaf-node, count sub tree, node
pair<int, int> dfsa1(myvvi& vvi, myvvi& vv2, int node, int parent)
{
    if (vvi[node].size() == 1 && node != 1)
    {
        vv2[node] = { 1,1,node };
        return std::make_pair(1, 1);
    }
    int lf = 0;
    int sub = 0;
    for (int nxt : vvi[node])
    {
        if (nxt == parent)
            continue;

        pair<int, int> p = dfsa1(vvi, vv2, nxt, node);
        lf += p.first;
        sub += p.second;
    }
    ++sub;

    vv2[node] = { lf, sub, node };

    return std::make_pair(lf, sub);
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
