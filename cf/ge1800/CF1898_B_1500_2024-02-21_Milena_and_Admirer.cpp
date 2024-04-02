
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








// AC

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    std::vector<int> vi(sz1, 0);
    for (int i = 0; i < sz1; ++i)
        cin>>vi[i];
    
    int mx = vi[sz1 - 1];
    long long ans = 0LL;
    for (int i = sz1 - 2; i >= 0; --i)
    {
        if (vi[i] <= mx)
        {
            mx = vi[i];
        }
        else
        {
            ans += (vi[i] - 1) / mx;
            mx = vi[i] / ((vi[i] - 1) / mx + 1);
        }
    }
    
    std::cout<<ans<<std::endl;
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
