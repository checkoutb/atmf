
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











//186166629 	Dec / 21 / 2022 11:02UTC + 8 	Ouha 	1669E - 2 - Letter Strings 	GNU C++17 	Accepted 	78 ms 	0 KB
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    string s;
    int arr[12][12] = { {0} };

#ifdef __test
    //for (int i = 0; i < 12; ++i)
    //{
    //    for (int j = 0; j < 12; ++j)
    //        cout << arr[i][j] << ", ";
    //    cout << endl;
    //}
#endif

    int arr1[12] = { 0 };
    int arr2[12] = { 0 };
    long long ans = 0LL;
    int t2, t3;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> s;
        t2 = s[0] - 'a';
        t3 = s[1] - 'a';

        ans += arr1[t2] + arr2[t3] - arr[t2][t3] * 2;

        ++arr1[t2];
        ++arr2[t3];
        ++arr[t2][t3];
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
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
