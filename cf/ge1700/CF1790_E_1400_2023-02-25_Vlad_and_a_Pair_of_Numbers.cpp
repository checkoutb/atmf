
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

//cin >> x;
//if (x % 2 == 1) {
//    cout << -1 << '\n';
//    continue;
//}
//int a = x / 2;
//int b = x / 2;
//if (a & x) {
//    cout << -1 << '\n';
//    continue;
//}
//cout << a + x << " " << b << '\n';


//int a = 0, b = 0;
//for (int i = 0; i < 30; i++) {
//    if (x >> i & 1) {
//        if (i == 0 || (x >> (i - 1) & 1)) {
//            std::cout << -1 << "\n";
//            return;
//        }
//        a |= 1 << i | 1 << (i - 1);
//        b |= 1 << (i - 1);
//    }
//}




// 194893229 	Feb/25/2023 17:00UTC+8 	Ouha 	1790E - Vlad and a Pair of Numbers 	GNU C++17 	Accepted 	62 ms 	0 KB
// 9380


// kk = a^b = (a+b)/2
// different
// kk' bit == 1 => 1,0 .. don't care a is 1 or a is 0.. both ok
//         == 0 => 1,1 or 0,0
// kk << 1 == a+b
// bit
void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    cin >> kk;

    if (kk % 2)
    {
        cout << -1 << endl;
        return;
    }

    int kk2 = kk << 1;
    int car = 0;
    int t2, t3;
    int a{ 0 }, b{ 0 };
    for (int i = 30; i >= 0; --i)
    {
        t2 = kk2 & (1 << i);
        t3 = kk & (1 << i);
        if (t3)     // diff
        {
            if (t2)         // remain 1
            {
                if (car)        // carry 1
                {
                    cout << -1 << endl;
                    return;
                }
                else
                {
                    a |= (1 << i);
                }
            }
            else
            {
                if (car)
                {
                    a |= (1 << i);
                }
                else
                {
                    cout << -1 << endl;
                    return;
                }
            }
        }
        else     // same
        {
            if (t2)
            {
                if (car)
                {
                    a |= (1 << i);
                    b |= (1 << i);
                }
                else
                {
                    car = 1;
                }
            }
            else
            {
                if (car)
                {
                    a |= (1 << i);
                    b |= (1 << i);
                    car = 0;
                }
                else
                {
                    ;
                }
            }
        }
    }
    if (car != 0)
        cout << -1 << endl;
    else
        cout << a << ' ' << b << endl;
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
