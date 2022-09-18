
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
using ll = long long;

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

// D

//        int sum = 0;
//        for (auto c : s) {
//            cnt[c - 'a']++;
//            sum += c - 'a' + 1;
//        }
//        for (int i = 25; i >= 0; --i) {
//            while(sum > p && cnt[i]) {
//                cnt[i]--;
//                sum -= i + 1;
//            }
//        }
//        string ans;
//        for(auto c : s) {
//            if (cnt[c - 'a']) {
//                ans.push_back(c);
//                cnt[c - 'a']--;
//            }
//        }







// 172516131 	Sep/18/2022 12:20UTC+8 	Ouha 	1702D - Not a Cheap String 	GNU C++17 	Accepted 	61 ms 	500 KB

void fun1()
{
    string s;
    cin>>s;
    int p;
    cin>>p;

    int sum2 = 0;
    int arr[27] = {0};
    for (char ch : s)
    {
        sum2 += ch - 'a' + 1;
        arr[ch - 'a' + 1]++;
    }
    int idx = 26;
    int arr2[27] = {0};     // delete
    while (sum2 > p)
    {
        if (arr[idx] > 0)
        {
            arr[idx]--;
            sum2 -= idx;
            arr2[idx]++;
        }
        else
        {
            --idx;
        }
    }

    //string ans;

    for (int ch : s)
    {
        if (arr2[ch - 'a' + 1] > 0)
        {
            arr2[ch - 'a' + 1]--;
        }
        else
        {
            //ans.push_back(ch);
            cout<<(char) ch;
        }
    }
    cout<<endl;
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


        fun1();

        //cout<<endl;
    }


    return 0;
}
