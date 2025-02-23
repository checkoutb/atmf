

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


/*

好像还行啊，现在 3277名， 希望不要错。

4675次AC C
1206次AC D
410 E
220 F1
80 F2

把unoffical 的踢掉，是 2976名

不要掉不要掉不要掉不要掉不要掉不要掉



*/



// g 时间到了， 而且 example 都过不了。。


// 之前看 F才1000多分， 看了一眼。。。

// 加面积，然后移除。  高始终一样， 就是看 底， 还有 底需要2个点， 顶角只需要一个点
// 1,2  4,6    5+2, 3+4,
// 两边开始选，  所以 顶角 选 对面中间的，中位数点。   点多的 做底。 不，还是 底边长的做底？
// 比如 [1,2,3, 1001,1002,1003] [1,2,3,4,5,6,7,8,9,10]  这个是 底边长的做底。就是 第一个数组做底。
// 如果底边相同呢？
// 还有半小时，感觉没戏。。
// 底边相同 选 点多的做底 ：  [1, 2, 10]  [1,2, 9,10] ... 好像没区别。
//
// 这个不会要dp吧？
// md, output 错了。
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
    std::cin>>sz2;

    std::vector<ll> v1(sz1);
    std::vector<ll> v2(sz2);

    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>v1[i];
    }
    for (size_t i = 0; i < sz2; ++i) {
        std::cin>>v2[i];
    }

    std::sort(std::begin(v1), std::end(v1));
    std::sort(std::begin(v2), std::end(v2));

    int t2 = v1.size() / 2 + (v1.size() % 2);
    std::vector<ll> v11(std::begin(v1), std::begin(v1) + t2);
    std::vector<ll> v12(std::begin(v1) + t2, std::end(v1));
    std::reverse(std::begin(v12), std::end(v12));
    
    t2 = v2.size() / 2 + (v2.size() % 2);
    std::vector<ll> v21(std::begin(v2), std::begin(v2) + t2);
    std::vector<ll> v22(std::begin(v2) + t2, std::end(v2));
    std::reverse(std::begin(v22), std::end(v22));

    ll ans = 0LL;

    std::vector<ll> vll;
    
    while (true) {
        if (v11.empty() && v12.empty())
            break;
        if (v21.empty() && v22.empty())
            break;
        
        if (v11.empty() || v12.empty()) {
            if (v21.size() + v22.size() < 2) {
                break;
            }
            int cnt = v11.size() + v12.size();  // cnt should must be 1
            while (!v21.empty() && !v22.empty() && cnt > 0) {
                ans += (v22[0] - v21[0]);
                vll.push_back(v22[0] - v21[0]);
                v21.erase(v21.begin());   // deque...
                v22.erase(v22.begin());
                --cnt;
            }
            break;
        } else if (v21.empty() || v22.empty()) {
            // if (v11.size() + v12.size() < 2) {
            //     break;
            // }
            // int cnt = v21.size() + v22.size();
            // while (!v11.empty() && !v12.empty()) {
                
            // }
            
            // cnt == 1
            ans += v12[0] - v11[0];
            vll.push_back(v12[0] - v11[0]);
            break;
        } else {

            int a1 = v12[0] - v11[0];
            int a2 = v22[0] - v21[0];

            if (a1 > a2) {
                ans += a1;
                vll.push_back(a1);
                v12.erase(v12.begin());
                v11.erase(v11.begin());
                if (v22.size() > v21.size()) {
                    v22.pop_back();
                } else {
                    v21.pop_back();
                }
            } else if (a1 < a2) {
                ans += a2;
                vll.push_back(a2);
                v22.erase(v22.begin());
                v21.erase(v21.begin());
                if (v12.size() > v11.size()) {
                    v12.pop_back();
                } else {
                    v11.pop_back();
                }
            } else {
                if (v12.size() + v11.size() > v21.size() + v22.size()) {
                    ans += a1;
                    vll.push_back(a1);
                    if (v21.size() > v22.size()) {
                        v21.erase(v21.begin());
                    } else {
                        v22.erase(v22.begin());
                    }
                } else {
                    vll.push_back(a2);
                    ans += a2;
                    if (v11.size() > v12.size()) {
                        v11.erase(v11.begin());
                    } else {
                        v12.erase(v12.begin());
                    }
                }
            }
            
        }
        
        
    }

    std::cout<<vll.size()<<std::endl;
    for (ll a : vll) {
        std::cout<<a<<' ';
    }
    std::cout<<std::endl;
    //std::cout<<ans<<std::endl;
    
    // int st1, st2, en1, en2;
    // st1 = st2 = 0;
    // en1 = v1.size() - 1;
    // en2 = v2.size() - 2;

    // while (st1 <= en1 && st2 <= en2) {
    //     int a1 = v1[en1] - v1[st1];
    //     int a2 = v2[en2] - v2[st2];

    //     if (a1 > a2) {
            
    //     } else if (a1 < a2) {

    //     } else {
 
    //     }
    // }
    
    
    
    
    
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
