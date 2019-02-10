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
const int maxn = 550;
int main() {
    int N;
    scanf("%d", &N);
    vector<string> vec;
    for(int i = 0; i < N; i++)
    {
        char str[maxn];
        scanf("%s", str);
        vec.push_back(str);
    }
    int cnt = 0;
    for(int i = 1; i < N - 1; i++)
    {
        for(int j = 1; j < N - 1; j++)
        {
            if(vec[i][j] == 'X' && 
                vec[i - 1][j - 1] == 'X' &&
                vec[i - 1][j + 1] == 'X' &&
                vec[i + 1][j - 1] == 'X' &&
                vec[i + 1][j + 1] == 'X')
                {
                    cnt++;
                }
        }
    }
    printf("%d\n", cnt);
    return 0;
}