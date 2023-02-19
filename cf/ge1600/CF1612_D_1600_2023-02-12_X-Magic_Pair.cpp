
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
#include <numeric>            // accumulate
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









// 15 23, 15 8
// 23 38, 23 15
// 10 8 
// 24 28
// a - b*N = x ... 15*3-38    a*N-b=x
// a*N - b*M = x. wo jianguo zhege ... peishu dingli.  
// you kanle yibian. buzhidao zhege dingli de hua ,wanquan meiyou banfa zuochulai ba.
// ......
void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;

    ll a, b, x;
    cin >> a >> b >> x;
    
    if (x > a && x > b)
    {
        cout << "NO" << endl;
        return;
    }

    ll t2 = std::gcd(a, b);
    
    if (x % t2 == 0LL )
    {
        //cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }

    if (a < b)
    {
        swap(a, b);
    }


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
