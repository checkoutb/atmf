
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
//#include <iomanip>    // std::setprecision(10)


//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE






// 264574771 	Jun/07/2024 17:45UTC+8 	Ouha 	1881F - Minimum Maximum Distance 	C++20 (GCC 13-64) 	Accepted 	781 ms 	25800 KB 


// min { max distance to a marked }
// farest, 2 marked node 's mid

int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, int& mxdis, int depth, std::vector<bool>& marked);
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1; // node
    std::cin>>sz2; // marked

    // std::vector<int> vmrk(sz2);
    std::vector<bool> marked(sz1);
    for (int i = 0; i < sz2; ++i) {
        std::cin>>kk;
        marked[kk - 1] = true;
    }

    std::vector<std::vector<int>> vvi(sz1);
    int a, b;
    for (int i = 1; i < sz1; ++i) {
        std::cin>>a>>b;
        --a, --b; // start from 1
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }
    
    int mxdis = 0; // edge's count

    dfsa1(vvi, 0, -1, mxdis, 0, marked);
    
    std::cout<<(mxdis + 1) / 2<<std::endl;
}

// return max depth that marked
int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, int& mxdis, int depth, std::vector<bool>& marked) {
    // int ans = -1;
    int t2 = 0;
    int mx1 {-1}, mx2 {-1};
    for (int nxt : vvi[node]) {
        if (nxt == parent)
            continue;

        t2 = dfsa1(vvi, nxt, node, mxdis, depth + 1, marked);

        if (t2 != -1) {
            // ans = std::max(t2, ans);
            if (t2 > mx1) {
                mx2 = mx1;
                mx1 = t2;
            } else if (t2 > mx2) {
                mx2 = t2;
            }
        }
    }
    #ifdef __test
    std::cout<<node<<", "<<mx1<<", "<<mx2<<" --- "<<depth<<"\n";
    #endif
    if (mx2 != -1)
        mxdis = std::max(mxdis, mx1 + mx2 - depth - depth); // edge's count

    if (mx1 == -1) {
        if (marked[node]) {
            mx1 = depth;
        }
    } else if (marked[node]) {
        mxdis = std::max(mxdis, mx1 - depth);
    }
    
    return mx1;
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
