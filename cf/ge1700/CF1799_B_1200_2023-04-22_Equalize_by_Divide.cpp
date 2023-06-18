
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








// 203021305 	Apr/22/2023 16:04UTC+8 	Ouha 	1799B - Equalize by Divide 	GNU C++17 	Accepted 	62 ms 	200 KB
// 8230

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;

    vector<pair<int, int>> vp(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vp[i].first;
        vp[i].second = i + 1;
    }

    sort(rbegin(vp), rend(vp));

    if (vp[0].first == vp[sz1 - 1].first)
    {
        cout << 0 << endl;
        return;
    }
    if (vp[sz1 - 1].first == 1)
    {
        cout << -1 << endl;
        return;
    }

    int mn = vp[sz1 - 1].first;
    int mni = vp[sz1 - 1].second;
    bool chg = true;
    int t2 = 0;
    vector<pair<int, int>> vans;
    while (chg)
    {
        chg = false;

        for (int i = 0; i < sz1; ++i)
        {
            if (vp[i].first == mn)
            {
                continue;
            }
            chg = true;

            t2 = vp[i].first / mn + (vp[i].first % mn != 0);
            vans.push_back(std::make_pair(vp[i].second, mni));
            vp[i].first = t2;
            if (t2 < mn)
            {
                mn = t2;
                mni = vp[i].second;
            }
        }
    }

    cout << vans.size() << endl;
    for (auto& [fst, snd] : vans)
    {
        cout << fst << ' ' << snd << endl;
    }


    //vector<int> vi(sz1);
    //for (int i = 0; i < sz1; ++i)
    //{
    //    cin >> vi[i];
    //}
    //
    //sort(rbegin(vi), rend(vi));
    //
    //if (vi[0] == vi[sz1 - 1])
    //{
    //    cout << 0 << endl;
    //    return;
    //}
    //
    //if (vi[sz1 - 1] == 1)
    //{
    //    cout << -1 << endl;
    //    return;
    //}

    //priority_queue<int> priq(begin(vi), end(vi));
    //int a, b;

    //while (!priq.empty())
    //{

    //}

    
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
