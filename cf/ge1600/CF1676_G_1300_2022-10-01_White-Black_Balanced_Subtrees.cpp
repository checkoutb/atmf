
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
#include <queue>
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


// D

//void solve() {
//    int n;
//    std::cin >> n;
//    std::vector<int> s(n), p(n);
//    p[0] = -1;
//    for (int i = 1; i < n; i++) {
//        std::cin >> p[i];
//        p[i]--;
//    }
//    for (int i = 0; i < n; i++) {
//        char c;
//        std::cin >> c;
//        s[i] = c == 'W' ? 1 : -1;
//    }
//    for (int i = n - 1; i > 0; i--) {
//        s[p[i]] += s[i];
//    }
//    std::cout << std::count(s.begin(), s.end(), 0) << "\n";
//}
// 
// 但是，没有说 a 的parent 必然小于 a 啊。




// 174209488 	Oct/01/2022 14:31UTC+8 	Ouha 	1676G - White-Black Balanced Subtrees 	GNU C++17 	Accepted 	234 ms 	400 KB

int dfsa1(myvvi& vvi, int node, int& ans, string& s);

void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    
    //myvi vi(sz1);
    //for (int i = 1; i < sz1; ++i)
    //{
    //    cin >> vi[i];
    //    --vi[i];
    //}

    myvvi vvi(sz1);
    int t2;
    for (int i = 1; i < sz1; ++i)
    {
        cin >> t2;
        --t2;
        vvi[t2].push_back(i);
    }

    string s;
    cin >> s;
    
    int ans = 0;
    
    dfsa1(vvi, 0, ans, s);

    cout << ans << endl;
}

// return  W+, B-
int dfsa1(myvvi& vvi, int node, int& ans, string& s)
{
    if (vvi[node].empty())
    {
        return s[node] == 'W' ? 1 : -1;
    }

    int t2 = s[node] == 'W' ? 1 : -1;
    for (int nxt : vvi[node])
    {
        t2 += dfsa1(vvi, nxt, ans, s);
    }
    if (t2 == 0)
        ++ans;

    return t2;
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
