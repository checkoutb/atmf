
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






// 190615776 	Jan/26/2023 13:53UTC+8 	Ouha 	1624G - MinOr Tree 	GNU C++17 	Accepted 	1014 ms 	9200 KB

// bu, bushi meige bit, ershi zhege bit hou quan 1.
bool connectedb1(myvvi& vvi, int t2, int sz1);
int ufa1(vector<int>& uf, int idx);
void fun1()
{
    int sz1, sz2;
    cin >> sz1 >> sz2;
    myvvi vvi(sz2, myvi(3));
    for (int i = 0; i < sz2; ++i)
    {
        cin >> vvi[i][0] >> vvi[i][1] >> vvi[i][2];
    }
    
    int ans = 0;
    for (int i = 30; i >= 0; --i)
    {
        int t2 = ans | ((1 << (i)) - 1);

        if (!connectedb1(vvi, t2, sz1))
        {
            ans |= (1 << (i));
        }
    }
    cout << ans << endl;
}

bool connectedb1(myvvi& vvi, int t2, int sz1)
{
    vector<int> uf(sz1 + 1, -1);
    int a, b;
    for (myvi& vi : vvi)
    {
        if (vi[2] != (t2 & vi[2]))
            continue;

        a = ufa1(uf, vi[0]);
        b = ufa1(uf, vi[1]);

        if (a != b)
            uf[a] = b;
    }

    int tp = ufa1(uf, 1);

    for (int i = 2; i <= sz1; ++i)
        if (ufa1(uf, i) != tp)
            return false;
    return true;
}

// error, san jiao xing + 1 dian 1 bian, e wai de bian quan'zhong zui da.
// bu, zenme ganjue keyi dui meige bit jisuan ?
bool connecteda1(vector<vector<int>>& vvi, int mxwg, int sz1);
void fun1__()
{
    int sz1, sz2, kk;
    cin >> sz1; // node
    cin >> sz2; // edge

    //// st, en, weight
    vector<vector<int>> vvi(sz2, vector<int>(3));
    int mxwg = 0;
    for (int i = 0; i < sz2; ++i)
    {
        cin >> vvi[i][0] >> vvi[i][1] >> vvi[i][2];
        mxwg = max(mxwg, vvi[i][2]);
    }

    //vector<vector<pair<int, int>>> vvp(sz1 + 1);
    int st, en, wg;
    //int mxwg = 0;
    //for (int i = 0; i < sz2; ++i)
    //{
    //    cin >> st >> en >> wg;
    //    vvi[st].push_back(std::make_pair(en, wg));
    //    vvi[en].push_back(std::make_pair(st, wg));
    //    mxwg = max(mxwg, wg);
    //}
    
    st = 1;
    en = mxwg;
    int ans = -1;
    while (st <= en)
    {
        int md = (st + en) / 2;     // max weight

        if (connecteda1(vvi, md, sz1))
        {
            ans = md;
            en = md - 1;
        }
        else
        {
            st = md + 1;
        }
    }
    // cout<<
}

int ufa1(vector<int>& uf, int idx)
{
    return uf[idx] == -1 ? idx : (uf[idx] = ufa1(uf, uf[idx]));
}

//bool connecteda1(vector<vector<pair<int, int>>>& vvp, int mxwg, int sz1)
bool connecteda1(vector<vector<int>>& vvi, int mxwg, int sz1)
{
    vector<int> uf(sz1 + 1, -1);

    int a, b;
    for (myvi& vi : vvi)
    {
        if (vi[2] > mxwg)
            continue;
        a = ufa1(uf, vi[0]);
        b = ufa1(uf, vi[1]);
        if (a != b)
            uf[a] = b;
    }

    int tp = uf[1];
    if (tp == -1)
        return false;

    for (int i = 2; i <= sz1; ++i)
        if (uf[i] != tp)
            return false;
    return true;
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
