
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

//if (Max == Min && Max == 0) {
//    cout << "No\n"; continue;
//}
//cout << "Yes\n";
//int sum = 0;
//for (int i = 1; i <= n; i++) {
//    if (sum >= 0) {
//        sum += vec1.back();
//        cout << vec1.back() << " "; vec1.pop_back();
//    }
//    else {
//        sum += vec2.back();
//        cout << vec2.back() << " "; vec2.pop_back();
//    }
//}





//210028559 	Jun / 18 / 2023 15:27UTC + 8 	Ouha 	1798D - Shocking Arrangement 	GNU C++17 	Accepted 	888 ms 	2300 KB
// 6989



void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1, 0);

    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int lt0 = 0;
    int gt0 = 0;
    int mx = vi[0];
    int mn = vi[0];

    //for (int n : vi)
    //{
    //    if (n > 0)
    //        ++gt0;
    //    else if (n < 0)
    //        ++lt0;
    //
    //    mx = std::max(mx, n);
    //    mn = std::min(mn, n);
    //}

    std::sort(std::begin(vi), end(vi));

    mx = vi[sz1 - 1];
    mn = vi[0];
    
    lt0 = std::distance(begin(vi), std::lower_bound(begin(vi), end(vi), 0));
    gt0 = std::distance(std::upper_bound(begin(vi), end(vi), 0), end(vi));
    
    //bool chosePositive = gt0 > lt0;

    long long pmx = 0LL;
    long long pmn = 0LL;
    int li = 0;
    int ri = sz1 - 1;

    mx = mx - mn;

    vector<int> v2(sz1, 0);
    for (int i = 0; i < sz1; ++i)
    {
        if (lt0 < gt0)  // + first
        {
            long long t2 = max(abs(pmx + vi[ri]), abs(pmn + vi[ri]));
            if (t2 < mx && t2 > -mx)
            {
                v2[i] = vi[ri];
                --ri;
                --gt0;

                pmx += v2[i];
                if (pmx < 0)
                    pmx = 0;

                pmn += v2[i];
                if (pmn > 0)
                    pmn = 0;
            }
            else
            {
                v2[i] = vi[li];
                ++li;
                --lt0;
                pmx += v2[i];
                if (pmx >= mx)
                {
                    cout << "No" << endl;
                    return;
                }
                if (pmx < 0)
                    pmx = 0;
                pmn += v2[i];
                if (pmn <= -mx)
                {
                    cout << "No" << endl;
                    return;
                }
                if (pmn > 0)
                    pmn = 0;
            }
        }
        else
        {
                    // - first
            long long t2 = max(abs(pmx + vi[li]), abs(pmn + vi[li]));
            if (t2 < mx && t2 > -mx)
            {
                v2[i] = vi[li];
                ++li;
                --lt0;

                pmx += v2[i];
                if (pmx < 0)
                    pmx = 0;
                pmn += v2[i];
                if (pmn > 0)
                    pmn = 0;
            }
            else
            {
                v2[i] = vi[ri--];
                --gt0;
                pmx += v2[i];
                if (pmx >= mx)
                {
                    cout << "No" << endl;
                    return;
                }
                if (pmx < 0)
                    pmx = 0;

                pmn += v2[i];
                if (pmn <= -mx)
                {
                    cout << "No" << endl;
                    return;
                }
                if (pmn > 0)
                    pmn = 0;
            }
        }
    }

    cout << "Yes" << endl;
    for (int i : v2)
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
