
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






// 299138204 	Dec/31/2024 15:06UTC+8 	Ouha 	1851E - Nastya and Potions 	C++20 (GCC 13-64) 	Accepted 	921 ms 	34100 KB


//

int dfsa1(std::vector<bool>& infi, std::vector<int>& costs, std::vector<std::vector<int>>& vvi, int idx, std::vector<int>& mncost);

void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;  // potion
    std::cin>>sz2; // infinity

    std::vector<int> costs(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>costs[i];
    }

    std::vector<bool> infi(sz1);
    int t2, t3;
    for (int i = 0; i < sz2; ++i) {
        std::cin>>t2;
        --t2;
        infi[t2] = true;
    }

    std::vector<std::vector<int>> vvi(sz1);  // 配方
    for (int i = 0; i < sz1; ++i) {
        std::cin>>t2;
        while (t2-- > 0) {
            std::cin>>t3;
            --t3;
            vvi[i].push_back(t3);
        }
    }

    std::vector<int> mncost(sz1, -1);

    for (int i = 0; i < sz1; ++i) {
        dfsa1(infi, costs, vvi, i, mncost);
    }
    
    for (int i : mncost) {
        std::cout<<i<<' ';
    }
    std::cout<<std::endl;
}


int dfsa1(std::vector<bool>& infi, std::vector<int>& costs, std::vector<std::vector<int>>& vvi, int idx, std::vector<int>& mncost) {
    if (mncost[idx] != -1) {
        return mncost[idx];
    }
    if (infi[idx]) {
        mncost[idx] = 0;
        return mncost[idx];
    }
    mncost[idx] = costs[idx];

    if (!vvi[idx].empty()) {
        int spend = 0;
        for (int i = 0; i < vvi[idx].size(); ++i) {
            spend += dfsa1(infi, costs, vvi, vvi[idx][i], mncost);  // overflow, so: if (spend >= mncost[idx])
            if (spend >= mncost[idx]) {
                break;
            }
        }
        if (spend < mncost[idx])
            mncost[idx] = spend;
    }
    return mncost[idx];
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
