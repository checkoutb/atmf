
//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>

//#include <cstdio>
//#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cstdlib>
//#include <cmath>
//#include <climits>   // INT_MAX

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset
//#include <iomanip>    // std::setprecision(10)
//#include <utility>  // pair (include by other header)

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE



// 296806250 	Dec/16/2024 15:27UTC+8 	Ouha 	1856E1 - PermuTree (easy version) 	C++20 (GCC 13-64) 	Accepted 	78 ms 	50300 KB
// 看了 tutorial，但是应该没看懂。
// 从网上 抄 了一个 二分数组，使得 子数组和 的差值最小的 算法 ( 就是 splita2 )。 AC了。


// 自己试下，好像出问题了， 我没看懂 {1,3} 返回2 是什么操作？ 而且这还是对的， 我写的是返回1，错了。
// 看错了，我的返回2 。。。
// 抄的是 根据[i] 计算 [i+1]， 我写的是 根据[i] 计算 [i] 所以 j需要反序，不然会被影响。
// 还是不对。。
// ok了。

// tle ..


// 这个 就是二叉搜索树啊。
// 无重复值的 二叉搜索树中， 任意一个节点A，A的左子树中的 所有节点 都是 小于 A的右子树中的所有节点的。
// 所以只需要 post-order
// LCA, 也没问题， 左子树的所有节点， 和 右子树的左右节点的 LCA 就是 当前节点啊。
//
// 。。没说是 二叉的。。dfs时才发现没有left，right。。
// 不过也是 二叉搜索树的思路， 就是把 某几个叉合并 作为 左子树，剩下的叉合并作为右子树， 来满足 搜索二叉树的性质， 这个是 越平均越好。 就是 一个数组，划分2个子数组，让它们的和 尽可能接近，这个 是不是01背包硬算？ 但是 5000个结点， 数组的和是5000， 这种好算吗？




// return each part's sum
std::pair<int, int> split_array_to_2_part_let_sum_close(std::vector<int>& vi) {
    if (vi.empty())
        return std::make_pair(0, 0);

    int t2 = 0;
    int sum2 = std::accumulate(std::begin(vi), std::end(vi), 0);
    std::vector<std::vector<int>> vvi(vi.size(), std::vector<int>(sum2 / 2 + 1));

    for (int i = 0; i < vi.size(); ++i) {
        for (int j = 1; j <= sum2 / 2; ++j) {
            vvi[i][j] = i > 0 ? vvi[i - 1][j] : 0;
            if (j >= vi[i]) {
                if (i > 0) {
                    t2 = vvi[i - 1][j - vi[i]] + vi[i];
                } else {
                    t2 = vi[i]; // i == 0
                }

                if (t2 > vvi[i][j])
                    vvi[i][j] = t2;
            }
        }
    }

    t2 = vvi[vi.size() - 1][sum2 / 2];
    return std::make_pair(t2, sum2 - t2);
}

int splita2(std::vector<int>& v2, int got, int sum2, int idx) {
    return split_array_to_2_part_let_sum_close(v2).first;
}


int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, int &ans);
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::vector<std::vector<int>> vvi(sz1);

    // p2,p3..
    int t2 = 0;
    for (int i = 0; i < sz1 - 1; ++i) {
        // i+1
        //
        std::cin>>t2;
        --t2;  // from 0
        vvi[i + 1].push_back(t2);
        vvi[t2].push_back(i + 1);
    }

    int ans = 0;

    dfsa1(vvi, 0, -1, ans);

    std::cout<<ans<<std::endl;
}

int splita1(std::vector<int>& vi);

int dfsa1(std::vector<std::vector<int>>& vvi, int node, int parent, int &ans) {

    std::vector<int> vi;
    int t2 = 0;
    int cnt = 0;
    for (int nxt : vvi[node]) {
        if (nxt == parent)
            continue;

        t2 = dfsa1(vvi, nxt, node, ans);
        vi.push_back(t2);
        cnt += t2;
    }

    t2 = splita1(vi);

    ans += t2;

    return cnt + 1;
}

int splita2(std::vector<int>& v2, int got, int part_sum, int idx);
int splita2__(std::vector<int>& v2, int got, int part_sum, int idx);
int splita2__ok(std::vector<int>& v2, int got, int part_sum, int idx);


int splita1(std::vector<int>& vi) {
    std::sort(std::begin(vi), std::end(vi));
    std::reverse(std::begin(vi), std::end(vi));

    int sum2 = std::accumulate(std::begin(vi), std::end(vi), 0);

    int got = splita2(vi, 0, sum2, 0);

    #ifdef __test
    int t4 = splita2__ok(vi, 0, sum2, 0);

    if (t4 != got) {
        std::cout<<" ??? "<<t4<<", got: "<<got<<std::endl;
        for (int i : vi) {
            std::cout<<i<<" ";
        }
        std::cout<<"\n=========\n";
    }

    #endif
    

    
    return got * (sum2 - got);
}

