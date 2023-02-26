
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
#include <queue>
//#include <unordered_set>
//#include <numeric>            // accumulate
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

// D D

//you can just sort inverses and do lower_bound






// 194862733 	Feb/25/2023 11:33UTC+8 	Ouha 	1792D - Fixed Prefix Permutations 	GNU C++17 	Accepted 	389 ms 	27600 KB
// 4121

struct MyTrie
{
    MyTrie* arr[11] = { nullptr };
};
//struct MyTrie;        
int depth(MyTrie* mt, vector<int>& vi);
void mktrie(MyTrie* mt, int arr[11], int idx, int);
void showTrie(MyTrie* mt);
// map, trie
void fun1()
{
    int sz1, sz2, kk;
    cin >> sz1;
    cin >> sz2;
    
    MyTrie* mt = new MyTrie();
    
    int arr[11] = { 0 };

    vector<vector<int>> vvi(sz1, vector<int>(sz2, 0));
    int t2 = 0;
    for (int i = 0; i < sz1; ++i)
    {
        for (int j = 0; j < sz2; ++j)
        {
            cin >> t2;
            vvi[i][j] = t2;
            arr[t2] = j;
        }
        mktrie(mt, arr, 1, sz2);
#ifdef __test
        //showTrie(mt);
#endif
    }
    
    for (int i = 0; i < sz1; ++i)
    {
        t2 = depth(mt, vvi[i]);
        cout << t2 << ' ';
    }
    cout << endl;
}

int depth(MyTrie* mt, vector<int>& vi)
{
    int idx = 0;
    while (idx < vi.size() && mt->arr[vi[idx] - 1] != nullptr)
    {
        mt = mt->arr[vi[idx] - 1];
        ++idx;
    }
    return idx;
}

void showTrie(MyTrie* mt)
{
    queue<MyTrie*> que;
    que.push(mt);

    while (!que.empty())
    {
        cout << "-----------------" << endl;
        MyTrie* mt2;
        for (int i = 0, mxi = que.size(); i < mxi; ++i)
        {
            mt2 = que.front();
            que.pop();
            for (int j = 0; j < 10; ++j)
            {
                if (mt2->arr[j] != nullptr)
                {
                    cout << j << ", ";
                    que.push(mt2->arr[j]);
                }
            }
        }

        cout << endl << "==============" << endl;
    }

}

void mktrie(MyTrie* mt, int arr[11], int idx, int sz2)
{
    if (idx > sz2)
        return;
    if (mt->arr[arr[idx]] == nullptr)
        mt->arr[arr[idx]] = new MyTrie();
    mktrie(mt->arr[arr[idx]], arr, idx + 1, sz2);
}




int main()
{
    int w = 1;
    cin>>w;
    
    
    
    for (int _ = w; _ < w; ++_)
    {
        
    }
    
    for (int _ = 0; _ < w; ++_)
    {        
        fun1();
        
        #ifdef __test
        cout << "   ---/////--------/////---" << endl;
        #endif
        
        //cout<<endl;
    }
    
    
    return 0;
}
