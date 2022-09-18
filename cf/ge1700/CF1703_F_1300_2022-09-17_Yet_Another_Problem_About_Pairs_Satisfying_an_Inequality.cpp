
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

//		N=read();
//		for(int i=1;i<=N;i++) a[i]=read(),v[i]=0;
//		long long ans=0;
//		for(int i=1;i<=N;i++) {
//			if(a[i]<i) ans+=v[a[i]-1],v[i]=v[i-1]+1;else v[i]=v[i-1];
//		}


//	FenwickTree<int> g(n + 5);
//	ll res = 0;
//	for (auto i : p)
//	{
//		res += g.Get(a[i] - 1);
//		g.Add(i, 1);
//	}


//    while(T--){
//        cin>>n;ans=0;
//        for(i=1;i<=n;i++)  cin>>x,  s[i]=s[i-1]+(x<i),  (x<i) ? ans+=s[x-1] : 7;
//        cout<<ans<<'\n';
//    }




// 172434919 	Sep/17/2022 16:53UTC+8 	Ouha 	1703F - Yet Another Problem About Pairs Satisfying an Inequality 	GNU C++17 	Accepted 	343 ms 	2400 KB

// a[i] < i < a[j] < j
// i a[j]
static int arr[200005] = {0};

void fun1()
{
    int sz1;
    cin>>sz1;

    for (int i = 0; i < sz1; ++i)
    {
        cin>>arr[i];
    }
    vector<int> vi;
    for (int i = 0; i < sz1; ++i)
    {
        if (arr[i] < i + 1)         // aj
        {
            vi.push_back(arr[i]);
        }
    }

    sort(begin(vi), end(vi));

    #ifdef __test
    cout<<" ---- ";
    for_each(begin(vi), end(vi), [](int& a){ cout<<a<<" , ";});
    cout<<endl;
    #endif // __test

    ll ans = 0LL;
    int idx = 0;
    for (int i = 0; i < sz1; ++i)
    {
        if (arr[i] >= i + 1)
            continue;

        int t2 = i + 1;
        while (idx < vi.size() && vi[idx] <= t2)        // idx : first index that > t2
        {
            ++idx;
        }
        ans += (vi.size() - idx);
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
