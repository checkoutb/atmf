
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






// g...


long long cnta1(vector<int>& vi, int tar);

// 感觉 要么是 max，要么是 max+1.
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i)
        cin >> vi[i];
    
    int mx = *max_element(begin(vi), end(vi));
    
    long long ans = std::min(cnta1(vi, mx), cnta1(vi, mx + 1));
    
    cout << ans << endl;
}

long long cnta1(vector<int>& vi, int tar)
{
    int arr[3] = { 0 };
    long long ans = 0LL;
    for (int i : vi)
    {
        ans += (tar - i) / 3 * 2;
        arr[(tar - i) % 3]++;
    }

    ans += arr[2] >= arr[1] ? arr[2] * 2 : (arr[1] * 2 - 1);

    return ans;
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
