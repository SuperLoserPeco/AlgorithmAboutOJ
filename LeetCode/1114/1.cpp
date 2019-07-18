#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

class Foo {
public:
    vector<function<void()>> vec;
    int cnt;
    Foo() {
        cnt = 0;
        vec.resize(3);
    }

    void first(function<void()> printFirst) {
        vec[0] = printFirst;
        // printFirst() outputs "first". Do not change or remove this line.
        printTest();
    }

    void second(function<void()> printSecond) {
        vec[1] = printSecond;
        
        // printSecond() outputs "second". Do not change or remove this line.
        printTest();
    }

    void third(function<void()> printThird) {
        vec[2] = printThird;
        // printThird() outputs "third". Do not change or remove this line.
        printTest();
    }

    void printTest()
    {
        cnt++;
        if(cnt == 3)
        {
            for(int i = 0; i < 3; i++)
            {
                vec[i]();
            }
            cnt = 0;
        }
    }
};

int main() {
    
    return 0;
}