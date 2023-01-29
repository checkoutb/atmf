
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
// Eng. is hard.



// 在path 的最后一个点上，(假设)做 D， 使path 撞到 底边。
// 计算 向右 的最大偏移 ， 乘以 第一次 R 时所在行 和 最后一行 的距离。
// 计算 第一次 D 时 所在列 和 最后一个点 所在列 的距离 +1 (+1是加 第一步的 D) ， 乘以 向下的 最大偏移。

// 第100道


// 190061815 	Jan/22/2023 13:34UTC+8 	Ouha 	1644E - Expand the Path 	GNU C++17 	Accepted 	77 ms 	500 KB
void fun1()
{
    int sz1;
    cin >> sz1;
    string s;
    cin >> s;

    long long ans = s.size() + 1;
    int cntd, cntr, fstd, fstr;
#ifdef __test
//    cout << cntd << cntr << fstd << fstr << endl;     // ERROR: use un-initialized local variable
#endif
    cntd = cntr = 0;
    fstd = fstr = -1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'R')
        {
            ++cntr;
            if (fstr == -1)
                fstr = i;
        }
        else
        {
            ++cntd;
            if (fstd == -1)
                fstd = i;
        }
    }
    if (fstr != -1)
    {
        ans += 1LL * (fstd == -1 ? 1 : (sz1 - fstr)) * (sz1 - 1 - cntr);
    }
    if (fstd != -1)
    {
        ans += 1LL * (fstr == -1 ? 1 : (cntr - fstd + 1)) * (sz1 - 1 - cntd);
    }

    cout << ans << endl;
}


// error
void fun1__()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    string s;
    cin >> s;

    int cntd = 0;
    int cntr = 0;
    int fstd = -1;
    int fstr = -1;
    long long ans = s.size() + 1;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'R')
        {
            ++cntr;
            if (fstr == -1)
                fstr = i;
        }
        else
        {
            ++cntd;
            if (fstd == -1)
                fstd = i;
        }
    }
    
    long long lend = 1LL;
    long long lenr = 1LL;
    if (fstr != -1)
    {
        lenr = sz1 - cntr - 1;
    }
    if (fstd != -1)
    {
        lend = sz1 - cntd - 1;
    }
    
    ans += lenr * lend + lenr * cntd + lend * cntr;
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
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
