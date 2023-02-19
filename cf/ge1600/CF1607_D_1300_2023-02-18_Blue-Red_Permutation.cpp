
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








// 194069366 	Feb/18/2023 12:57UTC+8 	Ouha 	1607D - Blue-Red Permutation 	GNU C++17 	Accepted 	405 ms 	3100 KB
// 14370

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    string s;
    cin >> s;

    myvi vb;
    myvi vr;

    for (int i = 0; i < sz1; ++i)
    {
        if (s[i] == 'R')
            vr.push_back(vi[i]);
        else
            vb.push_back(vi[i]);
    }
    
    sort(begin(vr), end(vr));
    sort(begin(vb), end(vb));
    
    for (int i = 0; i < vb.size(); ++i)
    {
        if (vb[i] <= i)
        {
            cout << "NO" << endl;
            return;
        }
    }
    int szb = static_cast<int>(vb.size());
    for (int i = 0; i < vr.size(); ++i)
    {
        if (vr[i] > i + szb + 1)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
