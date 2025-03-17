

#include <algorithm>
#include <bits/stdc++.h>


#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

// not perfect square
// 2 1 3 4 5   (n)*(n+1)/2  ?   == a*a   n*(n+1)=a*a*2     aa2: 2,4,18,32,50 72..  8*9=72
// 1234  10
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
  
    if (sz1 == 1) {
        std::cout<<-1<<std::endl;
        return;
    }
    
    long long t2 = 3LL;
    long long sum2 = 3LL;

    std::vector<ll> vll(sz1 + 1, 0);
    for (ll i = 0; i < vll.size(); ++i) {
        vll[i] = i * i;
    }

    std::vector<ll> vans(sz1);
    vans.push_back(2);
    vans.push_back(1);

    int idx = 0;
    for (int i = 2; i < sz1; ++i) {
        while (idx < vll.size() && sum2 + t2 > vll[idx]) {
            idx += 1;
        }
        if (sum2 + t2 == vll[idx]) {
            #ifdef __test
            // std::cout<<"         "<<t2<<", "<<vll[idx]<<std::endl;
            #endif
            // std::cout<<(t2 + 1)<<' '<<t2<<' ';

            if (t2 + 1 <= sz1) {
                vans[i] = t2 + 1;
                vans[i + 1] = t2;
            } else {
                vans[i] = vans[i - 1];
                vans[i - 1] = t2;
            }

            ++i;
            sum2 += t2 + t2 + 1;
            t2 += 2;
        } else {
            // std::cout<<t2<<' ';
            vans[i] = t2;
            ++t2;
            sum2 += t2;
        }
    }
    
    for (ll t2 : vans) {
        std::cout<<t2<<' ';
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
