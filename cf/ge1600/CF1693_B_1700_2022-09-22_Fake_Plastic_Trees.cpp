
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








// 173065139 	Sep/22/2022 21:25UTC+8 	Ouha 	1693B - Fake Plastic Trees 	GNU C++17 	Accepted 	920 ms 	24400 KB

ll dfsa1(myvvi& chd, myvvi& lmt, int node, int& ans);

void fun1()
{
    int sz1;
    cin >> sz1;

    // root 0
    myvi vi(sz1);       // parent node, 
    
    for (int i = 1; i < sz1; ++i)
    {
        cin >> vi[i];
        --vi[i];
    }
    
    //vector<pair<int>> vp(sz1);      // limit
    myvvi vvi(sz1, myvi(2));
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vvi[i][0] >> vvi[i][1];
    }

    myvvi chd(sz1);
    for (int i = 1; i < sz1; ++i)
    {
        chd[vi[i]].push_back(i);
    }
    int ans = 0;
    
    dfsa1(chd, vvi, 0, ans);

    cout << ans << endl;
}

ll dfsa1(myvvi& chd, myvvi& lmt, int node, int& ans)
{
    if (chd[node].empty())
    {
        ++ans;
        return lmt[node][1];
    }

    ll sum2 = 0LL;

    for (int child : chd[node])
    {
        sum2 += dfsa1(chd, lmt, child, ans);
    }

    if (sum2 < lmt[node][0])
    {
        ++ans;
        sum2 = lmt[node][1];
    }
    else if (sum2 > lmt[node][1])
    {
        sum2 = lmt[node][1];
    }
    else
    {
        ;
    }
    return sum2;
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
