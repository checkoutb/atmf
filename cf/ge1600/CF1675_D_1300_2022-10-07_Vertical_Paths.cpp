
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


// D

//std::vector<int> p(n);
//std::vector<bool> leaf(n, true);
//for (int i = 0; i < n; i++) {
//    std::cin >> p[i];
//    p[i]--;
//    if (p[i] != i) {
//        leaf[p[i]] = false;
//    }
//}
//std::vector<bool> vis(n);
//
//std::cout << std::count(leaf.begin(), leaf.end(), true) << "\n";
//
//for (int i = 0; i < n; i++) {
//    if (leaf[i]) {
//        std::vector<int> a;
//        for (int j = i; !vis[j]; j = p[j]) {
//            vis[j] = true;
//            a.push_back(j);
//        }
//        std::reverse(a.begin(), a.end());
//        std::cout << a.size() << "\n";
//        for (auto x : a) {
//            std::cout << x + 1 << " \n"[x == a.back()];
//        }
//    }
//}






// 174923028 	Oct/07/2022 11:21UTC+8 	Ouha 	1675D - Vertical Paths 	GNU C++17 	Accepted 	1435 ms 	23600 KB
// 9514

//void dfsa1(myvvi& vvi, int node);

void dfsa2(myvvi& vvi, int node, myvvi& ans);

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);

    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
        --vi[i];
    }
    
    int rot = -1;
    myvvi vvi(sz1);
    int cnt = sz1;
    for (int i = 0; i < sz1; ++i)
    {
        if (vi[i] == i)
        {
            rot = i;
        }
        else
        {
            if (vvi[vi[i]].empty())
                --cnt;
            vvi[vi[i]].push_back(i);
        }
    }
    
    //cout << cnt << endl;

    //dfsa1(vvi, rot);

    myvvi ans(1);

    dfsa2(vvi, rot, ans);

    cout << ans.size() - 1 << endl;

    for (myvi& vi : ans)
    {
        if (vi.empty())
        {
            cout << endl;
        }
        else
        {
            cout << vi.size() << endl;
            for (int i : vi)
            {
                cout << i << ' ';
            }
            cout << endl;
        }
    }
}

void dfsa2(myvvi& vvi, int node, myvvi& ans)
{
    if (vvi[node].empty())
    {
        ans[ans.size() - 1].push_back(node + 1);
        ans.push_back(vector<int>());
        return;
    }
    ans[ans.size() - 1].push_back(node + 1);
    for (int chd : vvi[node])
    {
        dfsa2(vvi, chd, ans);
    }
}

//// xx+" "
//void dfsa1(myvvi& vvi, int node)
//{
//    if (vvi[node].empty())
//    {
//        cout << node + 1 << endl;
//        return;
//    }
//    cout << node + 1 << ' ';
//    for (int chd : vvi[node])
//    {
//        dfsa1(vvi, chd);
//    }
//}


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
