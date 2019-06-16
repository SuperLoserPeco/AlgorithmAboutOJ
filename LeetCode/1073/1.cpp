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
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        LL a = vec2Int(arr1);
        LL b = vec2Int(arr2);
        return int2vec(a + b);
    }


    LL vec2Int(vector<int>& vec)
    {
        LL ret = 0;
        int sz = vec.size();
        LL pwd = 1;
        for(int i = sz - 1; i >= 0; i--)
        {
            ret += (vec[i] * pwd);
            pwd *= (-2);
        }
        return ret;
    }

    vector<int> int2vec(LL val)
    {
        vector<int> vec;
        int current = 1;
        while(val > 0)
        {
            if(val % 2 != 0)
            {
                val -= current;
                vec.push_back(1);
            }
            else{
                vec.push_back(0);
            }
            val /= 2;
            current *= -1;
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {1,1,1,1,1};
    vector<int> arr2 = {1, 0, 1};
    s.addNegabinary(arr1, arr2);
    return 0;
}