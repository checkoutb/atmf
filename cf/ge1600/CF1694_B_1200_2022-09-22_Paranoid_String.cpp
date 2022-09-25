
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






// 173062916 	Sep/22/2022 21:07UTC+8 	Ouha 	1694B - Paranoid String 	GNU C++17 	Accepted 	46 ms 	500 KB


// 00001 -> 0001 -> 1
// 11110 -> 0
// 11 
// 1001 -> 01 -> 1
// 0110 -> 10 -> 0
// 0111110 -> 0110 -> 0
// 1000001 -> 1
// 0000111100001 -> 1
// 10101 -> 0101  001  1
void fun1()
{
    int sz1;
    cin >> sz1;
    string s;
    cin >> s;

    ll ans = sz1;

    for (int i = 1; i < sz1; ++i)
    {
        if (s[i] != s[i - 1])
        {
            ans += i;
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
