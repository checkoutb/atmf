

#include <bits/stdc++.h>

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// bi>bj   inversion    min
// pfx bigger then [i], sfx smaller then [i]
// n < 2001 所以 硬算？   4*10^6 这种在cf 是可以 硬算的还是 不可以的？  估计还有一个 hard版本？
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;

    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }
    int ans = 0;
    int totalInv = 0;
    int mxDec = 0;
    int l = 0;
    int r = 0;
    for (int i = 0; i < sz1; ++i) {
        int ls = 0;
        int bg = 0;
        int t2 = vi[i];
        for (int j = i + 1; j < sz1; ++j) {
            if (vi[j] > t2) {
                ++bg;
            } else if (vi[j] < t2) {
                ++ls;
                // ++totalInv;
            }
            // mxDec = std::max(mxDec, bg - ls);
            if ((ls - bg) > mxDec) {
                mxDec = ls - bg;
                l = i;
                r = j;
            }
        }
    }

    std::cout<<(l+1)<<' '<<(r+1)<<std::endl;
    // ans = totalInv - mxDec;
    
    // std::cout<<ans<<std::endl;
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
    std::cin>>w;   // <----------- remove it or not
        
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
