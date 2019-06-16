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
using namespace std;

typedef long long LL;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        for(int i = 1; i < n - k; i++)
        {
            ret.push_back(i);
        }
        for(int i = n - k; i <= n; i++)
        {
            if((i - (n - k)) % 2)
            {
                ret.push_back(n - ((i - (n - k)) / 2));
            }
            else{
                ret.push_back(i - ((i - (n - k)) / 2));
            }
        }
        return ret;
    }
};

int main() {
    
    return 0;
}