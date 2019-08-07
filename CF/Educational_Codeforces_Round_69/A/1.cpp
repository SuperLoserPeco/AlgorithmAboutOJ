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


int main() {
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<int> num(N);
        for(int i = 0; i < N; i++)
        {
            cin >> num[i];
        }
        sort(num.begin(), num.end());
        int res = N - 2;
        int h = min(num[N - 1], num[N - 2]) - 1;
        int ans = min(res, h);
        cout << ans << endl;
    }
    return 0;
}