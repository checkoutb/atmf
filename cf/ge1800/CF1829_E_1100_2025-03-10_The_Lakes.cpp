
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





// 309706383 	Mar/10/2025 13:39UTC+8 	Ouha 	1829E - The Lakes 	C++20 (GCC 13-64) 	Accepted 	312 ms 	94500 KB



//

int dfsa1(std::vector<std::vector<int>>& vvi, int r, int c);
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    std::vector<std::vector<int>> vvi(sz1, std::vector<int>(sz2));
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < sz2; ++j) {
            std::cin>>vvi[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < sz2; ++j) {
            if (vvi[i][j] != 0)
                ans = std::max(ans, dfsa1(vvi, i, j));
        }
    }
    
    std::cout<<ans<<std::endl;
    
    
}

int dfsa1(std::vector<std::vector<int>>& vvi, int r, int c) {
    static int arr[5] = {1,0,-1,0,1};
    if (r < 0 || c < 0 || r == vvi.size() || c == vvi[0].size() || vvi[r][c] == 0) {
        return 0;
    }
    int ans = vvi[r][c];
    vvi[r][c] = 0;
    for (int i = 0; i < 4; ++i) {
        ans += dfsa1(vvi, r + arr[i], c + arr[i + 1]);
    }
    return ans;
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
