using System;

namespace myApp.cs173
{
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}


public class BSTIterator {
    TreeNode cur;

    int now;
    TreeNode[] f;

    int dep;

    void dfs(TreeNode tn, int dep) {
        this.dep = Math.Max(this.dep, dep);
        if(tn.left != null) dfs(tn.left, dep + 1);
        if(tn.right != null) dfs(tn.right, dep + 1);
    }
    public BSTIterator(TreeNode root) {
        cur = root;
        if(cur != null) {
            dfs(root, 1);
            f = new TreeNode[dep + 1];
            f[0] = null;
            now = 0;
            getLeft();
        }
    }

    /** @return whether we have a next smallest number */
    public bool HasNext() {
        return cur != null;
    }

    /** @return the next smallest number */
    public int Next() {
        int ret = cur.val;
        if(cur.right != null) {
            f[++now] = cur;
            cur = cur.right;
            getLeft();
        }
        else {
            toLeftParents();
            if(f[now] == null) cur = null;
            else {
                cur = f[now];
                now--;
            }
        }
        return ret;
    }

    public void toLeftParents() {
        while(f[now] != null && f[now].right == cur) {
            cur = f[now];
            now--;
        }
    }

    void getLeft() {
        while(cur.left != null) {
            f[++now] = cur;
            cur = cur.left;
        }
    }
}
}