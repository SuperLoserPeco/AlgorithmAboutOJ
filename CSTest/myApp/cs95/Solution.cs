using System.Collections.Generic;

//not finished
namespace myApp.cs95
{

  public class TreeNode {
      public int val;
      public TreeNode left;
      public TreeNode right;
      public TreeNode(int x) { val = x; }
  }

public class Solution {
    List<TreeNode> ret;
    int[] dp;
    public IList<TreeNode> GenerateTrees(int n) {
        ret = new List<TreeNode>();
        
        int ans = 0;
        for(int i = 2; i < n; i++) {
            ans = ans + dp[i - 1] * dp[n - i];
        }

        return ret;
    }
}
}