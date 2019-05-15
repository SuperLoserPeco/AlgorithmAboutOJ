#define INF 0xFFFF

class Solution {
public:
    int ans[50][50][50];
    int prex[50];
    int mm[50][50][50];

    int dp(int l, int r, int m, int k) {
        int i, j, a, b, c;

        if((r - l + 1 - m) % (k - 1)) {
            return ans[l][r][m];
        }
        // 剪枝，否则会超时
        if(mm[l][r][m]) {
            return ans[l][r][m];
        }
        if(l == r) {
            if(m == 1) {
                ans[l][r][m] = 0;
                return ans[l][r][m];
            }
            else {
            	// 返回的是无穷大，因为1堆石头不可能分成多堆
                return ans[l][r][m];
            }
        }
        if(m == 1) {
        	// 分成k堆
            ans[l][r][m] = dp(l, r, k, k) + prex[r+1] - prex[l];
            mm[l][r][m] = 1;
            return ans[l][r][m];
        }

        for(i=l; i<r; i++) {
			//左数第一堆的左边界是l，右边界可能是l到r-1
            ans[l][r][m] = min(ans[l][r][m], dp(l, i, 1, k) + dp(i+1, r, m-1, k));
            mm[l][r][m] = 1;
        }
        return ans[l][r][m];
    }

    int mergeStones(vector<int>& stones, int K) {
        int i, j, a, len;


        len = stones.size();
        for(i=0; i<len; i++) {
            for(j=0; j<len; j++) {
                for(a=1; a<=K; a++) {
                    ans[i][j][a] = INF;
                    mm[i][j][a] = 0;
                }
            }
        }

        prex[0] = 0;
        prex[1] = stones[0];
        for(i = 2; i<=len; i++) {
            prex[i] = prex[i-1] + stones[i-1];
        }


        int ret = dp(0, len-1, 1, K);
        if(ret < INF) {
            return ret;
        }
        return -1;

    }
};
