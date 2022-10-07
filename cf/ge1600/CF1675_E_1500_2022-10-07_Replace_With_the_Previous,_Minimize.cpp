
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

//for (int i = 1; i <= n; i++) {
//    while (s[i] != to[s[i]])
//        s[i] = to[s[i]];
//    while (s[i] > 'a' && k > 0) {
//        to[s[i]] = s[i] - 1;
//        s[i] = to[s[i]];
//        while (s[i] != to[s[i]])
//            s[i] = to[s[i]];
//        k--;
//    }
//}





// 174921153 	Oct/07/2022 10:38UTC+8 	Ouha 	1675E - Replace With the Previous, Minimize 	GNU C++17 	Accepted 	93 ms 	500 KB
// 7582

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1 >> kk;
    string s;
    cin >> s;
    
    char arr[123] = { 0 };
    for (int i = 'a'; i <= 'z'; ++i)
        arr[i] = (char) i;
    
    char mn = 'a';      // max char be converted to 'a'
    
    for (int i = 0; i < sz1 && mn != 'z'; ++i)
    {
        if (s[i] > mn)
        {
            if (kk >= (s[i] - mn))
            {
                for (int j = mn + 1; j <= s[i]; ++j)
                {
                    arr[j] = 'a';
                }
                kk -= s[i] - mn;
            }
            else
            {
                char t2 = s[i] - kk;
                for (int j = t2 + 1; j <= s[i]; ++j)
                {
                    arr[j] = t2;
                }
                break;
            }
            mn = s[i];
        }
    }
    
    for (int i = 0; i < sz1; ++i)
        s[i] = arr[s[i]];

    cout << s << endl;
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
