
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

//for (int i = 0, j = 0; i < n; i++) {
//    while (j < n && cur + a[j] <= s) {
//        cur += a[j];
//        j++;
//    }
//    if (cur == s) {
//        ans = std::min(ans, n - (j - i));
//    }
//    cur -= a[i];
//}






// 173275396 	Sep/24/2022 13:53UTC+8 	Ouha 	1692E - Binary Deque 	GNU C++17 	Accepted 	140 ms 	800 KB

void fun1()
{
    int sz1, remain;
    cin >> sz1 >> remain;
    
    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];

    int sti = 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cnt += vi[i];
        while (cnt > remain)
        {
            cnt -= vi[sti++];
        }
        if ((i - sti + 1) > ans)
            ans = i - sti + 1;
    }
    if (cnt < remain)
    {
        cout << -1 << endl;
    }
    else
        cout << sz1 - ans << endl;
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
