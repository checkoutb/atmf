
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
#include <limits.h>   // INT_MAX

//#include <stack>
//#include <bitset>
#include <set>
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






// error

bool dfsa1(myvvi& vvi, set<int>& frd, int node, int par, int stp, vector<int>& v2);
int dfsa2(myvvi& vvi, int node, int par, vector<int>& v2);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    
    myvi vi(sz2);       // friend
    myvvi vvi(sz1 + 1);
    int a, b;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> vi[i];
    }
    for (int i = 1; i < sz1; ++i)
    {
        cin >> a >> b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }
    set<int> frd(begin(vi), end(vi));

    // -2: init, -1: not exist
    vector<int> v2(sz1 + 1, -2);            // min length to depth friend
    for (int i : vi)
        v2[i] = 0;
    
    for (int nxt : vvi[1])
    {
        if (dfsa1(vvi, frd, nxt, 1, 1, v2))
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

bool dfsa1(myvvi& vvi, set<int>& frd, int node, int par, int stp, vector<int>& v2)
{
    if (v2[node] >= 0 && v2[node] <= stp)
        return false;
    if (vvi[node].size() == 1)
        return true;
    if (vvi[node].size() == 2)
        return dfsa1(vvi, frd, vvi[node][vvi[node][0] == par], node, stp + 1, v2);

    if (v2[node] == -2)
        dfsa2(vvi, node, par, v2);

    for (int nxt : vvi[node])
    {
        if (nxt == par)
            continue;
        
        if (dfsa1(vvi, frd, nxt, node, stp + 1, v2))
            return true;

    }
    return false;
}

int dfsa2(myvvi& vvi, int node, int par, vector<int>& v2)
{
    if (v2[node] != -2)
        return v2[node];
    if (vvi[node].size() == 1)
        return -1;

    int mn = INT_MAX;
    int t2 = 0;
    for (int nxt : vvi[node])
    {
        if (par == nxt)
            continue;

        t2 = dfsa2(vvi, nxt, node, v2);
        if (t2 > -1)
            mn = min(mn, t2 + 1);
    }
    if (mn != INT_MAX)
        v2[node] = mn;
    else
        v2[node] = -1;

    return v2[node];  
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
