
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







void fun1()
{
    int sz1;
    cin >> sz1;

    vector<int> vi(sz1 + 1);            // count of child
    vi[0] = 1;
    int t2 = 0;
    for (int i = 1; i < sz1; ++i)
    {
        cin >> t2;
        ++vi[t2];
    }
    sort(rbegin(vi), rend(vi));
    while (vi.back() == 0)
        vi.pop_back();
    int st = 1;
    int en = sz1;
    int ans = INT_MAX;
    while (st <= en)
    {
        int md = (st + en) / 2;
        int tm = 0;
        int used = 0;
        for (int i = 0; i < vi.size() && used <= md; ++i)
        {

        }
        if (used <= md)
        {
            ans = min(ans, md);
            en = md - 1;
        }
        else
        {
            st = md + 1;
        }
    }
    cout << ans << endl;;
}


// error
void fun1_1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1 + 1);
    for (int i = 2; i <= sz1; ++i)
    {
        cin >> vi[i];
    }
    
    vector<int> chd(sz1 + 1);
    for (int i = 2; i <= sz1; ++i)
    {
        chd[vi[i]]++;
    }
    chd[0] = 1;

    vector<pair<int, int>> vp;
    for (int i = 0; i <= sz1; ++i)
    {
        if (chd[i] != 0)
        {
            vp.push_back({ chd[i], i });
        }
    }

    sort(begin(vp), end(vp));

    reverse(begin(vp), end(vp));

    int ans = 0;

    int tm = 0;

    //for (int i = 0; i < vp.size(); ++i)
    //{
    //    ans = max(ans, tm + vp[i].first);
    //    ++tm;
    //}



    cout << ans << endl;
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
