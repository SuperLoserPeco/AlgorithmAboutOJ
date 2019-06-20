#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

typedef long long LL;
//https://blog.csdn.net/qq_23997101/article/details/73135615
class Solution {
public:
    string smallestGoodBase(string n) {
        LL num = atoll(n.c_str());
        for(int i = log(num) / log(2); i >= 1; i--)
        {
            LL a = floor(pow(num, (double)1 / i));
            if((1 - (LL)pow(a, i + 1)) == num * (1 - a))
            {
                return to_string(a);
            }
        }
        return to_string(num - 1);
    }
};

int main() {
    Solution s;
    cout << s.smallestGoodBase("15") << endl;
    // cout << log(32) / log(2) << endl;
    return 0;
}