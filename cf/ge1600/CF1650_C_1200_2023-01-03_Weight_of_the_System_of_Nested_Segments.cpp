
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







// ...Verdict: ÅÐ¾ö¡£¡£¡£
// 187727994 	Jan/03/2023 22:34UTC+8 	Ouha 	1650C - Weight of the System of Nested Segments 	GNU C++17 	Happy New Year! 	920 ms 	7200 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> kk;
    cin >> sz1;
    
    vector<vector<int>> vvi(sz1, vector<int>(3, 0));
    for (int i = 0; i < sz1; ++i)
    {
        cin >> vvi[i][0] >> vvi[i][1];
        vvi[i][2] = (i + 1);
    }
    
    sort(begin(vvi), end(vvi), [](const vector<int>& vi, const vector<int>& v2) {
        return vi[1] < v2[1];
        });
    
    while (vvi.size() > kk * 2)
        vvi.pop_back();

    sort(begin(vvi), end(vvi));
    
    int sum2 = 0;
    for (int i = 0; i < vvi.size(); ++i)
    {
        sum2 += vvi[i][1];
    }
    cout << sum2 << endl;
    for (int i = 0; i < kk; ++i)
    {
        cout << vvi[i][2] << ' ' << vvi[vvi.size() - 1 - i][2] << endl;
    }
    cout << endl;
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
