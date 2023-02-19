
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



// D
// ¿¼ÂÇ 6 100. 6-12-16...96   100-96/2     98%6 == 100%98




// wrong answer come up with a better solution (test case 922)


// ans mod a = b mod ans = x
// a*N + x = ans, ans*N + x = b
// x = ans - a*N = b - ans*N
// even
// ans*(N+1) = b + a*N
// ans = (b + a*N) / (N+1)     , N!=N
// ans = (b + a*n) / (m+1) ... not <=>
//
// if n < (min(x, y)), n % x = n = y % n,    y%n < n, so y%n != n..  n always >= min(x,y)
// n > max(), n % x = y .. n%x<x, so need x>y  ..  n = x+y
// min < n < max 
//          x < y, x < n < y,  ???
//          x > y, n = x + y
// n = min
//          x < y,  x=n<y     y = x*N
// n = max
//          x < y, x<y=n      y = x*N
void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;

    int a, b;
    cin >> a >> b;

    if (a == b)
    {
        cout << a << endl;
        return;
    }
    if (b % a == 0)
    {
        cout << a << endl;
        return;
    }
    if (a > b)
    {
        cout << a + b << endl;
        return;
    }

    cout << (a + b) / 2 << endl;
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
