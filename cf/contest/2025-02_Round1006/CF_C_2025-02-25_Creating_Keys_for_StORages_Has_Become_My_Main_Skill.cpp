

#include <bits/stdc++.h>

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;



// Thank the example!


// min not exist +
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;

    std::cin >> kk;
    
    int t2 = 0;
    int got = 0;
    bool coutkk = false;
    for (int i = 0; i < sz1 - 1; ++i) {
        if (coutkk) {
            std::cout<<kk<<' ';
            continue;
        }
        if ((i | kk) != kk) {
            // MEX is i
            std::cout<<kk<<' ';
            coutkk = true;
        } else {
            std::cout<<i<<' ';
            got |= i;
        }
    }

    if (coutkk) {
        std::cout<<kk;
    } else {
        if ((got | (sz1 - 1)) == kk) {
            std::cout<<sz1 - 1;
        } else {
            std::cout<<kk;
        }
    }

    std::cout<<std::endl;
    
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
