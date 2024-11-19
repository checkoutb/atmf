
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
#include <climits>

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
//#include <utility>  // pair

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE







// 269820399 	Jul/11/2024 12:36UTC+8 	Ouha 	1873G - ABBC or BACB 	C++20 (GCC 13-64) 	Accepted 	62 ms 	0 KB 


// ABAAAAA
// .. B pfx, sfx, A cnt
// AABAAABA ... AABAABAB   AABBAABA
void fun1()
{
    std::string str;
    std::cin>>str;

    int sz1 = str.size();
    // int cnt = 0;
    // for (int i = 1; i < sz1; ++i) {
    //     if (str[i - 1] == 'A' && str[i] == 'B') {
    //         ++cnt;
    //         str[i - 1] = 'B';
    //         str[i] = 'C';
    //     } else if (str[i - 1] == 'B' && str[i] == 'A') {
            
    //     }
    // }

    // int pfxA = 0;
    // int sfxA = 0;
    // for (int i = 0; i < sz1; ++i) {
    //     if (str[i] == 'A') {
    //         ++pfxA;
    //     } else {
    //         sfxA = 0;
    //         while (i + 1 < sz1 && str[i + 1] == 'A') {
    //             ++sfxA;
    //             ++i;
    //         }

    //         cnt += std::max(sfxA, pfxA);
    //         pfxA = 0;
    //     }
    // }
    
    int cntA = 0;
    bool bb = str[0] == 'B' || str[sz1 - 1] == 'B';
    int mnCntA = INT_MAX;
    int tmpA = 0;

    for (int i = 0; i < sz1; ++i) {
        if (str[i] == 'A') {
            ++cntA;
            ++tmpA;
        } else {
            if (tmpA != 0) {
                mnCntA = std::min(tmpA, mnCntA);
            }
            tmpA = 0;
            if (!bb && i + 1 < sz1 && str[i + 1] == 'B') {
                bb = true;
            }
        }
    }
    if (tmpA != 0) {
        mnCntA = std::min(tmpA, mnCntA);
    }

    if (cntA == 0) {
        std::cout<<0<<std::endl;
    } else {
        if (bb) {
            std::cout<<cntA<<std::endl;
        } else {
            std::cout<<(cntA - mnCntA)<<std::endl;
        }
    }
    
    
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
