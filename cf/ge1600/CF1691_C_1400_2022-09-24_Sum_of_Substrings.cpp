
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
//#include <numeric>
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

//int ans = 11 * cnt;
//if (k >= first + n - 1 - last && first != last) {
//    ans -= 11;
//}
//else if (k >= n - 1 - last) {
//    ans -= 10;
//}
//else if (k >= first) {
//    ans -= 1;
//}






// 173299243 	Sep/24/2022 17:10UTC+8 	Ouha 	1691C - Sum of Substrings 	GNU C++17 	Accepted 	62 ms 	300 KB


// 111
// 01110  every 1 is 01 and 10...  11 = 10+01
// 1xxx1
void fun1()
{
    int sz1, kk;
    cin >> sz1 >> kk;
    
    string s;
    cin >> s;

    int t2, t3, cnt;
    t2 = -1;
    t3 = -1;
    cnt = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (s[i] == '1')
        {
            if (t2 == -1)
                t2 = i;
            t3 = i;
            ++cnt;
        }
    }

    t3 = sz1 - t3 - 1;

    int ans = cnt * 11;
    if (ans == 0)
    {
        cout << ans << endl;
        return;
    }

    if (t3 <= kk)
    {
        kk -= t3;
        if ((t2 == 0 || t2 <= kk) && (cnt > 1))
        {
            ans -= 1;
        }
        ans -= 10;
    }
    else
    {
        if (t2 == 0 || t2 <= kk)
        {
            ans -= 1;
        }
    }

    cout << ans << endl;
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
        
        //cout<<endl;
    }
    
    
    return 0;
}
