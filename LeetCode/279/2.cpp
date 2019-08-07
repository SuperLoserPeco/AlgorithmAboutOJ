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

class Solution {
    struct Node{
        int val;
        int step;
    };
public:
    int numSquares(int n) {
        queue<Node> Q;
        vector<bool> vis(n + 1, false);
        Q.push({n, 0});
        while(!Q.empty())
        {
            Node current = Q.front();
            Q.pop();
            int curNum = current.val;
            int curStep = current.step;
            for(int i = 1; i <= n; i++)
            {
                int nextNum = curNum - i * i;
                if(nextNum < 0)
                {
                    break;
                }
                if(nextNum == 0)
                {
                    return curStep + 1;
                }
                if(!vis[nextNum])
                {
                    Q.push({nextNum, curStep + 1});
                    vis[nextNum] = true;
                }
            }
        }
        return -1;
    }
};

int main() {
    
    return 0;
}