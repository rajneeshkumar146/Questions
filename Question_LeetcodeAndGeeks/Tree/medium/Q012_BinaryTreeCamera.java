public class Q012_BinaryTreeCamera {

    public static class TreeNode {
        int data;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            data = x;
        }
    }

    int camera = 0;

    public int minCameraCover(TreeNode root) {
        if (minCameraCover_(root) == -1)
            camera++;
        return camera;
    }

    // at any instance either children need camera so provide them,
    // or one of them is camera so you are covered. and in rest condition you will
    // be handel by your parent.

    // -1 means i need a camera.
    // 0 i am covered by a camera .
    // 1 i am a camera.

    public int minCameraCover_(TreeNode root) {
        if (root == null)
            return 0;

        int ls = minCameraCover_(root.left); // left subtree
        int rs = minCameraCover_(root.right); // right subtree

        if (root.left == null && root.right == null)
            return -1;

        if (ls == -1 || rs == -1) {
            camera++;
            return 1;
        } else if (ls == 1 || rs == 1) {
            return 0;
        }

        return -1;

    }

}
