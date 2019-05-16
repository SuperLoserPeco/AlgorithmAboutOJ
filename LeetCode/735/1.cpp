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
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        int sz = asteroids.size();
        for(int i = 0; i < sz; i++)
        {
            if(stk.size() <= 0 || stk.top() < 0 || asteroids[i] > 0)
            {
                stk.push(asteroids[i]);
            }
            else{
                if(asteroids[i] < 0)
                {
                    bool isBroken = false;
                    while(stk.size() > 0 && stk.top() > 0)
                    {
                        if(stk.top() + asteroids[i] == 0)
                        {
                            stk.pop();
                            isBroken = true;
                            break;
                        }
                        else if(stk.top() + asteroids[i] > 0)
                        {
                            isBroken = true;
                            break;
                        }
                        else{
                            stk.pop();
                        }
                    }
                    if(!isBroken)
                    {
                        stk.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> ret;
        while(stk.size() > 0)
        {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main() {
    
    return 0;
}