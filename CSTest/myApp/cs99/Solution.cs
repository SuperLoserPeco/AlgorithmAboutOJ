
namespace myApp.cs99
{

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    void resolve(TreeNode cur, TreeNode fa) {
        if(cur.left != null) resolve(cur.left, cur);
        if(cur.right != null) resolve(cur.right, cur);
        if(cur.left != null && cur.val < cur.left.val) {
            int temp = cur.left.val;
            cur.left.val = cur.val;
            cur.val = temp;
        }
        if(cur.right != null && cur.val > cur.right.val) {
            int temp = cur.right.val;
            cur.right.val = cur.val;
            cur.val = temp;
        }
    }

    public void RecoverTree(TreeNode root) {
        if(root != null) {
            resolve(root, null);
        }
    }
}
}