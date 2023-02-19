
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
#include <cmath>
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







// vi.push_back(mn = min(mn, arr[i]));
// 之前为了mn。。。

// 194182415 	Feb / 19 / 2023 11:44UTC + 8 	Ouha 	1601A - Array Elimination 	GNU C++17 	Accepted 	452 ms 	200 KB
// 11041

// error, y?

// 1 biran kyi
// 2 
// element all same, k is [1,sz1]. bu
// meige bit de zui xiao
// bu , 
// all meige bit geshu de gcd, no,  factor
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    int arr[31] = { 0 };
    int t2;
    int cnt0 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        cin >> t2;
        for (int j = 0; j < 31 && (1 << j) <= t2; ++j)
        {
            if ((t2 & (1 << j)) != 0)
            {
                ++arr[j];
            }
        }
    }
    
    int mn = 300000;
    vector<int> vi;
    for (int i = 0; i < 31; ++i)
        if (arr[i])
            vi.push_back(arr[i]);

    if (vi.empty())     // all 0
    {
        for (int i = 1; i <= sz1; ++i)
        {
            cout << i << ' ';
        }
        cout << endl;
        return;
    }


    sort(begin(vi), end(vi));
    vector<int> ans;

    for (int i = 1, mxi = vi[0]; i <= sz1; ++i)
    {
        for (int j = 0; j < vi.size(); ++j)
        {
            if (vi[j] % i)
            {
                goto AAA;
            }
        }

        //cout << i << ' ';
        ans.push_back(i);
        //if (vi[0] / i != i)
        //    ans.push_back(vi[0] / i);

        AAA:
        continue;
    }

    //if (vi[0] != 1)
    //{
    //    for (int j = 0; j < vi.size(); ++j)
    //    {
    //        if (vi[j] % vi[0])
    //            goto BBB;
    //    }
    //    //cout << vi[0] << ' ';
    //    ans.push_back(vi[0]);
    //    
    //    BBB:
    //    ;
    //}

    for (int i : ans)
        cout << i << ' ';

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
