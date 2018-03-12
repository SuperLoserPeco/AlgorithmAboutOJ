#include <vector>
#include <list>
#include <queue>
#include <map>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
// #include <tr1/unordered_set>
// #include <tr1/unordered_map>

using namespace std;
// using namespace tr1;

const int maxn = 5005;
int n, h[maxn];
long long dp[maxn][maxn];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &h[i]);
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++)
			dp[i][j] = 1e18;
	h[0] = 0;
	dp[0][0] = 0;

	//dp[i][j]：涂了i个栅栏 且离第i个最近的全是横着涂完的木板为j 涂满所需要的次数
    for(int i = 0; i < n; i++)
    	for(int j = 0; j <= i; j++) {
    		//第i+1个栏杆竖着涂
    		if(h[i + 1] >= h[j] && dp[i + 1][j] > dp[i][j] + 1)
    			dp[i + 1][j] = dp[i][j] + 1;
    		//第i+1个栏杆横着涂
    		if(h[i + 1] >= h[j] && dp[i + 1][i + 1] > dp[i][j] + h[i + 1] - h[j])
    			dp[i + 1][i + 1] = dp[i][j] + h[i + 1] - h[j];
    		//第i+1个栏杆横着涂
    		if(h[i + 1] < h[j] && dp[i + 1][i + 1] > dp[i][j])
    			dp[i + 1][i + 1] = dp[i][j];
    	}

    long long ans = dp[n][0];
    for(int i = 1; i <= n; i++) 
    	ans = min(ans, dp[n][i]);

   	cout << ans << endl;
   	return 0;
}