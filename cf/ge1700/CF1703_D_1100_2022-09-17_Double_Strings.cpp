
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
#include <unordered_set>
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

// Trie
//template <int maxN>
//struct trie
//{
//    struct node
//    {
//        node *next[26];
//        int count;
//    } nodes[maxN + 1], *root, *start;
//    void clear() { start = nodes, get(root = 0); }
//    node *get(node *&n)
//    {
//        if (n)
//            return n;
//        memset(start->next, 0, sizeof(start->next));
//        return start->count = 0, n = start++;
//    }
//    void add(char *it, char *last)
//    {
//        node *current = root;
//        for (; it != last; it++)
//            current = get(current->next[*it - 'a']);
//        current->count = 1;
//    }
//    int query(char *it, char *last)
//    {
//        node *current = root;
//        for (; it != last; it++)
//        {
//            current = current->next[*it - 'a'];
//            if (!current)
//                return 0;
//        }
//        return current->count;
//    }
//    int solve(char *start, char *last)
//    {
//        node *current = root;
//        for (auto it = start;;)
//        {
//            current = current->next[*it - 'a'];
//            it++;
//            if (it == last)
//                return 0;
//            if (current->count)
//                if (query(it, last))
//                    return 1;
//        }
//    }
//};




// 172447068 	Sep/17/2022 19:11UTC+8 	Ouha 	1703D - Double Strings 	GNU C++17 	Accepted 	233 ms 	6100 KB

// 26: aaa -> 0   aa -> 0
void fun1()
{
    int sz1;
    cin>>sz1;

    vector<string> vs(sz1);

    for (int i = 0; i < sz1; ++i)
        cin>>vs[i];

    unordered_set<ll> set2;
    vector<ll> vll(sz1);
    ll t2 = 0LL;
    for (int i = 0; i < sz1; ++i)
    {
        t2 = 0LL;

        for (int j = 0; j < vs[i].size(); ++j)
        {
            t2 = t2 * 27 + (vs[i][j] - 'a' + 1);
        }
        set2.insert(t2);
        vll[i] = t2;
    }
    ll t3 = 0LL;
    ll arr[8] = {1LL};
    for (int i = 1; i < 8; ++i)
    {
        arr[i] = arr[i - 1] * 27LL;
    }
    int ans = 0;
    for (int i = 0; i < sz1; ++i)
    {
        t2 = vs[i][0] - 'a' + 1;
        ans = 0;
        for (int j = 1; j < vs[i].size(); ++j)
        {
            if (set2.find(t2) != set2.end())
            {
                t3 = vll[i] % arr[vs[i].size() - j];
                if (set2.find(t3) != set2.end())
                {
                    ans = 1;
                    break;
                }
            }
            t2 = t2 * 27 + vs[i][j] - 'a' + 1;
        }
        cout<<ans;
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