// split and multiple
int splita1__eee(std::vector<int>& vi) {   // error: [1,2,2,3] cannot remove duplicate
    std::sort(std::begin(vi), std::end(vi));
    int dup = 0;
    //int sum2 = 0;
    int part_sum = 0;
    std::vector<int> v2;
    //v2.push_back(vi[0]);
    for (int i = 0; i < vi.size(); ++i) {
        //sum2 += vi[i];
        if (i + 1 < vi.size() && vi[i] == vi[i + 1]) {
            ++i;
            dup += vi[i];
        } else {
            part_sum += vi[i];
            v2.push_back(vi[i]);
        }
    }

    int got = splita2(v2, 0, part_sum, 0);

    return (got + dup) * (part_sum - got + dup);
}






// AC后，再自己写一下。
int splita2__ok(std::vector<int>& v2, int got, int sum2, int idx) {
    
    if (v2.empty()) // ....
        return 0;
    
    // [i][j]  下标 <= i 的元素 中 抽取 一些元素，使得 这些元素的和 小于 且 最接近 j。
    std::vector<std::vector<int>> vvi(v2.size(), std::vector<int>(sum2 / 2 + 1));
    
    for (int i = 0; i < v2.size(); ++i) {
        for (int j = 1; j <= sum2 / 2; ++j) {
        //for (int j = sum2 / 2; j >= 1; --j) {  // 反序，正序都可以

            vvi[i][j] = (i > 0 ? vvi[i - 1][j] : 0); // 本元素不加入子集。
            
            if (j >= v2[i]) { // 才有空间 减去v2[i]。 就是有空间可以加 v2[i]。  j<v2[i]的话，v2[i] 肯定加不进去   这个if 就是 本元素尝试加入子集
                int t2 = 0;
                if (i == 0) {
                    // 第一个元素，且加入子集，那么 子集和 必然是 元素值。
                    t2 = v2[i]; // j>=v2[i], 且i=0，那么必然是 取 v2[i]. 作为 小于等于j 的最大值
                } else {
                    // 非第一个元素，那么需要 使用 以上一个元素为截止的 子集 的 和。
                    // 本元素加入后 和 变成 j，那么 以上个元素为截止的子集的和 需要是 j-v2[i]
                    
                    t2 = vvi[i - 1][j - v2[i]] + v2[i]; // 要利用上一个元素为止的 子集，这个子集的 小于等于 j-v2[i] 的最大可获得的和 加上 本元素，就是 本元素为止的子集的 小于等于 j 的最大值
                }
                if (t2 > vvi[i][j])
                    vvi[i][j] = t2;
            }
        }
    }

    #ifdef __test
    std::cout<<"mine\n";
    for (myvi& v : vvi) {
        for (int i : v) {
            std::cout<<i<<". ";
        }
        std::cout<<std::endl;
    }
    #endif
    
    return vvi[v2.size() - 1][sum2 / 2];
}


int splita2__ok_(std::vector<int>& v2, int got, int sum2, int idx) {
    std::vector<std::vector<int>> vvi(v2.size() + 1, std::vector<int>(sum2 / 2 + 1));

    for (int i = 0; i < v2.size(); ++i) {
        for (int j = 1; j <= sum2 / 2; ++j) {
            vvi[i + 1][j] = vvi[i][j];
            if (v2[i] <= j && vvi[i][j - v2[i]] + v2[i] > vvi[i][j]) {
                vvi[i + 1][j] = vvi[i][j - v2[i]] + v2[i];
            }
        }
    }

    #ifdef __test
    std::cout<<"ans:\n";
    for (myvi& v : vvi) {
        for (int i : v) {
            std::cout<<i<<", ";
        }
        std::cout<<std::endl;
    }
    #endif
    
    int t2 = vvi[v2.size()][sum2 / 2];
    return t2;
    //return t2 * (sum2 - t2);
}

int splita2__tle(std::vector<int>& v2, int got, int part_sum, int idx) {
    if (got > (part_sum - got)) {
        return got;
    }
    if (idx == v2.size()) {
        return got;
    }
    int t3 = splita2(v2, got + v2[idx], part_sum, idx + 1);
    int t2 = splita2(v2, got, part_sum, idx + 1);

    if (std::abs(t2 - (part_sum - t2)) < std::abs(t3 - (part_sum - t3))) {
        return t2;
    } else {
        return t3;
    }
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    // std::cin>>w;
    

    // std::vector<int> vi = {1,3};

    // std::cout<<splita2__(vi, 0, 4, 0)<<std::endl;
    // std::cout<<splita2(vi, 0, 4, 0)<<std::endl;
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
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
