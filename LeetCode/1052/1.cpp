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
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int sz = customers.size();
        int* sumA = new int[sz];
        int* sumB = new int[sz];
        sumA[0] = customers[0];
        sumB[0] = customers[0] * (1 - grumpy[0]);
        for(int i = 1; i < sz; i++)
        {
            sumA[i] = customers[i] + sumA[i - 1];
            sumB[i] = customers[i] * (1 - grumpy[i]) + sumB[i - 1];
        }
        int ans = sumB[sz - 1];
        for(int i = X - 1; i < sz; i++)
        {
            int current = sumB[sz - 1];
            current = current 
                + (i >= X ? (sumA[i] - sumA[i - X]) : sumA[i])
                - (i >= X ? (sumB[i] - sumB[i - X]) : sumB[i]);
            ans = max(ans, current);
        }

        return ans;
    }
};

int main() {
    
    return 0;
}