
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


//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE






// g       gcd

// tle  939931150 385940696

// 2^n
// 0.75 = 0.5 + 0.25
// 0.2
// 2.5
void fun1()
{
    int sz1, sz2, kk;
    //std::cin >> sz1; // apple
    //std::cin>>sz2; // people

    int apple, person;
    std::cin>>apple>>person;

    apple %= person;

    int ans = 0;
    std::set<int> set2; // seen apple, check if there is a cirle(loop)
    while (apple != 0) {
        std::cout<<apple<<std::endl;
        if (set2.find(apple) != set2.end()) {
            ans = -1;
            break;
        }
        set2.insert(apple);
        ans += apple; // every piece cut to 2 half
        apple <<= 1;
        apple %= person;
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
