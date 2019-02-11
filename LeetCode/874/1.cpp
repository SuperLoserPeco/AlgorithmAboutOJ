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

int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int currentDir = 0;
        int cmdSize = commands.size();
        int currentX = 0, currentY = 0;
        int ret = INT32_MIN;
        map<pair<int, int>, int> mp;
        for(int i = 0; i < obstacles.size(); i++)
        {
            mp[make_pair(obstacles[i][0], obstacles[i][1])] = 1;
        }
        for(int i = 0; i < cmdSize; i++)
        {
            cout << currentDir << endl;
            if(commands[i] == -2)
            {
                currentDir = (currentDir - 1 + 4) % 4;
            }
            else if(commands[i] == -1)
            {
                currentDir = (currentDir + 1 + 4) % 4;
            }
            else{
                for(int j = 1; j <= commands[i]; j++)
                {
                    if(mp[make_pair(currentX + dirX[currentDir], currentY + dirY[currentDir])] == 1)
                    // if(collided(currentX + dirX[currentDir], currentY + dirY[currentDir], obstacles))
                    {
                        break;
                    }
                    else{
                        currentX += dirX[currentDir];
                        currentY += dirY[currentDir];
                    }
                }
                ret = max(ret, currentX * currentX + currentY * currentY);
            }
        }
        return ret;
    }

    bool collided(int x, int y, vector<vector<int>>& obstacles)
    {
        int sizeOb = obstacles.size();
        for(int i = 0; i < sizeOb; i++)
        {
            if(x == obstacles[i][0] && y == obstacles[i][1])
            {
                return true;
            }
        }
        return false;
    }
};