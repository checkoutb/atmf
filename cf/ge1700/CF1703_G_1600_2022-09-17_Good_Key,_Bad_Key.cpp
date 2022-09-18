
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

//    int n, k;
//    cin >> n >> k;
//    vector<int> a(n);
//    for (int& x: a) cin >> x;
//    vector<long long> as(n+1);
//    for (int i = 0; i < n; i++) {
//      as[i+1] = as[i] + a[i];
//    }
//    long long ans = 0;
//    for (int i = 0; i <= n; i++) {
//      // use good keys on the first i chests
//      long long z = as[i]-1LL*k*i;
//      for (int j = i; j < min(n, i+31); j++) {
//        z += a[j]>>(j-i+1);
//      }
//      ans = max(ans, z);
//    }
//.. 看代码的意思是， 一但下降必然是 下降到 0/最后 的。。

// tutorial:
// 如果手里 有2个key， 一个好，一个坏， 必然是 先用好的，再用坏的。
// 先用好的： 可以获得  a1 + a2/2 - k
// 如果先用坏的：  a1/2 + a2/2 - k
// 所以一但用了 bad key ，后面就不会再 使用 good key 了。
// 所以 一但 使用了 bad key ，后面 就 只能 /2 直到 0/最后
// 。。。amazing。


// 我的代码是：
// 10亿 < 2^31
// vi[] 的下标 是 /2 的次数。
// 在 当前index 下， 如果我选择 /2 ， 那么 就 会获得 xxx， 如果 不除以 2， 那么就 xxx
// 由于 vi 中 是 当前index + 1 的 各种 /2 次数 的 最优值。 所以 本次也可以是 /2 次数 的 最优值。



// 172428777 	Sep/17/2022 15:38UTC+8 	Ouha 	1703G - Good Key, Bad Key 	GNU C++17 	Accepted 	202 ms 	400 KB

static int arr[100005] = {0};

void fun1()
{
    int sz1, cst;
    cin>>sz1>>cst;

    for (int i = 0; i < sz1; ++i)
    {
        cin>>arr[i];
    }

    ll ans = 0LL;

    vector<ll> vi(32);

    for (int i = sz1 - 1; i >= 0; --i)
    {
        ll t2 = arr[i];

        vector<ll> v2(32);

        for (int j = 0; j < 31; ++j)   // 30?
        {
            v2[j] = max(vi[j] + t2 - cst, vi[j + 1] + t2 / 2);
            t2 /= 2;
        }

        swap(vi, v2);
    }

    cout<<*max_element(begin(vi), end(vi))<<endl;
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
