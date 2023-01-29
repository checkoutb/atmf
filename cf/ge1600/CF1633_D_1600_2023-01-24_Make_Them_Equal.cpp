
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
#include <map>
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





// tai nan le.

// g


// error
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> kk;

    vector<int> vtar(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vtar[i];
    
    vector<int> vcoin(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vcoin[i];
    
    vector<int> vi(1001, -1);
    vi[1] = 0;
    vi[2] = 1;


    int t2 = 0;
    for (int i = 2; i < 1001; ++i)
    {
        //t2 = 0;
        //for (; (1 << t2) < vtar[i]; ++t2)
        //    ;

        vtar[i] = t2;
    }
    map<int, long long> map2;
    long long sum0 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        int cnt = vtar[i];
        int coin = vcoin[i];
        if (cnt == 0)
        {
            sum0 += coin;
            continue;
        }
        map<int, long long> map3(begin(map2), end(map2));
        for (map<int, long long>::reverse_iterator it = map3.rbegin(); it != map3.rend(); it++)
        {
            if (it->first + cnt > kk)
                continue;
            map2[it->first + cnt] = max(map2[it->first + cnt], map2[it->first] + coin);
        }
        if (cnt <= kk)
            map2[cnt] = max(map2[cnt], (long long)coin);

        //map<int, long long> map3;
        //for (map<int, long long>::iterator it = map2.begin(); it != map2.end(); it++)
        //{
        //    if (it->first + cnt > kk)
        //        continue;
        //    map3[it->first + cnt] = max(map3[it->first + cnt], i t - > s e c o n d + coin);
        //}
        //if (cnt <= kk)
        //    map3[cnt] = max(map3[cnt], (long long)coin);
        ////swap(map2, map3);
        //for (auto& p : map3)
        //{
        //    //map2.insert(p);
        //    map2[p.first] = max(p.second, map2[p.first]);
        //}
    }
    long long ans = 0LL;
    for (auto& [k, v] : map2)
    {
        ans = max(ans, v);
    }
    cout << ans + sum0 << endl;
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
