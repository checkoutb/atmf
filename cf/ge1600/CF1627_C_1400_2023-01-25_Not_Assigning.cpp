
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
#include <queue>
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







// 190458111 	Jan/25/2023 15:22UTC+8 	Ouha 	1627C - Not Assigning 	GNU C++17 	Accepted 	296 ms 	4900 KB

// 2 + 5 = 7
// !2 + !2 = even, not prime.
// degree >= 3, No.
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    //vector<vector<int>> vvi(sz1 + 1);
    vector<vector<pair<int, int>>> vvp(sz1 + 1);
    int a, b;
    for (int i = 0; i < sz1 - 1; ++i)
    {
        cin >> a >> b;
        vvp[a].push_back(std::make_pair(b, i));
        vvp[b].push_back(std::make_pair(a, i));

        //vvi[a].push_back(b);
        //vvi[b].push_back(a);
    }
    
    for (int i = 1; i <= sz1; ++i)
    {
        if (vvp[i].size() >= 3)
        {
            cout << -1 << endl;
            return;
        }
    }
    
    vector<int> vi(sz1 - 1);

    queue<int> que;
    //que.push(1);
    if (vvp[1].size() == 1)
    {
        vi[vvp[1][0].second] = 2;
        que.push(vvp[1][0].first);
    }
    else
    {
        vi[vvp[1][0].second] = 2;
        vi[vvp[1][1].second] = 5;
        que.push(vvp[1][0].first);
        que.push(vvp[1][1].first);
    }
    
    while (!que.empty())
    {
        int tp = que.front();
        que.pop();

        if (vvp[tp].size() == 1)
            continue;

        if (vi[vvp[tp][0].second] != 0)
        {
            vi[vvp[tp][1].second] = 7 - vi[vvp[tp][0].second];
            que.push(vvp[tp][1].first);
        }
        else
        {
            vi[vvp[tp][0].second] = 7 - vi[vvp[tp][1].second];
            que.push(vvp[tp][0].first);
        }
    }

    for (int i : vi)
        cout << i << ' ';
    cout << endl;
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
