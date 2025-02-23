

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// 互质，只能被1除。
// 1-2, 2-3, 3-4, 4-5
// 所以直接相减？ [1,1]=1, [1,2]=1 ..
void fun1()
{
    int a, b;
    std::cin>>a>>b;

    int ans = b-a;
    if (a == 1 && b == 1) {
        ans = 1;
    }
    
    std::cout<<ans<<std::endl;
    
    
    
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
