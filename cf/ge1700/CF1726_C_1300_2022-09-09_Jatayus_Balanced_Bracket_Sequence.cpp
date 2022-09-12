
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
#include <unordered_map>
//#include <cstdlib>
//#include <cmath>

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>

using namespace std;

#define myvvi vector<vector<int>>
#define myvi vector<int>
#define __test1

// D

//int ans = n + 1;
//for (int i = 0; i < 2 * n - 1; i++) {
//    if (s[i] == '(' && s[i + 1] == ')') {
//        ans--;
//    }
//}
// 这个是 减去 核心的 ()，  我的是 减去 最外层的 ()。



// 171502545 	Sep/09/2022 20:42UTC+8 	Ouha 	1726C - Jatayu's Balanced Bracket Sequence 	GNU C++17 	Accepted 	421 ms 	500 KB
void fun1(string& s)
{
    int sz1 = s.size();
    int ans = 1;
    for (int i = 1; i < sz1; ++i)
    {
        if (s[i] == '(')
        {
            ans += (s[i - 1] == '(');
        }
    }
    cout << ans << endl;

    //int ans = 1;
    //stack<int> stk;
    //for (int i = 0; i < sz1; ++i)
    //{

    //}

}

int main()
{
    int w = 0;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {
        int sz1;
        cin >> sz1;
        string s;
        cin >> s;
        
        fun1(s);
        
        //cout<<endl;
    }
    
    
    return 0;
}
