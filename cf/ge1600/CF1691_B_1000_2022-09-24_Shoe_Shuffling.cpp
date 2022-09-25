
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








// 173314031 	Sep/24/2022 19:23UTC+8 	Ouha 	1691B - Shoe Shuffling 	GNU C++17 	Accepted 	218 ms 	1200 KB

void fun1()
{
    int sz1;
    cin >> sz1;

    //myvi vi(sz1);
    //for (int i = 0; i < sz1; ++i)
    //    cin >> vi[i];

    vector<pair<int, int>> vp(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vp[i].first;
        vp[i].second = i;
    }

    if (sz1 < 2)
    {
        cout << -1 << endl;
        return;
    }

    sort(begin(vp), end(vp));
    
    myvi ans(sz1);

    int sti = 0;
    
    for (int i = 0; i < sz1 - 1; ++i)
    {
        if (vp[i].first != vp[i + 1].first)
        {
            if (i == sti)
            {
                cout << -1 << endl;
                return;
            }
            ans[vp[i].second] = vp[sti].second;
            sti = i + 1;
        }
        else
        {
            ans[vp[i].second] = vp[i + 1].second;
        }
    }
    if (sti == sz1 - 1)
    {
        cout << -1 << endl;
        return;
    }
    ans[vp[sz1 - 1].second] = vp[sti].second;

    for (int i : ans)
        cout << i + 1 << ' ';
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
