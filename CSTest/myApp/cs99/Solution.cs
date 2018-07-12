namespace myApp.cs99
{

public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

public class Solution {
    TreeNode rt;
    void resolve(TreeNode cur, TreeNode fa) {
        if(cur.left != null && cur.val < cur.left.val) {
            TreeNode curleft = cur.left;
            TreeNode curright = cur.right;
            cur.left = curleft.left;
            cur.right = curleft.right;
            curleft.left = cur;
            curleft.right = curright;
            if(fa == null) rt = curleft;
            else{
                if(fa.left == cur) fa.left = curleft;
                else if(fa.right == cur) fa.right = curleft;
            }
            cur = curleft;
        }
        if(cur.right != null && cur.val > cur.right.val) {
            TreeNode curleft = cur.left;
            TreeNode curright = cur.right;
            cur.left = curright.left;
            cur.right = curright.right;
            curright.left = curleft;
            curright.right = cur;
            if(fa == null) rt = curright;
            else {
                if(fa.left == cur) fa.left = curright;
                else if(fa.right == cur) fa.right = curright;
            }
            cur = curright;
        }
        if(cur.left != null) resolve(cur.left, cur);
        if(cur.right != null) resolve(cur.right, cur);
    }

    public void RecoverTree(TreeNode root) {
        rt = root;
        if(root != null) {
            resolve(root, null);
        }
        root = rt;
    }
}
}