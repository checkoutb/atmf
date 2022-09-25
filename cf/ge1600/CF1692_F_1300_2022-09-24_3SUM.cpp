
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

//F(i, 0, 10)
//{
//    if (count[i] > 2)                 // count > 3 无意义。 所以压缩成 最多 30个。
//    {
//        temp.pb(i);
//        temp.pb(i);
//        temp.pb(i);
//    }
//    else if (count[i] == 2)
//    {
//        temp.pb(i);
//        temp.pb(i);
//    }
//    else if (count[i] == 1)
//        temp.pb(i);
//
//}
//ll ans = 0;
//for (ll i = 0; i < temp.size() and ans == 0; i++)
//{
//    for (ll j = i + 1; j < temp.size() and ans == 0; j++)
//    {
//        F(k, j + 1, temp.size())
//        {
//            if (temp[i] + temp[j] + temp[k] == 3 or temp[i] + temp[j] + temp[k] == 13 or temp[i] + temp[j] + temp[k] == 23)
//            {
//                ans = 1;
//                break;
//            }
//        }
//    }
//}







// 173274141 	Sep/24/2022 13:41UTC+8 	Ouha 	1692F - 3SUM 	GNU C++17 	Accepted 	343 ms 	0 KB

// 1 + 1 + 1
// 1 + 2 + 0
// 0 0 3
// 7 7 9
void fun1()
{
    int sz1;
    cin >> sz1;
    
    int arr[10] = { 0 };
    int t2 = 0;
    while (sz1-- > 0)
    {
        cin >> t2;
        ++arr[t2 % 10];
    }
    
    for (int i = 0; i < 10; ++i)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        --arr[i];
        for (int j = i; j < 10; ++j)
        {
            if (arr[j] == 0)
            {
                continue;
            }
            --arr[j];
            for (int k = j; k < 10; ++k)
            {
                if (arr[k] == 0)
                {
                    continue;
                }
                if ((i + j + k) % 10 == 3)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
            ++arr[j];
        }
        ++arr[i];
    }
    
    cout << "NO" << endl;
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
