
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

//while (i <= j) {
//    if (d <= 0)
//        d += a[i++];
//    else
//        d -= a[j--];
//    if (d == 0)
//        last = n - (j - i + 1);
//}


//while (dq.size()) {
//    if (sum1 <= sum2) {
//        sum1 += dq.front();
//        dq.pop_front();
//    }
//    else {
//        sum2 += dq.back();
//        dq.pop_back();
//    }
//    if (sum1 == sum2)mx = max(mx, n - sz(dq));
//}




// 186161570 	Dec/21/2022 09:22UTC+8 	Ouha 	1669F - Eating Candies 	GNU C++17 	Accepted 	265 ms 	900 KB

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int ans = 0;
    
    int st = 0;         // will eat
    int en = sz1 - 1;
    
    int sumst = 0;
    int sumen = 0;

    while (st <= en)
    {
        if (sumst == sumen && st != en)
        {
            sumst += vi[st];
            sumen += vi[en];
            ++st;
            --en;
        }
        else if (sumst < sumen)
        {
            sumst += vi[st++];
        }
        else
        {
            sumen += vi[en--];
        }
        if (sumst == sumen)
        {
            ans = st + sz1 - en - 1;
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
