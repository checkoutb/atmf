
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






// AC
// 261985152 	May/21/2024 16:48UTC+8 	Ouha 	1886C - Decreasing String 	C++20 (GCC 13-64) 	Accepted 	155 ms 	1300 KB



// tle

// fed zyx a  =>  if(idx > 0) --idx


// remove 1 char, lexico minq
// sz1 + (sz1 - 1) + (sz1 - 2) + ...
// how many time deleted
// pos = sz1 + (sz1 - 1) + ... (sz1 - x)
//     = (sz1 + sz1 - x) * (x + 1) / 2
// 2 * pos = (sz1*2 - x) * (x + 1) = -x^2 + (sz1*2 - 1) * x + sz1*2
// 
void fun1()
{
    // int sz1, sz2, kk;
    // std::cin >> sz1;

    std::string str;
    std::cin>>str;
    long long pos;
    std::cin>>pos;
    long long sz1 = str.size();
    int idx = 0;
    bool gotend = false;
    pos--;
    std::vector<int> vi;
    while (pos >= sz1)
    {
        pos -= sz1;
        --sz1;

        // std::cout<<pos<<", "<<sz1<<", "<<idx<<std::endl;

        if (gotend) {
            vi.pop_back();
        } else {
            // idx - 1
            if (!vi.empty() && str[vi.back()] > str[idx]) {
                vi.pop_back();
                continue;
            }
            
            while (idx + 1 < str.size() && str[idx] <= str[idx + 1]) {
                vi.push_back(idx);
                ++idx;
            }

            if (idx + 1 < str.size()) {
                ++idx;
            } else {
                gotend = true;
                // idx is last element, and not in vi
            }
        }
        
        
        // pos -= sz1;
        // if (gotend) {
        //     while (str[idx] == '_') {  // 'A' < '_' < 'a'
        //         --idx;
        //     }
        //     str[idx] = '_';
        // } else {
        //     while (idx + 1 < str.size() && str[idx] <= str[idx + 1])
        //         ++idx;
            
        //     if (idx + 1 < str.size()) {
        //         str[idx] = '_';
        //     } else {
                
        //     }
        // }
        // --sz1;

        
        // pos -= str.size();

        // if (idx > 0)    // ...
        //     --idx;
        // while (idx + 1 < str.size() && str[idx] <= str[idx + 1]) {
        //     ++idx;
        // }
        // if (idx + 1 < str.size()) {
        //     str.erase(idx, 1);
        // } else {
        //     str.pop_back();
        // }
        
        // if (gotend) {

        // } else {
        //     while (idx + 1 < str.size() && str[idx] <= str[idx + 1]) {
        //         ++idx;
        //     }
        //     if (idx + 1 < str.size()) {

        //     } else {
        //         gotend = true;
        //     }
        // }
        // --sz1;
    }
    
    // std::cout<<str[pos];

    #ifdef __test
    std::cout<<pos<<", "<<idx<<", "<<sz1<<"\n";
    for (int i : vi)
        std::cout<<i<<", ";
    std::cout<<std::endl;
    #endif
    
    std::cout<<str[pos >= vi.size() ? idx + (pos - vi.size()) : vi[pos]];
    
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
