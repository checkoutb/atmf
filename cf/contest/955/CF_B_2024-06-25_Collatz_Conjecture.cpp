

#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define __test
#endif // ONLINE_JUDGE

using namespace std;

using ll = long long;


// (x + n) /y/y/y/y   +o /y/y  + m /y + m /y + m /y
void fun1()
{

    int x, y, k;
    std::cin>>x>>y>>k;
    int t2;

    while (k > 0) {

        #ifdef __test
        // std::cout<<x<<", "<<y<<", "<<k<<std::endl;
        #endif
        
        
        x += 1;  
        k--;
        if (x % y == 0) {   // x=1+1  y = 2  k=999999
            while (x % y == 0) {
                x /= y;
            }
        } else if (x > y) {
            t2 = y - x % y;
            if (k >= t2) {
                k -= t2;
                x = x + t2;
                while (x % y == 0) {
                    x /= y;
                }
            } else {
                x += k;
                k = 0;
                break;
            }
        }
        #ifdef __test
        // std::cout<<x<<",## "<<y<<", "<<k<<std::endl;
        #endif
        if (x < y) {
            t2 = y - x;
            if (k >= t2) {
                k -= t2;
                x = 1;
            } else {
                x += k;
                k = 0;
                break;
            }
            // x = 1, y = 3  k = 999999
            t2 = y - x;
            k = k % t2;
            x += k;
            break;
        }
    }
    
    
    
    
    std::cout<<x<<std::endl;
    
}


int main()
{
    int w = 1;
    #ifdef __test
    std::cout<<"input cnt OR REMOVE IT:";
    #endif
    std::cin>>w;
        
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
