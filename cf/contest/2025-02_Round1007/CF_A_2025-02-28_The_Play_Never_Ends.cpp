

#include <bits/stdc++.h>


#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

// 2个人打，1个人看，   不能连续玩3次。   输的看
/*

1. k
2. w
3. w
k




*/ 
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
    
    if (sz1 % 3 == 1) {
        std::cout<<"yes\n";
    } else {
        std::cout<<"no\n";
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
