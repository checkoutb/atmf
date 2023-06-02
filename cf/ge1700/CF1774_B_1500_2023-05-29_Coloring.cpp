
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

		// int N, M, K; cin >> N >> M >> K;
		// bool is_bad = false;
		// int num_big = 0;
		// for (int i = 0; i < M; i++) {
		// 	int v; cin >> v;
		// 	if (v == (N / K) + 1) {
		// 		num_big++;
		// 	} else if (v > (N / K) + 1) {
		// 		is_bad = true;
		// 	}
		// }
		// cout << (!is_bad && num_big <= N % K ? "YES" : "NO") << '\n';


        // for (int& ai : a) cin >> ai;
        // int mx = *max_element(a.begin(), a.end());
        // if (mx > n / k + 1)
        //     cout << "NO\n";
        // else if(mx == n / k + 1 and count(a.begin(), a.end(), mx) > n % k)
        //     cout << "NO\n";
        // else cout << "YES\n";



// 207720101 	May/29/2023 14:31UTC+8 	Ouha 	1774B - Coloring 	GNU C++17 	Accepted 	249 ms 	0 KB
// 9416

void fun1()
{
    // int sz1, sz2, kk;
    // cin >> sz1;
    
    int n, m, k;
    cin>>n>>m>>k;   // cell, color, consecutive

    // int mx = 0;
    // vector<int> vi(m);
    // for (int i = 0; i < m; ++i)
    // {
    //     cin>>vi[i];
    //     mx = std::max(mx, vi[i]);
    // }

    int mx = 0;
    int cnt = 0;
    int t2 = 0;
    for (int i = 0; i < m; ++i)
    {
        cin>>t2;
        if (t2 > mx) {
            mx = t2;
            cnt = 1;
        } else if (t2 == mx) {
            ++cnt;
        }
    }

    if (mx > (n + k - 1) / k) {
        cout<<"No"<<endl;
    } else if (mx < (n + k - 1) / k) {
        cout<<"Yes"<<endl;
    } else {
        if (cnt > n % k && n % k != 0) {       // n % k == 0 <=> n % k == k
            cout<<"No"<<endl;
        } else {
            cout<<"Yes"<<endl;
        }
    }
    
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
