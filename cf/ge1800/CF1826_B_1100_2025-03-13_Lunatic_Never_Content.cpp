
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





// 310340061 	Mar/13/2025 10:57UTC+8 	Ouha 	1826B - Lunatic Never Content 	C++20 (GCC 13-64) 	Accepted 	171 ms 	4000 KB 

// test case 2, 494th, expect 1, but found 2... xiangbuchu
// 0 0 1 2 ... gcd xiecuole
// a way to print test case. wangji contest shi shenme shuchu le

// diffs' gcd
int gcda1(int, int);
void fun1(bool show = false)
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::vector<int> vi(sz1);

    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    if (show) {
        for (int i : vi) {
            std::cout<<i<<',';
        }
        std::cout<<std::endl;
    }

    int t2 = std::abs(vi[0] - vi[sz1 - 1]);
    for (int i = 1; i < sz1 / 2; ++i) {
        // std::cout<<t2<<",   "<<vi[i]<<','<<vi[sz1 - 1 - i]<<std::endl;
        t2 = gcda1(t2, std::abs(vi[i] - vi[sz1 - 1 - i]));
    }
    
    std::cout<<t2<<std::endl;
    
    
}

int gcda1(int a, int b) {
    if (a < b) {
        int t2 = a;
        a = b;
        b = t2;
    }
    if (b == 0) {
        return a;
    }
    return gcda1(b, a % b);
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

        if (_ == -1)
            fun1(true);
        fun1();
        
        #ifdef __test
        std::cout << "   ---/////--------/////---" << std::endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
