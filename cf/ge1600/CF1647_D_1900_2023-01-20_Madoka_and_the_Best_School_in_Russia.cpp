
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

// D D

// This is     e a s i l y     solved by dynamic programming. Let dpn,d be the number of factorizations
// . not easy .


// 189811221 	Jan / 20 / 2023 14:44UTC + 8 	Ouha 	1647D - Madoka and the Best School in Russia 	GNU C++17 	Accepted 	15 ms 	0 KB


// good : d*N
// beautiful : d*N & !(good * good)    !(d*N * d*M)  !(d^2 * X)
//      multiple of d , not multiple of d^2
// x : good : d*N
//      beautiful (* beautiful *... beautiful)
//      (d*N not d^2*N) * (d*N not d^2*N) * ...
//       d^odd != d^2 * N    no  d^odd = d^even * d
//      !d * d * N != d^2 * N ,,  no  N = !d * N
// prime?
// beautiful <=> d*N && (!d^2 * N)
// d * d * d * d * C = q*w*e*r*C  (q=w=e=r = d)   , C != d*N   C%d != 0
//  d is beautiful, q w e r is beautiful
// so
//      if count of d == 1, no
//          >= 2,  d * d * d * C . [d,d,d,d*C]   C is prime?
//   36 = 2 2 3 3 = 2 2 9   [2, 2*9]   9 is not prime, 9=3*3 [2*3, 2*3]
// 1000 = 10 10 10 =   [10,10,10] [10*2, 10*5]
// 6 6 6 11 = 2376  [6 6 6*11] [6*2 3*6*11]
// 128 = 4 4 4 2 ... 
// 19683 9   = 9 9 9 9 3    [9 9 9 27] [27 27 27] .....
void fun1()
{
    //int sz1, sz2, kk;
    //cin >> sz1;
    
    int x, d;
    cin >> x >> d;
    
    int cnt = 0;
    while (x % d == 0)
    {
        ++cnt;
        x /= d;
    }
    
    if (x == 1)
    {
        if (cnt <= 2)
        {
            cout << "NO" << endl;
            return;
        }
        --cnt;
        x = d;
    }

    if (cnt == 1)
    {
        cout << "NO" << endl;
        return;
    }
    
    int sqt = std::sqrt(x);
    for (int i = 2; i <= sqt; ++i)
    {
        if (x % i == 0)
        {
            cout << "YES" << endl;
            return;
        }
    }

    if (cnt >= 3)
    {
        sqt = std::sqrt(d);
        for (int i = 2; i <= sqt; ++i)
        {
            if (d % i == 0)
            {
                //if (i == x || (d % i) == x)
                //    continue;

                if (cnt == 3 && ((i * x) % d == 0 && ((d / i * x) % d == 0)))
                {
                    continue;
                }

                cout << "YES" << endl;
                return;
            }
        }
    }

    cout << "NO" << endl;
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
