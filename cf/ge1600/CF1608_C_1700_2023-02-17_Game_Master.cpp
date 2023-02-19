
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







// g

// error... y?
// Wrong answer on test 21

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    //vector<int> va(sz1);
    //vector<int> vb(sz1);
    //for (int i = 0; i < sz1; ++i)
    //{
    //    cin >> va[i];
    //}
    //for (int i = 0; i < sz1; ++i)
    //    cin >> vb[i];

    vector<pair<int, int>> vpa(sz1);
    vector<pair<int, int>> vpb(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vpa[i].first;
        vpa[i].second = i;
    }
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vpb[i].first;
        vpb[i].second = i;
    }
    
    sort(begin(vpa), end(vpa));
    sort(begin(vpb), end(vpb));

    int mxa = vpa[vpb[sz1 - 1].second].first;
    int mxb = vpb[vpa[sz1 - 1].second].first;
    int ia = sz1 - 2;
    int ib = sz1 - 2;
    bool chg = true;
    while (chg)
    {
        chg = false;
        while (ia >= 0 && vpa[ia].first >= mxa)
        {
            chg = true;
            mxb = min(mxb, vpb[vpa[ia].second].first);
            --ia;
        }
        while (ib >= 0 && vpb[ib].first >= mxb)
        {
            chg = true;
            mxa = min(mxa, vpa[vpb[ib].second].first);
            --ib;
        }
    }
    sort(begin(vpa), end(vpa), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second;  });
    sort(begin(vpb), end(vpb), [](const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second < p2.second;  });

    string ans(sz1, '0');
    for (int i = 0; i < sz1; ++i)
    {
        if (vpa[i].first >= mxa)
            ans[i] = '1';
        else if (vpb[i].first >= mxb)
            ans[i] = '1';
    }
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
