
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








void fun1()
{
    int sz1, kk;
    cin >> sz1 >> kk;

    vector<long long> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    vector<long long> v2(sz1, 0LL);

    long long car = 0LL;
    long long ans = 0LL;
    priority_queue<int> priq;

    for (int i = sz1 - 1; i >= kk - 1; --i)
    {

    }

    for (int i = 0; i < kk - 1; ++i)
    {

    }

    return ans;
}



// tle
void fun1__()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;

    vector<long long> vi(sz1);

    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    vector<long long> v2(sz1, 0);
    long long ans = 0LL;
    for (int i = sz1 - 1; i >= kk - 1; --i)
    {
        if (vi[i] > v2[i])
        {
            long long cnt = (vi[i] - v2[i] - 1) / kk + 1;
            ans += cnt;
            for (int j = 1; j <= kk; ++j)
            {
                v2[i - kk + j] += cnt * j;
            }
        }
    }
    
    for (int i = 0; i < kk - 1; ++i)
    {
        if (vi[i] > v2[i])
        {
            long long cnt = (vi[i] - v2[i] - 1) / (i + 1) + 1;
            ans += cnt;
            for (int j = i + 1; j < kk; ++j)
            {
                v2[j] += cnt * (j + 1);
            }
        }
    }
    
    cout << ans << endl;
}


int main()
{
    int w = 1;
    //cin>>w;
    
    
    
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
