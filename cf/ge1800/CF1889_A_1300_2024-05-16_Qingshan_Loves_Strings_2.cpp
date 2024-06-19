
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
//#include <limits.h>   // INT_MAX

#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
//#include <unordered_map>
//#include <string.h>       // memset

//using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = std::vector<std::vector<int>>;
using myvi = std::vector<int>;
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE






// g
// 会发生次序的乱序的，不知道怎么处理。
// 比如 001110



void fun1()
{
    int sz1;
    std::cint>>sz1;
    std::string s;
    std::cin>>s;
    if (sz1 % 2) {
        std::cout<<-1<<std::endl;
        return;
    }

    std::vector<int> vi; // from 0
    std::vector<int> v2; // to sz1
    int st = 0, en = sz1 - 1;
    while (st < en) {
        if (s[st] == s[en]) {
            if (s[st] == '0') {
                // 0xx0  0xx0 01
                ++st;
                v2.push_back(s.size());
            } else {
                // 1xx1  01 1xx1
                
            }
        } else {
            ++st, --en;
        }
    }
    
}


// g 没办法追踪。。 看来得必须 直接 操作 str
// 
// 0,1
// good: ai != ak-i+1,  k is sz1   i=1..k   fei zhou duicheng
// insert 01 to make good
// 从2侧开始  如果 相同，只能在一侧加。
// 100    001   01100  001    100 001
// 111   010   11 01  0111 01
void fun1_err()
{
    int sz1, sz2, kk;
    std::cin >> sz1;

    std::string s;
    std::cin>>s;

    if (sz1 % 2) {
        std::cout<<-1<<std::endl;
        return;
    }
    
    // 01
    
    // std::stack<int> stk1, stk2;
    std::vector<int> stk1, stk2;

    int st = 0, en = sz1 - 1;
    while (st <= en) {
        stk1.push_back(s[st++] - '0');
        if (st <= en) {
            stk2.push_back(s[en--] - '0');
        }
    }
    std::ranges::reverse(stk1);
    std::ranges::reverse(stk2);
    std::vector<int> vi;
    std::vector<int> v2;
    int ti = 0, t2 = 0;
    while (!stk1.empty() || !stk2.empty()) {
        if (vi.size() + v2.size() > 300)
            break;
        if (stk1.size() + stk2.size() <= 1)
            break;
        if (stk1.empty()) {
            stk1.push_back(stk2.front());
            stk2.erase(stk2.begin());
        }
        if (stk2.empty()) {
            stk2.push_back(stk1.front());
            stk1.erase(stk1.begin());
        }
        if (stk1.back() == stk2.back()) {
            if (stk1.back() == 0) {
                // 0xxx0 -> 0xxx0 01 -> xxx0 0
                stk1.pop_back();
                stk2.push_back(0);
                v2.push_back(t2);
                ++t2;
            } else {
                // 1xxx1 -> 01 1xxx1 -> 1 1xxx
                stk1.push_back(1);
                stk2.pop_back();
                vi.push_back(ti);
                ti += 1;
            }
        } else { // != is good
            stk1.pop_back();
            stk2.pop_back();
            ++ti, ++t2;
        }
    }

    // 001110 0{01}1
    t2 = sz1 + (v2.size() + vi.size()) * 2;
    for (int i = v2.size() - 1; i >= 0; --i) {
        #ifdef __test
        std::cout<<v2[i]<<",,,, "<<(t2 - v2[i])<<std::endl;
        #endif
        vi.push_back(t2 - v2[i]);
    }
    
    if (vi.size() <= 300) {
        
        
        std::cout<<vi.size()<<"\n";
        for (int i : vi)
            std::cout<<i<<' ';
        std::cout<<std::endl;
    } else {
        std::cout<<-1<<std::endl;
    }
    
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
    
    
    
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
