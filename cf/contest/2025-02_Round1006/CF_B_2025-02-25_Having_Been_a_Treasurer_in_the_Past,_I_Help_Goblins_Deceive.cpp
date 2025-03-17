

#include <bits/stdc++.h>

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// subseq, -_-
// 一半 中间 一半
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
    std::string str;
    std::cin>>str;

    char ch1 = '-';
    char ch2 = '_';
    int cnt1 = 0;
    int cnt2 = 0;

    for (char ch : str) {
        if (ch == ch1) {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }
    
    int t2 = cnt1 / 2;

    long long ans = 1LL * t2 * (cnt1 - t2) * cnt2;

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
