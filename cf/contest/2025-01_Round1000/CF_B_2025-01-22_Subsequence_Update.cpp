

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;



// ... 用了 t2 = ans;  但是 ans 已经 min(ans, t2) 了。。   加了个 t3，过了。 

// 11 2 13 [4 5 6] 2 3 11 11

// Test#2 错了。。看不到输入。。

// a's seq, reverse
// min value of [l, r]
// 最小的， 连续
// [l,r] 取k个， l前面取k个，
// seq 如果 一部分在l前面，一部分在r后面，有些部分 似乎没有意义，不会影响[l,r]
// 是的， 比如 l前面取 k-1， [l,r]取k， r后面取1个， reverse，r后的那一个到 l前面了， 不会影响 l,r
void fun1()
{
    int sz1, sz2, kk;

    int st, en;   // l r
    std::cin>>sz1;
    std::cin>>st;
    std::cin>>en;

    --st, --en;
    
    std::vector<int> vi(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    std::vector<int> v2(std::begin(vi), std::begin(vi) + st);
    std::vector<int> vlr(std::begin(vi) + st, std::begin(vi) + en + 1);
    std::vector<int> v3(std::begin(vi) + en + 1, std::end(vi));

    std::sort(std::begin(v2), std::end(v2));
    std::sort(vlr.begin(), vlr.end());
    std::sort(v3.begin(), v3.end());

    #ifdef __test
    for (int i : v2) {
        std::cout<<i<<',';
    }
    std::cout<<std::endl;
    for (int i : vlr) {
        std::cout<<i<<'.';
    }
    std::cout<<std::endl;
    for (int i : v3) {
        std::cout<<i<<',';
    }
    std::cout<<std::endl;
    #endif 

    ll ans = std::accumulate(std::begin(vlr), std::end(vlr), 0LL);
    ll t2 = ans;
    ll t3 = ans;
    for (int i = 0, j = vlr.size() - 1; i < v2.size() && j >= 0; ++i, --j) {
        if (vlr[j] > v2[i]) {
            t2 -= vlr[j];
            t2 += v2[i];
        } else {
            break;
        }
    }
    ans = std::min(ans, t2);
    
    t2 = t3;  // ....
    for (int i = 0, j = vlr.size() - 1; i < v3.size() && j >= 0; ++i, --j) {
        if (vlr[j] > v3[i]) {
            t2 -= vlr[j];
            t2 += v3[i];
        } else {
            break;
        }
    }
    ans = std::min(ans, t2);

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
