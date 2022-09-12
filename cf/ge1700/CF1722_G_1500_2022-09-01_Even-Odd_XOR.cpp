

//#include <time.h>
//#include <windows.h>
//#include <sstream>
//#include <climits>
//#include <fstream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>
#include <cmath>

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


// D

//#include<bits/stdc++.h>
//using namespace std;
//int tt;
//int main()
//{
//    cin >> tt;
//    while (tt--) {
//        int n, x = 0;
//        cin >> n;
//        for (int i = 1; i <= n - 3; i++)
//        {
//            x ^= i;
//            cout << i << ' ';
//        }
//        //		奇：a^30^x
//        //		偶：b^30
//        cout << (1 << 29) << ' ' << (1 << 30) << ' ' << ((1 << 30) ^ (1 << 29) ^ x) << endl;
//    }
//    return 0;
//}
// 最后3位。


//#include <bits/stdc++.h>
//using namespace std;
//int main() {
//    int tt;
//    cin >> tt;
//    while (tt--) {
//        int n, s = 0;
//        cin >> n;
//        for (int i = 3; i <= n; ++i)
//            s ^= i;
//        cout << (1 << 25) + s << ' ' << (1 << 25) << ' ';
//        for (int i = 3; i <= n; ++i)
//            cout << i << ' ';
//        cout << '\n';
//    }
//}
// s 会不会是 0 ？  为什么不会？  奇数个数 肯定不会0，因为 2^0 这位 必然1的。
// 1^2^3 = 0, 但是后续 是不是 不可能出现这种了？

// 并不区分 奇数 偶数 下标， 只是 最后 几个元素的 时候 特殊计算下。
// 
// 奇数下标^ == 偶数下标^  ==>  所有^ == 0 .  但 不是必要条件啊。  为什么可以不区分呢？
// 



// 170486995 	Sep/01/2022 21:37UTC+8 	Ouha 	1722G - Even-Odd XOR 	GNU C++17 	Accepted 	46 ms 	800 KB 

// distinct  奇数下标的^  == 偶数下标的^
// 1 2 3 4 5 6 7 ...
// 1^3^5^7 == 0..
// 2^4^6  == 0...
// 3^5 = 6
// 5^7
// 
void fun1(int sz1)
{
    vector<int> vi(sz1);
    int n1 = 0;
    int n2 = 0;
    int mx = 1 << 18;
    int mn = 1;
    for (int i = 0; i < sz1 - 1; ++i)
    {
        if (i % 2)
        {
            vi[i] = mn++;
            n1 ^= vi[i];
        }
        else
        {
            vi[i] = mx--;
            n2 ^= vi[i];
        }
    }

    int t2 = n1 ^ n2 + (1 << 20);
    vi[sz1 - 2] += (1 << 20);
    vi[sz1 - 1] = t2;

    for (int i = 0; i < sz1; ++i)
        cout << vi[i] << " ";

}

int main()
{
    int w = 0;
    cin >> w;
    
    vector<int> vi(w);
    
    for (int e = 0; e < w; ++e)
    {
        cin >> vi[e];
    }

    //ifstream f;
    //f.open("../test.txt.ignore", ios::in);
    //if (!f.is_open())
    //{
    //    cout << " cannot find file ... " << endl;
    //    return -1;
    //}
    //int w = 0;
    //f >> w;
    //cout << w << endl;
    //vector<int> vi[w];
    //
    //for (int e = 0; e < w; ++e)
    //{
    //    f >> vi[e];
    //}

    for (int e = 0; e < w; ++e)
    {
        //cout << vi[e] << endl;
        fun1(vi[e]);
        cout << endl;
        //cout << endl << " =========== " << endl;
    }


    return 0;
}