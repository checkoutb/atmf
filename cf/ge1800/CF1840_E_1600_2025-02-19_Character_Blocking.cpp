
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





// 306874554 	Feb/19/2025 21:29UTC+8 	Ouha 	1840E - Character Blocking 	C++20 (GCC 13-64) 	Accepted 	187 ms 	0 KB 


// pos1 == pos2 ?

// 
void fun1()
{
    // std::string s, t;
    // std::cin>>s>>t;
    std::string arr[2];
    std::cin>>arr[0]>>arr[1];
    int tm;
    int sz1;
    std::cin>>tm;
    std::cin >> sz1;

    int cnt_diff = 0;
    for (int i = 0; i < arr[0].size(); ++i) {
        if (arr[0][i] != arr[1][i])
            ++cnt_diff;
    }
    
    // std::string q;
    std::vector<std::pair<int, int>> vp;  // <unblock time, index>
    size_t vpidx = 0;
    int in = 0;
    int a,b,c,d;
    for (size_t i = 0; i < sz1; ++i) {
        std::cin>>in;

        if (vpidx < vp.size() && vp[vpidx].first <= i) {
            int t2 = vp[vpidx].second;
            if (arr[0][t2] != arr[1][t2])
                ++cnt_diff;

            ++vpidx;
        }

        switch(in) {
        case 1:
            std::cin>>a;
            --a;
            vp.push_back(std::make_pair(i + tm, a));
            if (arr[0][a] != arr[1][a])
                --cnt_diff;
            break;
        case 2:
            std::cin>>a>>b>>c>>d;
            --b, --d;
            --a, --c;

            if (b == d) {
                if (a != c)
                    std::swap(arr[a][b], arr[c][d]);   // a==c, b==d ?
                break;
            }
            
            if (arr[0][b] != arr[1][b])
                --cnt_diff;
            if (arr[0][d] != arr[1][d])
                --cnt_diff;
            
            std::swap(arr[a][b], arr[c][d]);

            if (arr[0][b] != arr[1][b])
                ++cnt_diff;
            if (arr[0][d] != arr[1][d])
                ++cnt_diff;
            
            break;
        case 3:
            if (cnt_diff == 0)
                std::cout<<"YES\n";
            else
                std::cout<<"NO\n";
            break;
        }
    }
}


int main()
{

    std::string a = "asdfg";
    std::swap(a[2], a[2]);
    std::cout<<a<<std::endl;  // asdfg.  no problem
    

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
