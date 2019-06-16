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
using namespace std;

typedef long long LL;


class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sz = A.size();
        int last = 0;
        int ans = 0;
        for(int i = 2; i < sz; i++)
        {
            if((A[i] - A[i - 1]) == (A[i - 1] - A[i - 2]))
            {
                if(last != 0)
                {
                    last = last + 1;
                }
                else{
                    last = 1;
                }
                ans += last;
            }
            else{
                last = 0;
            }
        }
        return ans;
    }
};

int main() {
    
    return 0;
}