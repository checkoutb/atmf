
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

//for (int i = 0; i < n; ++i) {
//    cin >> a[i];
//    ans += a[i] / k;
//    a[i] %= k;
//}
//sort(all(a));
//int i = 0, j = n - 1;
//while (i < j) {
//    if (a[i] + a[j] >= k) {
//        ans++;
//        i++;
//        j--;
//    }
//    else {
//        i++;
//        i++;
//    }
//}
// i++ i++ ?




// 173322618 	Sep/24/2022 20:46UTC+8 	Ouha 	1690E - Price Maximization 	GNU C++17 	Accepted 	436 ms 	800 KB

void fun1()
{
    int sz1, kk;
    cin >> sz1 >> kk;

    myvi vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    //int arr[1000] = { 0 };
    myvi v2(kk + 1, 0);
    
    ll ans = 0LL;

    for (int i = 0; i < sz1; ++i)
    {
        ans += vi[i] / kk;
        
        ++v2[vi[i] % kk];
    }

    int sti = 1;
    for (int i = kk - 1; i >= sti; --i)
    {
        if (v2[i] == 0)
        {
            continue;
        }

        while (sti <= i && (v2[sti] == 0 || (i + sti) < kk))
        {
            sti++;
        }

        if (sti > i)
            break;
        
        if (sti == i)
        {
            ans += v2[i] / 2;
            continue;
        }

        ans += min(v2[sti], v2[i]);

        if (v2[sti] >= v2[i])
        {
            v2[sti] -= v2[i];
            v2[i] = 0;
        }
        else
        {
            v2[i] -= v2[sti];
            v2[sti] = 0;
            ++i;
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
