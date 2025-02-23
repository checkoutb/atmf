
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
#include <climits>   // INT_MAX

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






// 299142846 	Dec/31/2024 16:04UTC+8 	Ouha 	1850H - The Third Letter 	C++20 (GCC 13-64) 	Accepted 	875 ms 	25100 KB


//

bool dfsa1(std::vector<long long>& position, std::vector<std::vector<std::pair<int, int>>>& vvp, int idx, long long pos);

void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2;

    std::vector<std::vector<std::pair<int, int>>> vvi(sz1); // [a] = [[b,d],[b,d]]
    
    int a,b,d;
    for (int i = 0; i < sz2; ++i) {
        std::cin>>a>>b>>d;
        --a, --b;

        vvi[a].push_back(std::make_pair(b, d));
        vvi[b].push_back(std::make_pair(a, -d));
    }

    std::vector<long long> position(sz1, LLONG_MAX);

    for (int i = 0; i < sz1; ++i) {
        if (position[i] == LLONG_MAX) {
            if (!dfsa1(position, vvi, i, 0)) {
                std::cout<<"no\n";
                return;
            }
        }
    }

    // #ifdef __test
    // for (int i : position) {
    //     std::cout<<i<<", ";
    // }
    // std::cout<<std::endl;
    // #endif
    
    std::cout<<"yes\n";
}


// set position, return is_valid
bool dfsa1(std::vector<long long>& position, std::vector<std::vector<std::pair<int, int>>>& vvp, int idx, long long pos) {
    if (position[idx] == LLONG_MAX) {
        position[idx] = pos;
    } else {
        return position[idx] == pos;
    }

    for (auto& [b, d] : vvp[idx]) {
        if (!dfsa1(position, vvp, b, pos + d)) {
            return false;
        }
    }
    
    return true;
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
