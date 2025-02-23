
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
//#include <iomanip>    // std::cout<<std::fixed<<std::setprecision(10)<<ans<<std::endl;
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




// 307412258 	Feb/23/2025 21:03UTC+8 	Ouha 	1837D - Bracket Coloring 	C++20 (GCC 13-64) 	Accepted 	77 ms 	100 KB




// 似乎最多2种颜色？ 一种涂正序的，一种涂反序的
// 优先 湮灭
// ...不需要stk，直接一个int 就可以了。。 因为不需要检查 stk.top() 。。
void fun1()
{
    int sz1, sz2, kk;
    std::cin >> sz1;
    
    std::string str;
    std::cin>>str;

    std::stack<char> stk1;  // ->
    std::stack<char> stk2;  // <-
    std::vector<int> vi(sz1);
    for (int i = 0; i < sz1; ++i) {
        if (str[i] == '(') {
            if (!stk2.empty()) {
                stk2.pop();
                vi[i] = 2;
            } else {
                stk1.push('(');
                vi[i] = 1;
            }
        } else {
            if (!stk1.empty()) {
                stk1.pop();
                vi[i] = 1;
            } else {
                stk2.push(')');
                vi[i] = 2;
            }
        }
    }
    
    if (!stk1.empty() || !stk2.empty()) {
        std::cout<<-1<<std::endl;
        return;
    }

    int t2 = 0;
    for (int i : vi) {
        t2 |= (1 << (i - 1));
        if (t2 == 3) {
            break;
        }
    }

    if (t2 != 3 && vi[0] == 2) {
        for (int& i : vi) {
            i = 1;
        }
    }

    std::cout<<(t2 == 3 ? 2 : 1)<<std::endl;
    
    // bool has2 = false;
    // for (int i : vi) {
    //     if (i == 2) {
    //         has2 = true;
    //         break;
    //     }
    // }
    // std::cout<<(has2 ? 2 : 1)<<std::endl;
    
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
    std::cin>>w;  // <------   remove or not
    
    
    
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
