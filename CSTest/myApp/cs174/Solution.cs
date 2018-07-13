using System;

namespace myApp.cs174
{
    public class Solution {
        public int CalculateMinimumHP(int[][] dungeon) {
            int szX = dungeon.Length;
            int szY = dungeon[0].Length;
            int[,] dp = new int[szX,szY];
            dp[szX - 1, szY - 1] = dungeon[szX - 1][szY - 1] < 0 ? 
                        -dungeon[szX - 1][szY - 1] + 1 : 1;
            for(int i = szX - 2; i >= 0; i--)
                dp[i, szY - 1] = Math.Max(dp[i + 1, szY - 1] - dungeon[i][szY - 1], 1);
        
            for(int i = szY - 2; i >= 0; i--)
                dp[szX - 1, i] = Math.Max(dp[szX - 1, i + 1] - dungeon[szX - 1][i], 1);

            // for(int i = szX - 2; i >= 0; i--)
            // for(int j = szY - 2; j >= 0; j--) {
            //     dp[i, j] = Math.Max(1, Math.Min(dp[i + 1, j] - dungeon[i][j], dp[i, j + 1] - dungeon[i][j]));
            // }

            return dp[0, 0]; 
        }
    }
}