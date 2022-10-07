
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

//int p = 0, q = l - 1;
//for (int i = 0; i < l; i++) {
//    if (s[i] == '1') { p = max(p, i); }
//    else if (s[i] == '0') { q = min(q, i); }
//}
//cout << q - p + 1 << '\n';

// 排除法， 如果 1 是真的，那么 不可能在 1 之前偷走， 如果是假的， 那么 只会怀疑 他一个人。他也是怀疑对象。



// 174926720 	Oct/07/2022 12:39UTC+8 	Ouha 	1675C - Detective Task 	GNU C++17 	Accepted 	31 ms 	500 KB
// 14543

void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    
    string s;
    cin >> s;
    sz1 = s.size();
    
    int lst1 = -1;
    int plst = -1;

    int fst0 = sz1;
    int nfst = sz1;
    
    for (int i = 0; i < sz1; ++i)
    {
        if (s[i] == '1')
        {
            plst = lst1;
            lst1 = i;
        }
        else if (s[i] == '0')
        {
            if (fst0 == sz1)
            {
                fst0 = i;
            }
            else if (nfst == sz1)
            {
                nfst = i;
            }
        }
    }
    
#ifdef __test
    cout << lst1 << " , " << fst0 << endl;
#endif

    if (lst1 == sz1 - 1 || fst0 == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        if (lst1 == -1)
        {
            lst1 = 0;
        }
        if (fst0 == sz1)
        {
            fst0 = sz1 - 1;
        }
        cout << (fst0 - lst1 + 1) << endl;
    }

    //if (lst1 > fst0)
    //{
    //    if (plst != -1 || nfst != sz1)
    //        cout << 1 << endl;
    //    else
    //        cout << 2 << endl;
    //}
    //else if (lst1 != -1 && fst0 != sz1)
    //{
    //    //return max(nfst - lst1 - 1, fst0 - plst - 1);
    //    return max();
    //}
    //else
    //{

    //}
    
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
