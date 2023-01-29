
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








// 187490205 	Jan/01/2023 11:11UTC+8 	Ouha 	1659A - Red Versus Blue 	GNU C++17 	Accepted 	30 ms 	0 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    int r, b;
    cin >> r >> b;
    
    int t2 = r / (b + 1);
    int t3 = r % (b + 1);
    
    string s(r + b, 'R');

#ifdef __test
//    cout << s << endl;
#endif

    int idx = -1;
    for (int i = 0; i < t3; ++i)
    {
        idx += (t2 + 1 + 1);
        s[idx] = 'B';
    }
    
    for (; idx + t2 + 1 < (r + b); )
    {
        idx += t2 + 1;
        s[idx] = 'B';
    }

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
