#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int inputStrLength = 30;
const int maxn = 4e5 + 10;

int factorial[9]={1,1,2,6,24,120,720,5040,40320};
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char d[5] = "udlr";

struct State
{
    int value[3][3];
    int x, y;
    int g, h;
    int cantorExpansionValue;
    bool operator < (const State& rhs) const {
        return h + g > rhs.h + rhs.g;
    }
};

struct Path
{
    int pre;
    char ch;
} path[maxn];
int vis[maxn];

int getHValue(State state) {
    int ans = 0;
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++) 
        if(state.value[i][j]) {
            ans += (abs(i - (state.value[i][j] - 1) / 3) + 
                    abs(j - (state.value[i][j] - 1) % 3));
        }
    return ans;
}

int getCantorExpansion(State state) {
    int a[9], k = 0, ret = 0;
    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
        a[k++] = state.value[i][j];
    
    for(int i = 0; i < 9; i++) {
        k = 0;
        for(int j = 0; j < i; j++)
            if(a[j] > a[i]) k++;
        ret += (factorial[i] * k);
    }
    return ret;
}

void printAns(int cantorExpansionValue) {
    if(path[cantorExpansionValue].pre == -1) return;
    printAns(path[cantorExpansionValue].pre);
    printf("%c", path[cantorExpansionValue].ch);
}

void Astar(State start) {
    memset(vis, 0, sizeof(vis));
    
    State endState;
    for(int i = 0; i < 9; i++) {
        endState.value[i / 3][i % 3] = (i + 1) % 9;
    }
    int endCantorExpansion = getCantorExpansion(endState);

    start.cantorExpansionValue = getCantorExpansion(start);
    start.g = 0;
    start.h = getHValue(start);
    vis[start.cantorExpansionValue] = 1;
    path[start.cantorExpansionValue].pre = -1;
    if(start.cantorExpansionValue == endCantorExpansion) {
        printf("\n");
        return ;
    }


    priority_queue<State> Q;
    Q.push(start);
    while(!Q.empty()) {
        State now = Q.top();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int x = now.x + dir[i][0];
            int y = now.y + dir[i][1];

            if(x < 0 || x >= 3 || y < 0 || y >= 3) continue;

            State nextState = now;

            swap(nextState.value[now.x][now.y], nextState.value[x][y]);

            int nextCantorExpansionValue = getCantorExpansion(nextState);
            if(vis[nextCantorExpansionValue]) continue;
            vis[nextCantorExpansionValue] = 1;

            nextState.cantorExpansionValue = nextCantorExpansionValue;
            nextState.x = x;
            nextState.y = y;
            nextState.g++;
            nextState.h = getHValue(nextState);

            path[nextCantorExpansionValue].pre = now.cantorExpansionValue;
            path[nextCantorExpansionValue].ch = d[i];

            if(nextCantorExpansionValue == endCantorExpansion) {
                printAns(nextCantorExpansionValue);
                printf("\n");
                return;
            }
            Q.push(nextState);
        }
    }
}

int main() {
    char input[inputStrLength];
    while( gets(input) ) {
        State start;
        int n = strlen(input);
        int j = 0;
        for(int i = 0; i < n; i++) {
            if(input[i] == ' ') continue;
            if(input[i] == 'x') {
                start.value[j / 3][j % 3] = 0;
                start.x = j / 3;
                start.y = j % 3;
            }
            else {
                start.value[j / 3][j % 3] = input[i] - '0';
            }
            j++;
        }
        
        //这边涉及到一个逆序数问题，如果开始状态的逆序数为奇数，那么这个状态只能到达逆序数为奇数的转态，同理偶数逆序数的状态也只能到达逆序数为偶数的状态
        int k = 0;
        for(int i = 0; i < 9; i++) {
            if(start.value[i / 3][i % 3] == 0) continue;

            for(j = 0; j < i; j++) {
                if(start.value[j / 3][j % 3] == 0) continue;
                if(start.value[j / 3][j % 3] > 
                    start.value[i / 3][i % 3]) k++;
            }
        }

        if(k & 1) printf("unsolvable\n");
        else Astar(start);
    }
    return 0;
}