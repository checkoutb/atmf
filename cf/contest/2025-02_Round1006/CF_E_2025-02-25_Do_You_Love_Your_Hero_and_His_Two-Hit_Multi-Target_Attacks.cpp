

#include <bits/stdc++.h>

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// 距离 == 绝对值  所以是 相同x 或 相同y ？
// 500 能覆盖 10^5 ？  (1+499)*(500)/2 = 125000 > 10^5   但，是充满的吗？ 当做 充满的写
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>kk;
    
    std::vector<std::pair<int, int>> vp;

    int mxy = 0;
    int x = 0;
    while (kk > 0) {
        int kk2 = kk;
        int cnt = 0;
        // for (int y = 0; y <= 500; ++y) {   // y's mx is desc
        //     if (x + y <= kk) {
        //         kk -= x + y;
        //         vp.push_back(std::make_pair(x, y));
        //     } else {
        //         break;
        //     }
        // }
        while (mxy <= 555) {
            if (cnt <= kk) {
                kk -= cnt;
                vp.push_back(std::make_pair(x, mxy));
                ++mxy;
                ++cnt;
            } else {
                break;
            }
        }
        ++x;
    }

    if (vp.empty()) {
        vp.push_back(std::make_pair(-1,-1));
    }
    
    std::cout<<vp.size()<<std::endl;
    for (auto& [x, y] : vp) {
        std::cout<<x<<' '<<y<<std::endl;
    }
    
    
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
