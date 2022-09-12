
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

//#include <stack>
//#include <bitset>
//#include <set>
//#include <list>
//#include <deque>
//#include <map>
//#include <queue>
//#include <unordered_set>
//#include <numeric>
//#include <unordered_map>
//#include <string.h>       // memset

using namespace std;

//#define myvvi vector<vector<int>>
//#define myvi vector<int>
using myvvi = vector<vector<int>>;
using myvi = vector<int>;

#define __test1

// D

//		for(int i=1;i<=n;i++)
//		{
//			a[i]=(x+i-1)/i*i;
//			if(a[i]>y)s="NO";
//		}





// 加上 	ios::sync_with_stdio(0); 	cin.tie(0); 后
// 171663150 	Sep/11/2022 07:49UTC+8 	Ouha 	1708B - Difference of GCDs 	GNU C++17 	Accepted 	78 ms 	400 KB
//
// 171663009 	Sep/11/2022 07:43UTC+8 	Ouha 	1708B - Difference of GCDs 	GNU C++17 	Accepted 	124 ms 	400 KB

// n-size, l min, r max
// 1 2 3 4 5
// 1 2 3 4 5 6 7 8 9
// 就是 gcd 按照 1 2 3 4 5 ， 然后 算 可能的值。
void fun1()
{
    int sz1, mn, mx;
    cin>>sz1>>mn>>mx;

    myvi vi(sz1);
    int t2, t3;
    for (int i = 0; i < sz1; ++i)
    {
        t2 = i + 1;
        t3 = mn / t2 * t2;
        if (t3 < mn)
        {
            t3 += t2;

            if (t3 > mx)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        vi[i] = t3;
    }

    cout<<"YES"<<endl;
    for (int i : vi)
    {
        cout<<i<<' ';
    }
    cout<<endl;

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int w = 0;
    cin>>w;


    for (int _ = w; _ < w; ++_)
    {

    }

    for (int _ = 0; _ < w; ++_)
    {


        fun1();

        //cout<<endl;
    }


    return 0;
}
