
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








// tle

// > pre
// once [0] < pre, never choose [0]
// if [0] == [sz1-1]. alway choose one end
// if [0] < [sz1 - 1],  if alice choose [sz1-1], then always this end
//          if alice choose [0] ...     [1] [sz1-1] bob first
bool dfsAlice(myvi& vi, int st, int en, map<int, map<int, bool>>& mapa, int pre, map<int, map<int, bool>>& mapb);
bool dfsBob(myvi& vi, int st, int en, map<int, map<int, bool>>& mapa, int pre, map<int, map<int, bool>>& mapb);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    
    map<int, map<int, bool>> mapa;
    map<int, map<int, bool>> mapb;
    bool b2 = dfsAlice(vi, 0, sz1 - 1, mapa, -1, mapb);
    
    if (b2)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
    
}

bool dfsAlice(myvi& vi, int st, int en, map<int, map<int, bool>>& mapa, int pre, map<int, map<int, bool>>& mapb)
{
    if (st == en)
        return vi[st] > pre;
    if (vi[st] < pre && vi[en] < pre)
        return false;



    if (mapa.find(st) != mapa.end() && mapa[st].find(en) != mapa[st].end())
    {
        return mapa[st][en];
    }
    if (vi[st] < pre || vi[en] < pre)
    {
        int cnt = 0;
        if (vi[st] < pre)
        {
            while (vi[en--] > pre)
                ++cnt;
        }
        else
        {
            while (vi[st++] > pre)
                ++cnt;
        }
        mapa[st][en] = cnt % 2;
        return cnt % 2;
    }
    bool ans = false;
    //if (vi[st] > pre)
    {
        if (dfsBob(vi, st + 1, en, mapa, vi[st], mapb))
        {
            ;
        }
        else
        {
            ans = true;
        }
    }
    //if (vi[en] > pre)
    {
        if (dfsBob(vi, st, en - 1, mapa, vi[en], mapb))
        {
            ;
        }
        else
        {
            ans = true;
        }
    }
    mapa[st][en] = ans;
    return ans;
}

bool dfsBob(myvi& vi, int st, int en, map<int, map<int, bool>>& mapa, int pre, map<int, map<int, bool>>& mapb)
{
    if (st == en)
        return vi[st] > pre;

    if (vi[st] < pre && vi[en] < pre)
        return false;



    if (mapb.find(st) != mapb.end() && mapb[st].find(en) != mapb[st].end())
        return mapb[st][en];

    if (vi[st] < pre || vi[en] < pre)
    {
        int cnt = 0;
        if (vi[st] < pre)
        {
            while (vi[en--] > pre)
                ++cnt;
        }
        else
        {
            while (vi[st++] > pre)
                ++cnt;
        }
        mapb[st][en] = cnt % 2;
        return cnt % 2;
    }

    bool ans = false;
    //if (vi[st] > pre)
    {
        if (dfsAlice(vi, st + 1, en, mapa, vi[st], mapb))
        {
            ;
        }
        else
        {
            ans = true;
        }
    }
    //if (vi[en] > pre)
    {
        if (dfsAlice(vi, st, en - 1, mapa, vi[en], mapb))
        {
            ;
        }
        else
        {
            ans = true;
        }
    }
    mapb[st][en] = ans;
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
