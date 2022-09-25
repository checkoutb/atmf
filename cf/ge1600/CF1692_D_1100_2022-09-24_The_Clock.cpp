
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

//string s;
//int x;
//cin >> s >> x;
//int t = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');
//int t0 = t;
//int ans = 0;
//while (1) {
//    t += x, t %= 1440;
//    if (t / 600 == t % 10 && t / 60 % 10 == t % 60 / 10)
//        ans++;
//    if (t == t0)
//        break;
//}




// 173278749 	Sep/24/2022 14:23UTC+8 	Ouha 	1692D - The Clock 	GNU C++17 	Accepted 	15 ms 	0 KB


// 00 23
// 00 59
// 2400
void fun1()
{
    string s;
    cin >> s;
    int gap;
    cin >> gap;


    //gap = (gap / 60) * 100 + (gap % 60);

    int tm = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0');

    //function<bool(int)> 
    auto f1 = [](int t2) {
        return ((t2 / 1000) == (t2 % 10)) && ((t2 % 1000 / 100) == (t2 % 100 / 10));
    };

    //function<int(int)> f2;
    auto f2 = [&](int tm) {

        int t2 = tm % 100;
        int t3 = tm / 100;
        t2 += gap;

        t3 += t2 / 60;
        t2 %= 60;

        t3 %= 24;

        return t3 * 100 + t2;

        // 59 + 59

        //tm += gap;
        //if (tm % 100 >= 60)
        //{
        //    tm = (tm / 100 + 1) * 100 + tm % 100 - 60;
        //}
        //if (tm / 100 > 23)
        //{
        //    tm = (tm / 100 % 24) * 100 + tm % 100;
        //}
        //return tm;
    };
    
    vector<bool> vb(2360, false);
    int ans = 0;
    while (!vb[tm])
    {
        vb[tm] = true;
        if (f1(tm))
            ++ans;
        tm = f2(tm);
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
