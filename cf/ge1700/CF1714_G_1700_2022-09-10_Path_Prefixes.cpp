#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")

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

#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>
//#include <unordered_map>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1


// D

// ... size为20万的单链表 dfs， 不会爆栈？






// tle ... 200000 单链表， 第二个节点的a,b 是 1, 10000000000，其它节点全是 1，1
static long long arr[200005] = { 0LL };
void fun1(myvvi& vvi)
{

    int sz1 = vvi.size();

    vector<vector<int>> chd(sz1 + 2, vector<int>());

    for (int i = 0; i < sz1; ++i)
    {
        int me = i + 2;
        int p = vvi[i][0];
        
        //chd[p].push_back(me);
        chd[p].push_back(i);
    }

    stack<vector<long long>> stk;
    vector<long long> vt = { 1, 0, 0, 0 };
    stk.push(vt);     // node , sum(a), chd[node][?], b[?]
    
    
    int st = 0;
    int en = 1;     // next insert
    
    vector<long long> ans(sz1 + 2);

    while (!stk.empty())
    {
        //vector<int> vi = stk.top();
        long long nd = stk.top()[0];
        long long sa = stk.top()[1];
        //stk.pop();
        long long idx = stk.top()[2];
        long long bi = stk.top()[3];
        if (idx >= chd[nd].size())
        {
            stk.pop();
        }
        else
        {
            long long ch = chd[nd][idx] + 2;
            stk.top()[2]++;
            arr[stk.size()] = arr[stk.size() - 1] + vvi[ch - 2][2];
            sa = sa + vvi[ch - 2][1];
            
            while (bi <= stk.size() && arr[bi] <= sa)
            {
                ++bi;           // first > sa
            }
            ans[ch] = bi - 1;
            stk.push({ch, sa, 0, bi - 1});
        }

    }

    for (int i = 2; i < ans.size(); ++i)
        cout << ans[i] << ' ';
    cout << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int w = 0;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {
        int sz1;
        cin >> sz1;

        vector<vector<int>> vvi(sz1 - 1, vector<int>(3));

        for (int i = 0; i < sz1 - 1; ++i)
        {
            cin >> vvi[i][0] >> vvi[i][1] >> vvi[i][2];
        }
        
        fun1(vvi);
        
        //cout<<endl;
    }
    
    
    return 0;
}
