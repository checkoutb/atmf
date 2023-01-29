
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
#include <cmath>
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





// if (!f[j] && sum[min(c, i*j + i - 1)] - sum[i*j - 1])
// j * i <= c(kk)
// 倍数不存在，但是 积存在
// 因为 跨度，100/34 == 100/35 == 100/50 == 2。



// tle

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    
    int t2 = 0;
    vector<int> vi(kk + 1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        ++vi[t2];
    }
    
    if (vi[1] == 0)
    {
        cout << "No" << endl;
        return;
    }

    vector<int> v2;
    for (int i = 1; i <= kk; ++i)
    {
        if (vi[i] != 0)
        {
            v2.push_back(i);
        }
    }
    
//    for (int i = v2.size() - 1; i > 0; --i)
    for (int i = 1; i < v2.size(); ++i)
    {
        t2 = v2[i];
//        int sqt = std::sqrt(i);
        int sqt = t2 / 2;
        for (int j = 1; j < v2.size() && v2[j] <= sqt; ++j)
        {
            if (vi[t2 / v2[j]] == 0)
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    
    cout << "Yes" << endl;
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
