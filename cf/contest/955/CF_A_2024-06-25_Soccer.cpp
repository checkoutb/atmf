

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// 
void fun1()
{
    int a, b;
    int x, y;
    std::cin>>a>>b>>x>>y;

    if (a == b || x == y) { // 题目有说 不相等。
        std::cout<<"NO"<<std::endl;
        return;
    }

    if ((a < b && x > y) || (a > b && x < y)) {
        std::cout<<"NO"<<std::endl;
        return;
    }
    
    std::cout<<"YES"<<std::endl;
    
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
        
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
