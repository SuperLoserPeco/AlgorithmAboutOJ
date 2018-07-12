using System;
using System.Collections.Generic;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    List<int> ret;
    void dfs(TreeNode tn, int dep) {
        if(dep >= ret.Count) ret.Add(tn.val);
        else ret[dep] = tn.val;
        if(tn.left != null) dfs(tn.left, dep + 1);
        if(tn.right != null) dfs(tn.right, dep + 1);
    }
    public IList<int> RightSideView(TreeNode root) {
        ret = new List<int>();
        if(root != null) dfs(root, 0);
        return ret;
    }
}