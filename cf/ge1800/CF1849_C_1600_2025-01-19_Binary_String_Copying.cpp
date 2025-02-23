
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
#include <set>
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






// 301707779 	Jan/19/2025 18:49UTC+8 	Ouha 	1849C - Binary String Copying 	C++20 (GCC 13-64) 	Accepted 	624 ms 	18100 KB


// last1， next0
// already sorted
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin >> sz2;


    // ...
    std::string str;
    std::cin>>str;
    
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        vi[i] = str[i] - '0';
    }

    std::vector<std::vector<int>> vvi(sz2, std::vector<int>(2));
    int t2;
    for (int i = 0; i < sz2; ++i) {
        std::cin>>t2;
        vvi[i][0] = t2 - 1;
        std::cin>>t2;
        vvi[i][1] = t2 - 1;
    }

    std::vector<int> lst1(sz1), nxt0(sz1);
    std::vector<int> srt(sz1);

    int lst1idx = -1;
    int nxt0idx = -1;
    int srtidx = 0;
    for (int i = 0; i < sz1; ++i) {
        lst1[i] = lst1idx;
        if (vi[i] == 1)
            lst1idx = i;

        if (i != 0 && vi[i] < vi[i - 1]) {
            srtidx = i;
        }
        srt[i] = srtidx;
        //std::cout<<"    "<<vi[i]<<", "<<srtidx<<", "<<srt[i]<<std::endl;
    }

    for (int i = sz1 - 1; i >= 0; --i) {
        nxt0[i] = nxt0idx;
        if (vi[i] == 0)
            nxt0idx = i;
    }

    std::set<std::pair<int, int>> set2;

    int l, r;
    bool ori = false;
    for (std::vector<int>& v2 : vvi) {
        l = v2[0], r = v2[1];
        if (srt[r] <= l) {
            ori = true;
            continue;
        }
        l = lst1[l];
        r = nxt0[r];

        #ifdef __test
        std::cout<<l<<", "<<v2[0]<<", "<<v2[1]<<", "<<r<<std::endl;
        #endif

        
        set2.insert(std::make_pair(l, r));
    }

    #ifdef __test
    for (int i : vi) {
        std::cout<<i;
    }
    std::cout<<std::endl;
    for (int i : srt) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;
    for (int i : lst1) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;

    for (int i : nxt0) {
        std::cout<<i<<", ";
    }
    std::cout<<std::endl;

    std::cout<<(ori ? "ori" : "no ori")<<std::endl;

    for (auto& p : set2) {
        std::cout<<p.first<<" - "<<p.second<<std::endl;
    }
    #endif


    
    std::cout<<(set2.size() + (ori ? 1 : 0))<<std::endl;
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
