public class Q007_recoverBST {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    static TreeNode x, y, prev;

    public void recoverTree(TreeNode root) {

        // first refer notes and do how to find two swapped elements in array.
        recoverTree_(root);

        int temp = x.val;
        x.val = y.val;
        y.val = temp;

    }

    public void recoverTree_(TreeNode root) {
        if (root == null)
            return;

        recoverTree_(root.left);

        if (prev != null && root.val < prev.val) {
            y = root;
            if (x == null)
                x = prev;
            else
                return;
        }
        prev = root;

        recoverTree_(root.right);
    }

}
