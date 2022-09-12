
//#include <time.h>
//#include <windows.h>
//#include <sstream>
#include <climits>
//#include <fstream>

//#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <cmath>

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

//		for(int i=1;i<=N;i++) a[i]=read();
//		int ma=0,mi=INF,ans=0;
//		for(int i=1;i<=N;i++) {
//			ma=std::max(ma,a[i]);
//			mi=std::min(mi,a[i]);
//			if(ma-mi>2*X) {
//				ma=mi=a[i];
//				ans++;
//			}
//		}
//
// ... 多个 a[x] 的区间，只要 gap 小于 2*x, 肯定有 v 可用。





// 171690414 	Sep/11/2022 16:58UTC+8 	Ouha 	1704B - Luke is a Foodie 	GNU C++17 	Accepted 	358 ms 	800 KB

// -x < v - a < x
// v >= a - x
// v <= a + x
void fun1()
{
    int n,x;
    cin>>n>>x;
    myvi vi(n);
    for (int i = 0; i < n; ++i)
    {
        cin>>vi[i];
    }

    int ans = 0;
    int mnv = INT_MIN, mxv = INT_MAX;
    int t2 = 0;
    int t3 = 0;
    for (int i = 0; i < n; ++i)
    {
        t2 = vi[i] - x;
        t3 = vi[i] + x;
        mnv = max(mnv, t2);
        mxv = min(mxv, t3);
        if (mnv > mxv)
        {
            ++ans;
            mnv = t2;
            mxv = t3;
        }
    }
    cout<<ans<<endl;
}


int main()
{
    int w = 0;
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
