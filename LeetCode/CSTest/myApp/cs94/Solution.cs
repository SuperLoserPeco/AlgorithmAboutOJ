using System.Collections.Generic;

namespace myApp.cs94
{

 public class TreeNode {
     public int val;
     public TreeNode left;
     public TreeNode right;
     public TreeNode(int x) { val = x; }
 }
 

    public class Solution {
        List<int> ret;
        void dfs(TreeNode root) {
            if(root.left != null) dfs(root.left);
            ret.Add(root.val);
            if(root.right != null) dfs(root.right);
        }
        public IList<int> InorderTraversal(TreeNode root) {
            ret = new List<int>();
            if(root != null) {
                dfs(root);
            }
            return ret;
        }
    }
}