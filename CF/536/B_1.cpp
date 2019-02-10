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

const int maxn = 1e5 + 100;
int a[maxn];
int c[maxn];
int n, m;

int findMinValueIdx();

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
    }
    for(int i = 0; i < m; i++)
    {
        int t, d;
        scanf("%d%d", &t, &d);
        long long currentAns = 0;
        int currentCostNum = min(a[t - 1], d);
        a[t - 1] -= currentCostNum;
        currentAns += ((long long)currentCostNum * (long long)c[t - 1]);
        d -= currentCostNum;
        while(d > 0)
        {
            int minValueIdx = findMinValueIdx();
            if(minValueIdx == -1)
            {
                break;
            }
            int currentCostNum = min(a[minValueIdx], d);
            a[minValueIdx] -= currentCostNum;
            currentAns += ((long long)currentCostNum * (long long)c[minValueIdx]);
            d -= currentCostNum;
        }
        if(d > 0)
        {
            printf("%d\n", 0);
        }
        else{
            printf("%I64d\n", currentAns);
        }
    }
    return 0;
}

int findMinValueIdx()
{
    int minValueIdx = -1;
    int minValue = -1;

    for(int i = 0; i < n; i++)
    {
        if(minValueIdx == -1 && a[i] > 0)
        {
            minValueIdx = i;
            minValue = c[i];
        }
        else if(a[i] > 0 && c[i] < minValue)
        {
            minValueIdx = i;
            minValue = c[i];
        }
    }
    return minValueIdx;
}