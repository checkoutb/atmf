
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

// D D

// m = (n-1)/2;
// (1,3m+3),(2,3m+4),бн(m,4m+2),(m+1,2m+2),(m+2,2m+3),бн(2m+1,3m+2)






// 194897639 	Feb/25/2023 17:42UTC+8 	Ouha 	1788C - Matching Numbers 	GNU C++17 	Accepted 	296 ms 	0 KB
// 11015


// 6: 24,16,35
// min + max = avg
// min+1, max-2  min+max, min+2,mx-1
// 1-8  36
// 1-10 55        2+   1+11  3+10  5+9  7+8
// 4+ 2+8 1+10 3+9 5+8
// 2+7 4+6 1+10 3+9 5+8
// 2+10 4+9 6+8 1+14 3+13 5+12 7+11
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    if (sz1 == 1)
    {
        cout << "yes" << endl;
        cout << 1 << ' ' << 2 << endl;
        return;
    }
    if (sz1 % 2 == 0)
    {
        cout << "no" << endl;
        return;
    }
    
    cout << "yes" << endl;
    cout << 1 << ' ' << sz1 * 2 << endl;
    int a{ 1 }, t2{ 1 + sz1 * 2 };
    for (int i = 0; i < sz1 / 2; ++i)
    {
        a += 2;
        ++t2;
        cout << a << ' ' << t2 - a << endl;
    }
    a = 2, t2 = 1 + sz1 * 2 - sz1 / 2;
    for (int i = 0; i < sz1 / 2; ++i)
    {
        cout << a << ' ' << t2 - a << endl;
        a += 2;
        ++t2;
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
