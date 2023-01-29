
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







// crazy fix
//186544160 	Dec / 24 / 2022 15:30UTC + 8 	Ouha 	1666L - Labyrinth 	GNU C++17 	Accepted 	546 ms 	22100 KB

bool dfsb2(vector<vector<int>>& vvi, vector<int>& vst, int node, int parent, int tar, vector<int>& ans2);
bool dfsb1(vector<vector<int>>& vvi, vector<int>& vi, int node, int parent, int& st, int flg, vector<int>& ans);

void fun1()
{
    int sz1, sz2, st;
    cin >> sz1 >> sz2 >> st;

    vector<vector<int>> vvi(sz1 + 1);

    int t2, t3;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> t2 >> t3;
        vvi[t2].push_back(t3);
    }

    vector<int> ans;
    vector<int> vi(sz1 + 1);
    for (int nxt : vvi[st])
    {
        if (dfsb1(vvi, vi, nxt, st, st, nxt, ans))
        {
            int en = ans[0];
            int flg = vi[en];

            vector<int> ans2;
            vector<int> vst(sz1 + 1);
            vst[st] = 1;
            dfsb2(vvi, vst, flg, st, en, ans2);

            if (ans2.empty())
            {
                ans2.push_back(flg);
            }

            ans.push_back(st);
            ans2.push_back(st);

            cout << "Possible" << endl;
            cout << ans.size() << endl;
            for (int i = ans.size() - 1; i >= 0; --i)
            {
                cout << ans[i] << ' ';
            }
            cout << endl;

            cout << ans2.size() << endl;
            for (int i = ans2.size() - 1; i >= 0; --i)
            {
                cout << ans2[i] << ' ';
            }
            cout << endl;
            return;
        }
    }

    cout << "Impossible" << endl;
}

bool dfsb2(vector<vector<int>>& vvi, vector<int>& vst, int node, int parent, int tar, vector<int>& ans2)
{
    if (vst[node] != 0)
        return false;
    vst[node] = 1;

    for (int nxt : vvi[node])
    {
        if (nxt == parent)
            continue;

        if (nxt == tar)
        {
            ans2.push_back(nxt);
            ans2.push_back(node);
            return true;
        }

        if (dfsb2(vvi, vst, nxt, node, tar, ans2))
        {
            ans2.push_back(node);
            return true;
        }
    }
    return false;
}

bool dfsb1(vector<vector<int>>& vvi, vector<int>& vi, int node, int parent, int& st, int flg, vector<int>& ans)
{
    if (vi[node] != 0 && vi[node] != flg)       // ..
    {
        ans.push_back(node);
        return true;
    }
    if (vi[node] == 0)
        vi[node] = flg;
    for (int nxt : vvi[node])
    {
        //if (vi[nxt] == 0)
        //    vi[nxt] = flg;

        if (nxt == parent || nxt == st)
            continue;

        if (vi[nxt] != 0)
        {
            if (vi[nxt] != flg)
            {
                ans.push_back(nxt);
                ans.push_back(node);
                return true;
            }
            else
            {
                continue;
            }
        }

        vi[nxt] = flg;

        if (dfsb1(vvi, vi, nxt, node, st, flg, ans))
        {
            ans.push_back(node);
            return true;
        }
    }
    return false;
}







bool dfsa1(vector<vector<int>>& vvi, vector<int>& vi, int node, int parent, int& st);

// error
void fun1_1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    cin >> kk;

    vector<vector<int>> vvi(sz1 + 1);

    int t2, t3;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> t2 >> t3;
        vvi[t2].push_back(t3);
//        vvi[t3].push_back(t2);        // ...
    }
    
    vector<int> vi(sz1 + 1);
    
    dfsa1(vvi, vi, kk, -1, kk);
    
    if (vi[kk] == 0)
    {
        cout << "Impossible" << endl;
        return;
    }
    cout << "Possible" << endl;

    vector<int> v2;
    int i = kk;

    for (; vi[vi[i]] != kk; i = vi[i])
    {
        v2.push_back(i);
    }

    cout << 3 << endl;
    cout << kk << ' ' << vi[i] << ' ' << i << endl;

    cout << v2.size() << endl;
    for (int i = 0; i < v2.size(); ++i)
    {
        cout << v2[i] << ' ';
    }
    cout << i;
    cout << endl;

}

bool dfsa1(vector<vector<int>>& vvi, vector<int>& vi, int node, int parent, int& st)
{
    for (int nxt : vvi[node])
    {
        if (nxt == parent)
            continue;

        if (nxt == st)
        {
            vi[st] = node;
            return true;
        }

        if (vi[nxt] != 0)
            continue;

        vi[nxt] = node;

        if (dfsa1(vvi, vi, nxt, node, st))
        {
            return true;
        }

        vi[nxt] = 0;
    }
    return false;
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
