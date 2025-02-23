

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// 想到一个，

/*

  \ | /
   - -
  /   \

  3个节点有3条边， 如果取了 中间的节点，就不行。 取中间的节点，会4个连通，  取2侧的 节点就是 5连通。
  5个叶子
*/
// 相同边数， 取谁？ 似乎只能 遍历？


// 会tle？ 主要是 vp2 每次都复制的。 或者，vp2 不需要 太多的 元素？  。。 tle了。
// 还是说 只探测2次？
// + cnt > 2, 过了， 估计 2次(>=2) 就可以， >2 是3次。

int dfsa1(std::vector<std::pair<int, int>> vp2, int delNode, std::vector<std::vector<int>>& vvi);
void fun1() {
    int sz1;
    std::cin>>sz1;
    std::vector<std::vector<int>> vvi(sz1);
    int a, b;
    for (int i = 1; i < sz1; ++i) {
        std::cin>>a>>b;
        --a, --b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);
    }
    std::vector<std::pair<int, int>> vp(sz1);
    std::vector<std::pair<int, int>> vp2(sz1);
    for (size_t i = 0; i < sz1; ++i) {
        vp[i].first = vvi[i].size();
        vp[i].second = i;

        vp2[i].first = vvi[i].size();
        vp2[i].second = i;
    }
    std::sort(std::begin(vp), std::end(vp));
    int ans = vp.back().first;

    int t2 = 0;
    int cnt = 0;
    for (int i = vp.size() - 1; i >= 0; --i) {
        if (vp[i].first != vp.back().first)
            break;
        t2 = std::max(t2, dfsa1(vp2, vp[i].second, vvi));
        ++cnt;
        if (cnt > 2) {
            break;
        }
    }

    ans += t2 - 1;

    std::cout<<ans<<std::endl;
    
}

int dfsa1(std::vector<std::pair<int, int>> vp2, int delNode, std::vector<std::vector<int>>& vvi) {

    for (int idx : vvi[delNode]) {
        vp2[idx].first -= 1;
    }
    vp2[delNode].first = -1;

    std::sort(std::begin(vp2), std::end(vp2));

    return vp2.back().first;
}

// Test#4 ...

// 选择1个点， 移除 它的边 和 它
// 操作2次， 最大的 连通分量个数。 。。 是 多少个连通分量， 不是 连通分量 中节点最多， 后者只需要移除 叶子。
// 所以 答案必然是 1,2,3  bububu, 最多5，  就是 7个节点 满二叉树， 把第二层的 2个节点 全部删除。这样就 1个根节点 + 4个 叶子。  不， n叉树，  所以 只要把 边最多的节点 删除就可以了？ 似乎是的。
void fun1_error()
{
    int sz1, sz2, kk;

    std::cin>>sz1;
    
    std::vector<std::vector<int>> vvi(sz1);
    int a, b;

    for (size_t i = 0; i < sz1 - 1; ++i) {   // ... sz1-1...
        //std::cout<<"input "<<i<<std::endl;
        std::cin>>a>>b;
        --a, --b;
        vvi[a].push_back(b);
        vvi[b].push_back(a);

        //std::cout<<a<<".."<<b<<std::endl;
    }

    // std::vector<int> vi(sz1);   // how many edges

    std::vector<std::pair<int, int>> vp(sz1);
    
    for (size_t i = 0; i < sz1; ++i) {
        // vi[i] = vvi[i].size();
        vp[i].first = vvi[i].size();
        vp[i].second = i;
    }

    std::sort(std::begin(vp), std::end(vp));

    //std::cout<<"111"<<std::endl;
    
    int ans = 1;

    ans = vp[vp.size() - 1].first;

    int t2 = vp.back().second;

    for (size_t i = 0; i < sz1; ++i) {
        vp[i].first = vvi[i].size();
        vp[i].second = i;
    }

    //std::cout<<"222"<<std::endl;
    
    for (int idx : vvi[t2]) {  // remove edge
        vp[idx].first -= 1;
    }
    vp[t2].first = -1; // remove vertex

    std::sort(std::begin(vp), std::end(vp));

    ans += vp.back().first - 1;

    //std::cout<<"333"<<std::endl;

    std::cout<<ans<<std::endl;
}

// void dfsa1(int node, int parent, std::vector<std::vector<int>>& vvi, std::vector<int>& vi) {
    
// }


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
