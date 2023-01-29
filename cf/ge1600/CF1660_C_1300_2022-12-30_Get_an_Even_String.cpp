
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

// 贪婪，只需要一个int + arr[123]， 不需要 vi(sz1)
// 因为在 arr[123] 的时候 也贪婪， 只要匹配了，那么 就肯定取 这对， 这个时候 +2， 然后清空arr[123]。




//187234298 	Dec / 30 / 2022 19:19UTC + 8 	Ouha 	1660C - Get an Even String 	GNU C++17 	Accepted 	77 ms 	1300 KB

void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    string s;
    cin >> s;
    sz1 = s.size();
    vector<int> vi(s.size() + 2);
    int arr[123] = { -1 };
#ifdef __test
    cout << arr[22] << endl;  // 0
#endif
    std::fill_n(arr, 123, -1);
#ifdef __test
    cout << arr[22] << endl;
#endif

    int mxlen = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (arr[s[i]] != -1)
        {
            mxlen = max(mxlen, arr[s[i]] == 0 ? 2 : (vi[arr[s[i]] - 1] + 2));
        }
        arr[s[i]] = i;
        vi[i] = mxlen;
    }
    cout << sz1 - mxlen << endl;
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
