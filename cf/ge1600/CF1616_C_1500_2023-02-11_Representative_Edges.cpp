
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
#include <map>
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

// ....
//for (int i = 0; i < n; i++) {
//    for (int j = i + 1; j < n; j++) {
//        int res = 0;
//        for (int k = 0; k < n; k++) {
//            if ((i - k) * (a[j] - a[k]) - (j - k) * (a[i] - a[k]) == 0) {
//                res++;
//            }
//        }
//        ans = std::max(ans, res);
//    }
//}






// 193176011 	Feb/11/2023 18:38UTC+8 	Ouha 	1616C - Representative Edges 	GNU C++17 	Accepted 	78 ms 	300 KB
// 10657

// [a,b,c,d,e]
// a+b=(a+b)*2/2,,, always ==
// a+b+c = (a+c)*3/2
// a+b+c+d = (a+d)*4/2 = (a+d)*2  => a+d = b+c => a+b+c=a+a+d=(a+c)*3/2  0.5a+d=1.5c
// a..e = (a+e)*5/2
// a..f = (a+f)*3 => b+c+d+e = a+f+a+f = a+d+e = afaf , de=aff
//
// a+b = a+b , b+c=b+c
// a+b+c = (a+c)1.5
// b+c+d = (d+b)1.5
// cde = (ce)1.5
// def = (df)1.5
//
// 1 1 2 2 , 1 1 1 1
// a+c = 2b <=> a+b+c=(a+c)1.5
// a+d = b+c   a-b=c-d
// 2a 2b 2c 2d 2e = 5a 5e
// ganjue shi dengcha shulie...
// 2b 2c 2d = 3a 3e
// 2c+2d = 3a-2b+3e
// 2c+2d = a + 2(c-d)+3e
// 2d = a - 2d + 3e   4d = a+3e
// b+d=2c  a-b=c-d  b-c=d-e c-d=e-f  .. zenme zhaodao  a-b=b-c ? ... jiushi  a+c=2b ....
int gcd(int a, int b);
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;

    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    if (sz1 <= 2)
    {
        cout << 0 << endl;
        return;
    }

    map<ll, int> map2;
    int df, cnt;
    long long st, bediv, div;
    bool isneg;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = i + 1; j < sz1; ++j)
        {
            df = vi[j] - vi[i];
            if (df < 0)
            {
                df = -df;
                isneg = true;
            }
            else
            {
                isneg = false;
            }
            cnt = j - i;
            bediv = df;
            div = cnt;
            int t2 = gcd(max(bediv, div), min(bediv, div));
            bediv /= t2;
            div /= t2;

            st = 1LL * vi[i] * div - 1LL * i * bediv * (isneg ? -1 : 1);

            ++map2[(isneg ? -1 : 1) * (((st * 1000) + bediv) * 1000 + div)];
        }
    }
    
    int ans = 0;
    for (auto& [k, v] : map2)
    {
        if (v > ans)
        {
            ans = v;
        }
    }
    ans = (-1 + std::sqrt(1 + 8 * ans)) / 2;
    cout << sz1 - 1 - ans << endl;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
