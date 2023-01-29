
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

    //int ans = 2 * (cntPairs / k);
    //cntOdd += 2 * (cntPairs % k);
    //if (cntOdd >= k) {
    //    ans++;
    //}
// ...

// 190745388 	Jan/27/2023 18:03UTC+8 	Ouha 	1624D - Palindromes Coloring 	GNU C++17 	Accepted 	46 ms 	500 KB 
// 13410

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2; // color

    string s;
    cin >> s;
    
    int arr[26] = { 0 };
    for (char ch : s)
    {
        ++arr[ch - 'a'];
    }
//    std::sort(begin(arr), std::end(arr));
    
    int st = 1;
    int en = sz1 / sz2;
    int ans = -1;
    int t1 = 0;
    int t2 = 0;
    int cnt = 0;

    for (int i : arr)
    {
        t1 += i % 2;
        t2 += (i >> 1) << 1;
    }

    while (st <= en)        // min length
    {
        int md = (st + en) / 2;

        if (md % 2 == 0)
        {
            cnt = t2 / md;
        }
        else
        {
            if (md == 1)
            {
                cnt = t1 + t2;
            }
            else
            {
                cnt = t2 / (md - 1);
                if (cnt > t1)
                {
                    cnt = sz1 / md;
                }
            }
        }

        //for (int i = 0; i < 26; ++i)
        //{
        //    if (arr[i] == 0)
        //        continue;

        //    if (md % 2 == 0)
        //    {
        //        cnt += (arr[i] + t2) / 2;
        //    }
        //    else
        //    {

        //    }
        //}

        if (cnt >= sz2)
        {
            ans = md;
            st = md + 1;
        }
        else
        {
            en = md - 1;
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
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
