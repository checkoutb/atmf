
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

//for (int i = 1; i <= n; i++) {
//    int x; cin >> x;
//    bool found = false;
//    for (int j = i + 1; j >= 2; j--) { // this loop will run not more than 22 times, in practice its much lower than that
//        if (x % j) {
//            found = true;

// 看起来，是 从小到大 合算。
// LCM(2,3,..23) > 10^9。 最小公倍数
// 不，从大到小合算。 LCM(2,3,4,5,6) 应该< LCM(12,13,14,15,16)
// 举LCM(2,3,...23) 的例子 是为了说明 最多情况下 是 2,3,..23 。


//int n;
//read(n);
//for (int i = 1; i <= n; ++i)read(a[i]);
//ll s = 1;
//bool ok = 1;
//for (int i = 1; i <= n; ++i) {
//    s = s / __gcd(s, i + 1ll) * (i + 1);
//    if (s > 1000000000)break;
//    if (!(a[i] % s)) { ok = 0; break; }
//}
//write(ok ? "YES\n" : "NO\n");
//return 0;





// 194088821 	Feb/18/2023 16:32UTC+8 	Ouha 	1603A - Di-visible Confusion 	GNU C++17 	Accepted 	514 ms 	800 KB
// 14273

// 12 -> 2,3,4
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int t2, t3;
    for (int i = 0; i < sz1; ++i)
    {
        t2 = i + 2;
        t3 = vi[i];
        for (int j = 2; j <= t2; ++j)
        {
            if (t3 % j)
            {
                goto AAA;
            }
        }

        cout << "NO" << endl;
        return;

        AAA:
        continue;
    }
    cout << "Yes" << endl;
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
