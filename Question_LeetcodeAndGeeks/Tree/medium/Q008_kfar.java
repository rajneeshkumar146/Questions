import java.util.*;
public class Q008_kfar {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    List<Integer> ans = new ArrayList<>();

    public List<Integer> distanceK(TreeNode node, TreeNode target, int k) {

        kfar_02(node, k, target.val);
        return ans;

    }

    public int kfar_02(TreeNode node, int k, int data) {
        if (node == null)
            return -1;
        if (node.val == data) {
            kaway(node, k, null);
            return 1;
        }

        int ld = kfar_02(node.left, k, data);
        if (ld != -1) {
            if (ld == k) {
                ans.add(node.val);
            } else
                kaway(node, k - ld, node.left);

            return ld + 1;
        }

        int rd = kfar_02(node.right, k, data);
        if (rd != -1) {
            if (rd == k) {
                ans.add(node.val);
            } else
                kaway(node, k - rd, node.right);
            return rd + 1;
        }

        return -1;

    }

    public void kaway(TreeNode node, int k, TreeNode rnode) { // rnode = return node
        if (node == null)
            return;
        if (node == rnode) {
            return;
        }
        if (k == 0) {
            ans.add(node.val);
            return;
        }

        kaway(node.left, k - 1, rnode);
        kaway(node.right, k - 1, rnode);
    }

}
