

#include <bits/stdc++.h>

// std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;



// 第二天早上，想到：杨辉三角通项公式， 用异或代替+，即 如果 是奇数，那么kk，如果是偶数 那么0.
// 100万的阶乘 不太可能。 因为我只需要 奇数 or 偶数，所以 只需要判断 有 没有 偶数。 但是也挺难的啊。

// 靠， 昨天AC了 5道， 今天一看 2道被回退了。 不清楚，是不是 CF再重新测试提交的代码，所以导致 看起来回退了。。 不管了。 确实应该是处理中，在problemset中，点题目 点不进去的。 You can't run practice now or contest does not support practice

// 第三天： 偶数就是 有没有2. 所以 分解为 多少个2. 应该可以的。
// 1169 没有变色

/*


307809131 	01:56:07 	Ouha 	F - Goodbye, Banker Life 	C++20 (GCC 13-64) 	Time limit exceeded on test 3 	3000 ms 	2400 KB
307808469 	01:55:13 	Ouha 	F - Goodbye, Banker Life 	C++20 (GCC 13-64) 	Wrong answer on test 1 	30 ms 	4 KB
307805425 	01:51:11 	Ouha 	F - Goodbye, Banker Life 	C++20 (GCC 13-64) 	Wrong answer on test 2 	405 ms 	56 KB
307772659 	01:13:17 	Ouha 	E - Do You Love Your Hero and His Two-Hit Multi-Target Attacks? 	C++20 (GCC 13-64) 	Accepted 	483 ms 	48 KB
307742269 	00:45:11 	Ouha 	D - For Wizards, the Exam Is Easy, but I Couldn't Handle It 	C++20 (GCC 13-64) 	Accepted 	77 ms 	44 KB
307715467 	00:24:39 	Ouha 	C - Creating Keys for StORages Has Become My Main Skill 	C++20 (GCC 13-64) 	Accepted 	61 ms 	12 KB
307694052 	00:11:32 	Ouha 	B - Having Been a Treasurer in the Past, I Help Goblins Deceive 	C++20 (GCC 13-64) 	Accepted 	46 ms 	24 KB
307681721 	00:05:28 	Ouha 	A - New World, New Me, New Array 	C++20 (GCC 13-64) 	Accepted 	30 ms 	56 KB 

最后6分钟，一下子多了200个通过。我敲。


2391 	Ouha 	5 	158 	  	+ 00:05 	+ 00:11 	+ 00:24 	+ 00:45 	+ 01:13 	-2

这把完了，名字应该能变颜色了
2391是所有人的。



*/






// g. test case 2 错了。 看不到。
// tle. 应该还可以 继续利用 2^n
// 递归的， 第9行取第一个 == 第一行， 第10行前2个 == 第二行。 确实， 中间是0
// 13,14,15 的前缀 也是 1-3行
// 可惜，时间不够，而且还缺点思路
// 2N  2N-1 行的前缀 都是 5   55  。所以 奇数行 前2个元素是50， 偶数行 前2个是55
// 4N 4N-1 4N-2 4N-3 行 的前缀 就是 1-4行
// 所以可以递归，一直 /2 递归 。。 太繁了。


// n是 一百万， 那么 就是 一百万的元素？ 这么狂野？ 感觉没戏了。。
// 这个是杨辉三角，但是，。。。 知道了，难道直接 杨辉三角的 公式？ 直接算 第n行的？ 应该没用。不是加，是 异或。

/*

  5
 5 5
5 0  5
5 5  5  5          line 4
5  0 0 0  5
5 5  0 0  5  5
5 0 5 0 5 0  5
5 5 5 5 5 5 5 5     line 8
5 000000  (7个0)  5
5 5 (6ge 0)  5 5
5 0 5    (5个0)     5  0 5
5 5 5 5     4个0      5 5 5 5       12
5 000 5     3个0    50005
5 5 0 0 5 5  2个0   550055
5 0 5 0 5 0 5 1个0  5050505     15
55555555555555555555555555  16 

5 15个0 5
5 5  14  5 5
5 

55555555


1 2 4 8 16 32 64 。。 ？  1百万里 离 2^n 最远的是 什么数？

这图，似乎是 斜着下去的。

还有， 8+2 行 是 2侧2个5， 8+4 是 两侧 4个五   8+8 两侧 8个5
对， 2+2行，2个2个5 ， 4+2 2侧2个5， 4+4 两侧4个5


2^n + 2^m 了。

*/
void fun1()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
    std::cin>>kk;

    sz2 = 1;
    while ((sz2 << 1) <= sz1) {
        sz2 <<= 1;
    }

    sz2 >>= 1;    // sz2个 kk

    if (sz1 == sz2) {
        for (int i = 0; i < sz2; ++i) {
            std::cout<<kk<<' ';
        }
        std::cout<<std::endl;
        return;
    }
    
    int t2 = sz1 - sz2;
    int ta = 1;
    while ((ta << 1) <= t2) {
        ta <<= 1;
    }
    ta >>= 1;
    // 两侧 t2 个kk， 中间全0  。。。 ta！！！！

    // 硬算了

    std::vector<int> vi(ta + sz2);
    for (int i = 0; i < ta; ++i) {
        vi[i] = kk;
        vi[vi.size() - 1 - i] = kk;
    }

    while (vi.size() < sz1) {
        std::vector<int> v2(vi.size() + 1);
        v2[0] = v2[v2.size() - 1] = kk;

        for (int i = 1; i < v2.size() - 1; ++i) {
            v2[i] = vi[i - 1] ^ vi[i];
        }

        vi = v2;

        // std::cout<<vi.size()<<std::endl;
    }
 
    for (int i : vi) {
        std::cout<<i<<' ';
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
