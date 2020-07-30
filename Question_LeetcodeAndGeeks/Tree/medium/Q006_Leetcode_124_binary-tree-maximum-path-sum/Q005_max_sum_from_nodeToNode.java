public class Q004_max_sum_from_leaf_to_leaf {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public int maxPathSum(TreeNode root) {
        int[] val = new int[1];
        val[0] = Integer.MIN_VALUE;

        maxPathSum(root, val);

        return val[0];

    }

    public static int maxPathSum(TreeNode node, int[] val) {
        if (node == null)
            return (int) -1e8;

        int left = maxPathSum(node.left, val);
        int right = maxPathSum(node.right, val);

        int max = Math.max(left, right);
        val[0] = Math.max(Math.max(left + right + node.val, val[0]), Math.max(max + node.val, node.val));

        return Math.max(max + node.val, node.val);
    }

}
