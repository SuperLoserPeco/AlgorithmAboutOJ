
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
        if(fa != null) {
            if(cur == fa.left) {
                if(cur.right != null && cur.right.val > fa.val) {
                    int temp = cur.right.val;
                    cur.right.val = fa.val;
                    fa.val = temp;
                }
            }
            if(cur == fa.right) {
                if(cur.left != null && cur.left.val < fa.val) {
                    int temp = cur.left.val;
                    cur.left.val = fa.val;
                    fa.val = temp;
                }
            }
        }
    }

    void resolve2(TreeNode cur, TreeNode fa) {
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
        if(cur.left != null) resolve2(cur.left, cur);
        if(cur.right != null) resolve2(cur.right, cur);
    }

    public void RecoverTree(TreeNode root) {
        if(root != null) {
            resolve(root, null);
            resolve2(root, null);
        }
    }
}
}