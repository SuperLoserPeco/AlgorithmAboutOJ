#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;

//
// 随时插入数据
// 查找
// 大于该数据的最小值 
// 小于该数据的最大值
// https://blog.csdn.net/fuxuemingzhu/article/details/86439744

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int count = A.size();
        vector<int> nextJiStep(count);
        vector<int> nextOuStep(count);
        for(int i = 0; i < count; i++)
        {
            nextJiStep[i] = nextOuStep[i] = -1;
        }
        int maxValuePos = count - 1;
        int minValuePos = count - 1;
        nextOuStep[maxValuePos] = maxValuePos;
        nextJiStep[minValuePos] = minValuePos;
        map<int, int> m;
        m[A[count - 1]] = count - 1;
        int ans = 1;
        for(int i = count - 2; i >= 0; i--)
        {
            auto ji = m.lower_bound(A[i]);
            auto ou = m.upper_bound(A[i]);
            if(ji != m.end())
            {
                nextJiStep[i] = nextOuStep[ji->second];
            }
            if(ou != m.begin())
            {
                nextOuStep[i] = nextJiStep[(--ou)->second];
            }
            
            if(nextJiStep[i] == count - 1)
            {
                ans++;
            }
            cout << nextJiStep[i] << endl;
            cout << nextOuStep[i] << endl;

            m[A[i]] = i;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> params = {10,13,12,14,15};
    int ans = s.oddEvenJumps(params);
    cout << ans << endl;
    return 0;
}