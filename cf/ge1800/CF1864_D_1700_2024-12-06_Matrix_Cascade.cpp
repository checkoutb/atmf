
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





// 295179444 	Dec/06/2024 14:00UTC+8 	Ouha 	1864D - Matrix Cascade 	C++20 (GCC 13-64) 	Accepted 	1453 ms 	8400 KB



// (i,j), x>i below,  y-j <= x-i,  y is j+-1, j+-2, j+-3 ...  
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<std::string> vs(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vs[i];
    }

    //std::vector<bool> vb(sz1); // flip
    std::vector<int> v2(sz1);
    std::vector<int> v3(sz1);

    int ans = 0;
    bool flp = false;
    int t2 = 0;
    for (int i = 0; i < sz1; ++i) {
        flp = false;
        std::vector<int> v4;
        for (int j = 0; j < sz1; ++j) {
            if ((v2[j] + v3[j]) % 2 != 0)
                flp = !flp;

            t2 = vs[i][j] - '0';
            if (flp)
                t2 = 1 - t2;

            if (t2) {

                #ifdef __test
                std::cout<<i<<", "<<j<<", "<<t2<<std::endl;
                #endif
                
                ++ans;
                v4.push_back(j);
            }
        }
        for (int i = 0; i < v4.size(); ++i) {
            v2[v4[i]]++;
            if (v4[i] + 1 < sz1) {
                v3[v4[i] + 1]++;
            }
        }

        v2[0] += v2[1];    // ...
        for (int i = 2; i < sz1; ++i) {
            v2[i - 1] = v2[i];
        }
        v2[sz1 - 1] = 0;
        for (int i = sz1 - 2; i >= 0; --i) {
            v3[i + 1] = v3[i];
        }
        v3[0] = 0;

        #ifdef __test
        std::cout<<" ======== "<<i<<" ======\n";
        for (int i = 0; i < sz1; ++i) {
            std::cout<<v2[i]<<", ";
        }
        std::cout<<std::endl;
        for (int i = 0; i < sz1; ++i) {
            std::cout<<v3[i]<<". ";
        }
        std::cout<<std::endl;
        #endif

    }

    std::cout<<ans<<std::endl;
    
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
