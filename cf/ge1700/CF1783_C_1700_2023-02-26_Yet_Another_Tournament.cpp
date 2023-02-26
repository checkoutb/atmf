
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









// error ,..   2 0 + {1,0} => 1  ???????
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vi[i];
    }
    sort(begin(vi), end(vi));
    
    myvi wcnt(sz1);
    for (int i = 1; i < sz1; ++i)
    {
        while (i < sz1 && vi[i] == vi[i - 1])
        {
            wcnt[i] = wcnt[i - 1];
            ++i;
        }
        if (i < sz1)
            wcnt[i] = i;
    }
    
    int idx = 0;
    while (idx < sz1 && kk >= vi[idx])
    {
        kk -= vi[idx];
        ++idx;
    }
    if (idx < sz1 && idx > 0 && (kk + vi[idx - 1]) >= vi[idx])
    {
        swap(wcnt[idx], wcnt[idx - 1]);
        //++idx;
    }

    for (int i = idx; i < sz1; ++i)
        ++wcnt[i];

    myvi::iterator it = upper_bound(begin(wcnt), end(wcnt), idx);
    cout << sz1 - (std::distance(begin(wcnt), it)) + 1 << endl;


    //cout << sz1 - idx + 1 << endl;

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
