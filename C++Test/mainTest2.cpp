// 最舒适的c++开发环境
// 
//
//

//无法定位程序输入点__gxx_personality_v0的一个解决方法
//https://blog.csdn.net/zyli14/article/details/51302153

#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unistd.h>
using namespace std;

typedef long long LL;

class A{
    public:
    A()
    {
        cout << "AAA" << endl;
    }
    virtual void DDD() {
        cout << "eee" << endl;
    }
    private:

};

class B : A {
    public:
    B()
    {
        cout << "BBB" << endl;
    }
    void DDD()
    {
        cout << "wocao" << endl;
    }
};

class C : B{
    public:
    C()
    {
        cout << "CCC" << endl;
    }
    void DDD()
    {
        cout <<"wocao" << endl;
    }
};

//Ctrl+Shift+B
int main() {
    while(1){
        int a;
        cin >> a;
    }
    vector<vector<vector<int>>> 
        dp(3, vector<vector<int>>(2, vector<int>(4)));
    dp.resize(2, vector<vector<int>>(2, vector<int>(4)));
    int a = 2;
    int b = 3;
    int c = a + b;
    B ccc;
    ccc.DDD();
    C ddd;
    ddd.DDD();
    vector<int> eeee;
    cout << "size " << dp.size() << " " << dp[0].size() << " " << dp[0][0].size() << endl;
    
    string s1 = string("string1");
    string s2 = string("string2");
    const char* p1 = s1.substr(1).data();
    const char* p2 = s2.substr(1).data();
    cout << p1 << p2 << endl;

    return 0;
}