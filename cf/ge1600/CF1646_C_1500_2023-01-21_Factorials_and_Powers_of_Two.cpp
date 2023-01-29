
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





// 189959816 	Jan/21/2023 19:36UTC+8 	Ouha 	1646C - Factorials and Powers of Two 	GNU C++17 	Accepted 	546 ms 	0 KB

// g


int makeBy2(long long val, vector<long long>& vi);
int dfsb1(long long val, vector<long long>& vi, vector<long long>& v2, int idx);

void fun1()
{
    long long ll;
    cin >> ll;
    vector<long long> vi(42, 1);
    vector<long long> v2(17, 1);
    for (int i = 1; i < vi.size(); ++i)
        vi[i] = 2LL * vi[i - 1];
    for (int i = 2; i < v2.size(); ++i)
        v2[i] = v2[i - 1] * i;

    int ans = dfsb1(ll, vi, v2, 16);
    cout << ans << endl;
    //int cnt = 0;
    //for (int i = v2.size() - 1; i >= 0; --i)
    //{
    //    if (ll >= v2[i])
    //    {
    //        ll -= v2[i];
    //        ++cnt;
    //    }
    //}
    
}

int dfsb1(long long val, vector<long long>& vi, vector<long long>& v2, int idx)
{
    if (val == 0LL)
        return 0;
    if (idx < 0)
        return makeBy2(val, vi);

    while (idx >= 0 && v2[idx] > val)
    {
        --idx;
    }
    int t2 = idx >= 0 ? (1 + dfsb1(val - v2[idx], vi, v2, idx - 1)) : INT_MAX;
    int t3 = dfsb1(val, vi, v2, idx - 1);
    int t4 = makeBy2(val, vi);

    return min(t2, min(t3, t4));
}

int makeBy2(long long val, vector<long long>& vi)
{
    int cnt = 0;
    for (int i = vi.size() - 1; i >= 0; --i)
    {
        if (val >= vi[i])
        {
            ++cnt;
            val -= vi[i];
        }
    }
    return cnt;
}


// tle.
int dfsa1(long long val, vector<long long>& vi, vector<long long>& v2, int idx1, int idx2);
// distinct 
void fun1__()
{
    //int sz1, sz2, kk;
    //cin >> sz1;
    
    long long ll;
    cin >> ll;

    vector<long long> vi(42, 1);        // 2^index
    vector<long long> v2(17, 1);        // index!

    for (int i = 1; i < vi.size(); ++i)
    {
        vi[i] = 2LL * vi[i - 1];
    }
    for (int i = 2; i < v2.size(); ++i)
    {
        v2[i] = v2[i - 1] * i;
    }

    int ans = dfsa1(ll, vi, v2, 41, 16);
    cout << ans << endl;
}

int dfsa1(long long val, vector<long long>& vi, vector<long long>& v2, int idx1, int idx2)
{
    if (val == 0)
        return 0;

    while (idx1 >= 0 && vi[idx1] > val)
    {
        --idx1;
    }
    while (idx2 >= 0 && v2[idx2] > val)
    {
        --idx2;
    }
    int t2 = idx1 >= 0 ? dfsa1(val - vi[idx1], vi, v2, idx1 - 1, idx2) : INT_MAX;
    int t3 = idx2 >= 0 ? dfsa1(val - v2[idx2], vi, v2, idx1, idx2 - 1) : INT_MAX;
    return min(t2, t3) + 1;
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
