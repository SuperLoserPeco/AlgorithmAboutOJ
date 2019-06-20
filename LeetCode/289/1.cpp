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
    void gameOfLife(vector<vector<int>>& board) {
        int szX = board.size();
        if(szX == 0)
        {
            return;
        }
        int szY = board[0].size();
        for(int i = 0; i < szX; i++)
        {
            for(int j = 0; j < szY; j++)
            {
                int active = 0;
                for(int k = 0; k < 3; k++)
                {
                    for(int l = 0; l < 3; l++)
                    {
                        int nextX = i + k - 1;
                        int nextY = j + l - 1;
                        if((!(nextX == i && nextY == j)))
                        {
                            if(0 <= nextX && nextX < szX &&
                                0 <= nextY && nextY < szY)
                                {
                                    active += (board[nextX][nextY] & 1);
                                }
                        }
                    }
                }
                if(board[i][j] & 1)
                {
                    if(active < 2)
                    {
                    }
                    else if(active <= 3)
                    {
                        board[i][j] += 2;
                    }
                    else{

                    }
                }
                else{
                    if(active == 3)
                    {
                        board[i][j] += 2;
                    }
                }
            }
        }
        for(int i = 0; i < szX; i++)
        {
            for(int j = 0; j < szY; j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};

int main() {
    
    return 0;
}