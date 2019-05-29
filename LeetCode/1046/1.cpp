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
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int,vector<int>,less<int> > q;
        int sz = stones.size();
        for(int i = 0; i < sz; i++)
        {
            q.push(stones[i]);
        }
        while(q.size() > 1)
        {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(a != b)
            {
                int c = abs(a - b);
                q.push(c);
            }
        }
        if(q.size() == 1)
        {
            return q.top();
        }
        else{
            return 0;
        }
    }
};

int main() {
    
    return 0;
}