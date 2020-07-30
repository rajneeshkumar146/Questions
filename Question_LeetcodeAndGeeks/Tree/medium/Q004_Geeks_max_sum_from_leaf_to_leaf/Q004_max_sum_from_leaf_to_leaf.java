public class Q004_max_sum_from_leaf_to_leaf {

    public static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            data = x;
        }
    }

    public int maxPathSum(TreeNode root) {
        int[] val = new int[1];
        val[0] = Integer.MIN_VALUE;

        maxPathSumUtil(root, val);

        return val[0];

    }

    public static int maxPathSumUtil(TreeNode root, int[] val) {

        if (root == null)
            return 0;

        if ((root.left == null) && (root.right == null))
            return root.data;

        int ls = maxPathSumUtil(root.left, val);
        int rs = maxPathSumUtil(root.right, val);

        if ((root.left != null) && (root.right != null)) {

            val[0] = Math.max(val[0], ls + rs + root.data);
            return (Math.max(ls, rs) + root.data);
        }

        return ((root.left == null) ? rs + root.data : ls + root.data);
    }

}
