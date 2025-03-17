

#include <bits/stdc++.h>


#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;


// 睡了，明天再看。 本次就1题。  好像明天还看不了。要等几天才可以。

// 第二天： 昨天睡觉的时候，用计算器模拟了下，发现 不能和前面的 交换。 所以 第二题的 和前面交换的 分支 应该是 -1. 懒得起了。  昨天试了 2+1+3+4+5+6+7+8 。 发现+8 是36， 如果 n是8的话，那么 代码会 向前交换，但是 +8+7 还是36....
// 这道题目真的没有任何思路， 感觉就是 要平均，但是 一侧的 多叉 它可以自己消灭自己。 所以完全可能：
// node3 - en - st, st 后面有2叉，并且这2叉平衡，那么 完全可以 这2叉 互相拉锯， 最终又到 st。 然后 往 node3 走，然后 en。


// 崩盘了。。
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
    
    
    
    
    
    
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
