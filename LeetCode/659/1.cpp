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
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> current, need;
        for(int num: nums)
        {
            current[num]++;
        }
        for(int num: nums)
        {
            if(current[num] == 0)
            {
                continue;
            }
            else if(need[num] != 0)
            {
                need[num]--;
                need[num + 1]++;
                current[num]--;
            }
            else if(current[num + 1] > 0 && current[num + 2] > 0)
            {
                current[num]--;
                current[num + 1]--;
                current[num + 2]--;
                need[num + 3]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}