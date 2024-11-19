

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// You have +458! Wow!   .. wow 还真要开了。++
// Wow! Coder Ouha competed in Codeforces Round 955 (Div. 2, with prizes from NEAR!) and gained +458 rating points taking place 7,180 
// 如果不卡 人机的话，还能上去好多。 我看到 1982C 和 1982B 的 通过人数 很接近， 10067 ， 10246
// 还有不太理解 round，今天 出现了 公告：35小时后 Educational codeforces round 167 。这个 round 才167。当然可能是 educational 的原因，  但不知道具体规则， cf 还有 多少种 round。。
// 还有，今天看到 昨天晚上的 round 955 的题目是 1982X。 最新的已经是 1986X 了， 这个 1986X 是哪次 round的？ 还是说，不属于任何 round，就是 普通的 题目？


// 第二天。提交 ok了。
// pretest2 是因为 if (idxen >= sz1) break;  导致 少算了一些。 因为此时 sum2 可能大于 en，需要 减去 vi[i] 后 符合。
// pretest3 是因为 int，改成 ll 后今天提交 ok了，  但是 想不出来 为什么会 溢出。
// ll 是昨天就改了，但是 一直人机验证。。。

// 知道了，比如 l，r 都是 10亿， 数组中全是 9亿， 那么 sum2 会变成 18亿， 然后下次  sum2 + vi[idxen] 就会是 27亿。


// 一直 人机验证。。。

// wrong on pretest3 ...

// wrong on pretest2 ...

// sum of seleced card is in [l, r]
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    ll st, en;
    std::cin>>st>>en;

    std::vector<ll> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vi[i];
    }

    ll idxen = 0;
    ll sum2 = 0;
    ll ans = 0;
    for (int i = 0; i < sz1; ++i) {
        while ((idxen < sz1) && (sum2 + vi[idxen] < st)) {
            sum2 += vi[idxen];
            idxen++;
        }
        #ifdef __test
        // std::cout<<"      "<<i<<", "<<idxen<<", "<<sum2<<std::endl;
        #endif
        if (idxen >= sz1) {
            ; // . 不能break
        } else {
            if (sum2 < st) {
                sum2 += vi[idxen++];  // . 9亿 < 10亿， +=， sum2 变成 18亿， 下次循环 计算while 的时候 就 27亿了
            }
        }
        if (sum2 < st) {
            break;
        }
        if (sum2 > en) {
            sum2 -= vi[i];
        } else {
            ans++;
            i = idxen - 1;
            sum2 = 0;
        }
    }
    
    std::cout<<ans<<std::endl;
    
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
