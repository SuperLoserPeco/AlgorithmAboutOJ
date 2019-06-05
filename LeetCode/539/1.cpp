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
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec;
        int sz = timePoints.size();
        for(int i = 0; i < sz; i++)
        {
            int hour = 0;
            int min = 0;
            int szS = timePoints[i].length();
            bool isHour = true;
            for(int j = 0; j < szS; j++)
            {
                if(timePoints[i][j] == ':')
                {
                    isHour = false;
                    continue;
                }
                if(isHour)
                {
                    hour *= 10;
                    hour += timePoints[i][j] - '0';
                }
                else{
                    min *= 10;
                    min += timePoints[i][j] - '0';
                }
            }
            vec.push_back(hour * 60 + min);
        }
        sort(vec.begin(), vec.end());
        int minRange = 24 * 60;
        int szVec = vec.size();
        for(int i = 1; i < szVec; i++)
        {
            if(vec[i] - vec[i - 1] < minRange)
            {
                minRange = vec[i] - vec[i - 1];
            }
        }
        minRange = min(minRange, vec[0] + 24 * 60 - vec[szVec - 1]);
        return minRange;
    }
};

int main() {
    
    return 0;
}