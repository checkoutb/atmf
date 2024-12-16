
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
//#include <numeric>            // accumulate
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





// 295700321 	Dec/09/2024 13:19UTC+8 	Ouha 	1863D - Two-Colored Dominoes 	C++20 (GCC 13-64) 	Accepted 	108 ms 	100 KB



// 一黑一白
// 每行，黑.cnt = bai.cnt
// 每列，hei=bai
// 已给出位置，只是涂色
//
// 看起来 是成对出现的。 如果横者，那么 row 已经 一黑一白 平衡了， column必须有另外一个，横躺，颜色相反
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    std::cin>>sz2; // string.size

    std::vector<std::string> vs(sz1);
    
    for (int i = 0; i < sz1; ++i) {
        std::cin>>vs[i];
    }

    std::vector<int> vi(sz2, -1); // L' row   or  -1

    int lastUD = -1; // 左侧的未匹配的 竖着的  U's column
    int t2 = 0;
    for (int i = 0; i < sz1; ++i) {
        for (int j = 0; j < sz2; ++j) {
            char ch = vs[i][j];
            if (ch == 'L') {
                if (vi[j] != -1) {
                    t2 = vi[j];
                    vs[t2][j] = 'W';
                    vs[t2][j + 1] = 'B';
                    vs[i][j] = 'B';
                    vs[i][j + 1] = 'W';

                    vi[j] = -1;
                } else {
                    vi[j] = i;
                }
            } else if (ch == 'U') {
                if (lastUD != -1) {
                    vs[i][lastUD] = 'W';
                    vs[i + 1][lastUD] = 'B';
                    vs[i][j] = 'B';
                    vs[i + 1][j] = 'W';
                    
                    lastUD = -1;
                } else {
                    lastUD = j;
                }
            }
        }

        if (lastUD != -1) {
            std::cout<<"-1\n";
            return;
        }
    }
    for (int i = 0; i < sz2; ++i) {
        if (vi[i] != -1) {
            std::cout<<"-1\n";
            return;
        }
    }

    for (std::string& s : vs) {
        std::cout<<s<<std::endl;
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
