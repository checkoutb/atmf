
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






// 173327110 	Sep/24/2022 21:27UTC+8 	Ouha 	1690D - Black and White Stripe 	GNU C++17 	Accepted 	77 ms 	500 KB 

void fun1()
{
    int sz1, kk;
    cin >> sz1 >> kk;
    
    string s;
    cin >> s;

    int cnt = 0;
    int ans = kk;
    for (int i = 0; i < sz1; ++i)
    {
        cnt += s[i] == 'W';

        if (i >= kk - 1)
        {
            ans = min(ans, cnt);
        }
        if (i >= kk - 1)
        {
            cnt -= s[i - kk + 1] == 'W';
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
