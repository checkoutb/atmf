
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
#include <string.h>       // memset

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

// [x][y] 分解x，只用 小于等于 y 的 回文。





// tle...

pair<int, int> revCnt(int a);

void fun1()
{
    int sz1, sz2, kk;
    //cin >> sz1;
    
    //myvi v2(sz1 + 1);
    
    const int MOD = 1e9 + 7;
    
    myvi vi;

    bool b2 = true;

    for (int i = 1; i < 10; ++i)
    {
        vi.push_back(i);
    }

    sz1 = 40000;

    for (int i = 1; i < 1000; ++i)
    {
        pair<int, int> p = revCnt(i);
        int cnt = p.first;
        int rev = p.second;

        int t2 = i * cnt + rev;
        if (t2 <= sz1)
            vi.push_back(t2);
        else
            break;

        for (int j = 0; j < 10 and b2; ++j)
        {
            t2 = i * cnt * 10 + j * cnt + rev;
            if (t2 <= sz1)
                vi.push_back(t2);
            else
                b2 = false;
        }
    }

    sort(begin(vi), end(vi));

#ifdef __test
    cout << "---------------- " << vi.size() << endl;   // 582
#endif


    int w;
    cin >> w;
    
    int arr[40001] = { 0 };

    while (w-- > 0)
    {
        memset(arr, 0, sizeof(arr));
        cin >> sz1;

        for (int i = 0; i < vi.size() && vi[i] <= sz1; ++i)
        {
            int t2 = vi[i];

            ++arr[t2];

            for (int j = 1; j + t2 <= sz1; ++j)
            {
                arr[j + t2] += arr[j];
            }

            //for (int j = sz1; j > t2; --j)
            //{
            //    arr[j] = (arr[j] + arr[j - t2]) % MOD;
            //}
            //++arr[t2];

            //++v2[t2];       // 0 + 
            //for (int j = 1; j + t2 <= sz1; ++j)
            //{
            //    
            //}
        }
    
        cout << arr[sz1] << endl;
    }
}


pair<int, int> revCnt(int a)
{
    int cnt = 1;
    int ans = 0;
    while (a > 0)
    {
        cnt *= 10;
        ans = ans * 10 + a % 10;
        a /= 10;
    }
    return std::make_pair(ans, cnt);
}



int main()
{
    int w = 1;
    //cin>>w;
    
    
    
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
