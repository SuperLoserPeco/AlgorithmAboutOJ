using System;

namespace myApp.cs135
{
    //这种多判断的程序 可以考虑优化下代码
    //wrong
    public class Solution {
        int ans = 0;
        int[] temp;
        Boolean[] vis;
        int[] val;
        int ret;
        void dfs(int i) {
            if(vis[i]) return;
            if(i >= temp.Length || i < 0) return;
            if(i == 0) {
                if(temp[i] <= temp[i + 1]) {
                    val[i] = 1;
                    vis[i] = true;
                    dfs(i + 1);
                }
                else {
                    if(vis[i + 1]) {
                        val[i] = val[i + 1] + 1;
                        vis[i] = true;
                    }
                }
            }
            else if(i == temp.Length - 1) {
                if(temp[i - 1] >= temp[i]) {
                    val[i] = 1;
                    vis[i] = true;
                    dfs(i - 1);
                }
                else {
                    if(vis[i - 1]) {
                        val[i] = val[i - 1] + 1;
                        vis[i] = true;
                    }
                }
            }
            else {
                if(temp[i - 1] < temp[i] && temp[i] <= temp[i + 1]) {
                    if(vis[i - 1]) {
                        val[i] = val[i - 1] + 1;
                        vis[i] = true;
                        dfs(i + 1);
                    }
                }
                else if(temp[i - 1] < temp[i] && temp[i] > temp[i + 1]) {
                    if(vis[i - 1] && vis[i + 1]) {
                        vis[i] = true;
                        val[i] = Math.Max(val[i - 1], val[i + 1]) + 1;
                    }
                }
                else if(temp[i - 1] >= temp[i] && temp[i] > temp[i + 1]) {
                    if(vis[i + 1]) {
                        val[i] = val[i + 1] + 1;
                        vis[i] = true;
                        dfs(i - 1);
                    }
                }
                else if(temp[i - 1] >= temp[i] && temp[i] <= temp[i + 1]) {
                    val[i] = 1;
                    vis[i] = true;
                    dfs(i + 1); dfs(i - 1);
                }
            }
        }
        public int Candy(int[] ratings) {
            if(ratings.Length == 0) return 0;
            if(ratings.Length == 1) return 1;
            temp = new int[ratings.Length];
            vis = new Boolean[ratings.Length];
            val = new int[ratings.Length];


            for(int i = 0; i < ratings.Length; i++)
                temp[i] = ratings[i];
            // Array.Sort(temp);
            for(int i = 0; i < ratings.Length; i++) 
                dfs(i);
            for(int i = 0; i < ratings.Length; i++) {
                // Console.WriteLine("ret = " + val[i]);
                ret += val[i];
            }
            return ret;
        }
    }
}