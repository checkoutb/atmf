
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
#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
#include <map>
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





// 264567908 	Jun/07/2024 16:53UTC+8 	Ouha 	1881D - Divide and Equalize 	C++20 (GCC 13-64) 	Accepted 	93 ms 	100 KB 



// /div *div
// factor  count/sz1
// 1000
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::bitset<1000> bs;
    std::vector<int> prm;
    prm.push_back(2);
    for (int i = 3; i < bs.size(); i += 2) {
        if (!bs.test(i)) {
            prm.push_back(i);
            for (int j = i * 2; j < bs.size(); j += i) {
                bs.set(j);
            }
        }
    }

    std::map<int, int> map2;
    for (int num : vi) {
        for (int i = 0; i < prm.size() && num > 1; ++i) {
            while (num % prm[i] == 0) {
                ++map2[prm[i]];
                num /= prm[i];
            }
        }
        if (num > 1) {
            ++map2[num];
        }
    }

    for (auto& p : map2) {
        if (p.second % sz1 != 0) {
            std::cout<<"NO\n";
            return;
        }
    }
    
    std::cout<<"YES\n";
    
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
