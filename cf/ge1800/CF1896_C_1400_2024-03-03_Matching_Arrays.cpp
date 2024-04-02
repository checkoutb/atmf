
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







// 249429948 	Practice:Ouha 	1896C - 18 	GNU C++17 	Accepted 	576 ms 	4708 KB 	2024-03-03 11:36:55 	2024-03-03 11:36:55


void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> kk;
    
    std::vector<int> va(sz1), vb(sz1);
    for (int& n : va)
        cin>>n;
    for (int& n : vb)
        cin>>n;

    std::vector<std::pair<int, int>> vp(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        vp[i].first = va[i];
        vp[i].second = i;
    }
    std::sort(std::begin(vp), std::end(vp));
    using std::sort;
    sort(begin(vb), end(vb));

    // a > b

    int ib = kk - 1;        // [<=ib] must < a,  [>ib] must >= a
    std::vector<int> vbidx(sz1, -1);
    int ia = sz1 - 1;
    while (ib >= 0) {
        if (vp[ia].first > vb[ib])
        {
            vbidx[ib] = vp[ia].second;
            --ia;
        }
        else
        {
            std::cout<<"no\n";
            return;
        }
        --ib;
    }
    ib = kk;
    ia = 0;
    while (ib < sz1) {
        if (vp[ia].first <= vb[ib])
        {
            vbidx[ib] = vp[ia].second;
            ++ia;
        }
        else
        {
            std::cout<<"no\n";
            return;
        }
        ++ib;
    }
    
    std::vector<int> ans(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        ans[vbidx[i]] = vb[i];
    }

    std::cout<<"yes\n";
    for (int i : ans)
        cout<<i<<' ';
    cout<<'\n';
    return;
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
