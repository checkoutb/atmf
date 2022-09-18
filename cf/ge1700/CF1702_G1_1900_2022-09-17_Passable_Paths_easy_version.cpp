
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
//..
// easy 是 尝试 把 一端 作为root，然后找到 最深的  作为 另一端，然后。。
// hard 是 lca ，然后 。。
// 2者 都需要 记录下 每个 结点的深度。




// tle in hard version

// 172455707 	Sep/17/2022 20:43UTC+8 	Ouha 	1702G1 - Passable Paths (easy version) 	GNU C++17 	Accepted 	888 ms 	25100 KB

pair<bool, int> dfsa1(myvvi& vv, int idx, vector<bool>& vb, int sz2, int parent);

int ufa(myvi& uf, int idx)
{
    if (uf[idx] == 0)
        return idx;
    return ufa(uf, uf[idx]);
}

// LCA
void fun1()
{
    int sz1;
    cin>>sz1;

    #ifdef __test
//    cout<<" 111st "<<sz1<<endl;
    #endif // __test

    vector<int> vi(sz1 + 1);
    vector<int> uf(sz1 + 1);
    int a, b, aa, bb;

//    for (int i = 1; i < sz1; ++i)           // i = 1....
//    {
//        cin>>a>>b;
//        aa = ufa(uf, a);
//        bb = ufa(uf, b);
//        if (aa == 1)
//        {
//            if (vi[b] != 0)
//            {
//                int pre = b;
//                int x = vi[b];
//                while (x != 0)
//                {
//                    int t2 = vi[x];
//                    vi[x] = pre;
//                    pre = x;
//                    x = t2;
//                }
//            }
//            vi[b] = a;
//            uf[bb] = aa;
//        }
//        else if (bb == 1)
//        {
//            if (vi[a] != 0)
//            {
//                int pre = a;
//                int x = vi[a];
//                while (x != 0)
//                {
//                    int t2 = vi[x];
//                    vi[x] = pre;
//                    pre = x;
//                    x = t2;
//                }
//            }
//            vi[a] = b;
//            uf[aa] = bb;
//        }
//        else
//        {
//            if (vi[a] != 0)
//            {
//                int pre = a;
//                int x = vi[a];
//                while (x != 0)
//                {
//                    int t2 = vi[x];
//                    vi[x] = pre;
//                    pre = x;
//                    x = t2;
//                }
//            }
//
//            vi[a] = b;
//            uf[aa] = bb;
//        }
//    }
//
//    myvvi vv(sz1 + 1);
//    for (int i = 2; i <= sz1; ++i)
//    {
//        vv[vi[i]].push_back(i);
//    }

    myvvi vv(sz1 + 1);
    for (int i = 1; i < sz1; ++i)
    {
        cin>>a>>b;
        vv[a].push_back(b);
        vv[b].push_back(a);         // + dfsa1(... parent)
    }

    int qsz;
    cin>>qsz;

    #ifdef __test
//    cout<<" . "<<qsz<<endl;
    cout<<" ----- chd -- "<<endl;
    for (int i = 1; i <= sz1; ++i)
    {
        cout<<i<<" : [";
        for (int a : vv[i])
            cout<<a<<", ";
        cout<<"]"<<endl;
    }
    #endif // __test

    while (qsz-- > 0)
    {
        vector<bool> vb(sz1 + 1);
        int sz2;
        cin>>sz2;

        #ifdef __test
//        cout<<" - "<<sz2<<endl;
        #endif // __test

        //while (sz2-- > 0)
        for (int q = 0; q < sz2; ++q)
        {
            int t2;
            cin>>t2;
            vb[t2] = true;
        }

        #ifdef __test
//        cout<<" ======== "<<endl;
//
//        cout<<" -------------"<<endl;
        #endif // __test

        pair<bool, int> p = dfsa1(vv, 1, vb, sz2, 0);
        cout<<(p.first ? "yes" : "no")<<endl;
    }

}

// <can, count>
pair<bool, int> dfsa1(myvvi& vv, int idx, vector<bool>& vb, int sz2, int parent)
{
    pair<bool, int> ans = {true, 0};
    int cnt = 0;
    for (int i = 0; i < vv[idx].size(); ++i)
    {
        if (vv[idx][i] == parent)
            continue;

        pair<bool, int> p = dfsa1(vv, vv[idx][i], vb, sz2, idx);
        if (p.first == false)
        {
            ans.first = false;
            break;
        }
        if (p.second > 0)
        {
            if (cnt == 0)
            {
                ans.second = p.second;
            }
            else if (cnt > 1)       // dead code
            {
                ans.first = false;
                break;
            }
            else
            {
                // cnt == 1
                int t2 = ans.second + p.second + vb[idx];
                if (t2 != sz2)
                {
                    ans.first = false;
                    break;
                }
                ans.second += p.second;
            }
            ++cnt;
        }
    }

    ans.second += vb[idx];
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

        //cout<<endl;
    }


    return 0;
}
