import java.util.HashMap;
import java.util.Map;

public class Q003_path_sum_III {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    public static int pathSum(TreeNode root, int sum) {
        Map<Integer, Integer> map = new HashMap<>(); // prefix sum
        map.put(0, 1);
        return pathDown(root, 0, sum, map);
    }

    private static int pathDown(TreeNode root, int sum, int target, Map<Integer, Integer> map) {

        if (root == null)
            return 0;
        sum += root.val;

        int result = map.getOrDefault(sum - target, 0);

        map.put(sum, map.getOrDefault(sum, 0) + 1);
        result += pathDown(root.left, sum, target, map);
        result += pathDown(root.right, sum, target, map);

        if (map.get(sum) != 1)
            map.put(sum, map.get(sum) - 1);
        else
            map.remove(sum);
        return result;
    }

}
