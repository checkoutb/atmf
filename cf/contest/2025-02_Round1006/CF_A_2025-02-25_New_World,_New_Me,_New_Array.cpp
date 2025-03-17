

#include <bits/stdc++.h>

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// 
void fun1()
{

    int n,k,p;
    std::cin>>n>>k>>p;

    // -p - p

    if (n * p * -1 > k || n * p < k) {
        std::cout<<-1<<std::endl;
        return;
    }

    if (k < 0)
        k = -k;

    int ans = k / p;

    int t2 = k % p;
    if (t2 != 0)
        ++ans;

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
