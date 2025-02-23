
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
//#include <climits>   // INT_MAX

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
//#include <iomanip>    // std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;
//#include <utility>  // pair (include by other header)

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE





// 305943227 	Feb/13/2025 20:49UTC+8 	Ouha 	1843D - Apple Tree 	C++20 (GCC 13-64) 	Accepted 	530 ms 	27300 KB 




// 多少叶子。
int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, std::vector<int>& vi);
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<std::vector<int>> vvi(sz1);
    int u,v;
    for (size_t i = 1; i < sz1; ++i) {
        std::cin>>u>>v;
        --u, --v;
        vvi[u].push_back(v);
        vvi[v].push_back(u);
    }

    std::vector<int> vi(sz1);   // leaf count

    dfsa1(vvi, 0, -1, vi);

    /////////////////////////

    std::cin>>sz2;
    for (size_t i = 0; i < sz2; ++i) {
        std::cin>>u>>v;
        --u, --v;
        std::cout<<(1LL * vi[u] * vi[v])<<std::endl;
    }
    
}

// return leaf count
int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, std::vector<int>& vi) {

    int t2 = 0;
    for (int nxt : vvi[node]) {
        if (nxt == parent)
            continue;
        t2 += dfsa1(vvi, nxt, node, vi);
    }
    if (t2 == 0)
        t2 = 1;
    vi[node] = t2;
    return t2;
}


int main()
{

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    
    int w = 1;
    
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:"<<std::endl;
    #endif
    std::cin>>w;  // <------   remove or not
    
    
    
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
