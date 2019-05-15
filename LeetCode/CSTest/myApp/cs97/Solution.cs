namespace myApp.cs97
{
    public class Solution {
        //s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
        bool flag;
        int sz1, sz2;

        void dfs(string s1, string s2, string s3,
                    int i, int j) {
            if(i == s1.Length && j == s2.Length) flag = true;
            if(flag) return ;
            if(i < s1.Length && j < s2.Length) {
                if(s1[i] == s2[j]) {
                    if(s1[i] != s3[i + j]) return;
                    int com = 0;
                    while((i + com < s1.Length && j + com < s2.Length) &&
                                 s1[i + com] == s2[j + com]) {
                        if(s1[i + com] == s3[i + j + com]) com++;
                        else break;
                    }
                    for(int k = com; k >= 1; k--) {
                        dfs(s1, s2, s3, i + k, j);
                        dfs(s1, s2, s3, i, j + k);
                    }
                    // dfs(s1, s2, s3, i + com, j);
                    // dfs(s1, s2, s3, i, j + com);
                }
                else if(s1[i] == s3[i + j]) {
                    int com = 0;
                    while(i + com < s1.Length &&
                        s1[i + com] == s3[i + j + com]) {
                        com++;
                        // dfs(s1, s2, s3, i + com, j);
                    }
                    for(int k = com; k >= 1; k--) 
                        dfs(s1, s2, s3, i + k, j);
                }
                else if(s2[j] == s3[i + j]) {
                    int com = 0;
                    while(j + com < s2.Length &&
                        s2[j + com] == s3[i + j + com]) {
                        com++;
                        // dfs(s1, s2, s3, i, j + com);
                    }
                    for(int k = com; k >= 1; k--) 
                        dfs(s1, s2, s3, i, j + k);
                }
                else return;
            }
            else if(i == s1.Length) {
                int com = 0;
                while(j + com < s2.Length) {
                    if(s2[j + com] != s3[i + j + com]) return;
                    com++;
                }
                flag = true;
                return;
            }
            else if(j == s2.Length) {
                int com = 0;
                while(i + com < s1.Length) {
                    if(s1[i + com] != s3[i + j + com]) return;
                    com++;
                }
                flag = true;
                return;
            }
            
        }
        public bool IsInterleave(string s1, string s2, string s3) {
            flag = false;
            sz1 = s1.Length; sz2 = s2.Length;
            dfs(s1, s2, s3, 0, 0);
            return flag;
        }
    }
}