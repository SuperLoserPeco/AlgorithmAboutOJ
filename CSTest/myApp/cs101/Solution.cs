namespace myApp.cs101
{
    public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}
    public class Solution
    {
        bool flag;

        void dfs(TreeNode t1, TreeNode t2) {
            if(!flag) return;
            if(t1 == null && t2 == null) return;
            if(t1 == null && t2 != null) {
                flag = false;
                return;
            }
            if(t1 != null && t2 == null) {
                flag = false;
                return;
            }
            else{
                if(t1.val != t2.val) {
                    flag = false;
                    return;
                }
                dfs(t1.left, t2.right);
                dfs(t1.right, t2.left);
            }
        }
        public bool IsSymmetric(TreeNode root) {
            flag = true;
            dfs(root, root);
            return flag;
        }
    }
}