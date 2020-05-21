public class Q007Leetcode987{
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    class Node implements Comparable<Node>{
        TreeNode node=null;
        int level=0;
        Node(TreeNode node,int level){
            this.node=node;
            this.level=level;
        }
        
        @Override
        public int compareTo(Node o){
            if( this.level==o.level ) return this.node.val-o.node.val;
            return this.level-o.level;
        }
    }
    
    public List<List<Integer>> verticalTraversal(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    if(root==null){
        return result;
    }
 
    int[] mm = new int[2];
    getMinMax(root, mm, 0);
 
    int len = mm[1]-mm[0]+1;
 
    for(int i=0; i<len; i++){
        result.add(new ArrayList<Integer>());
    }
 
    PriorityQueue<Node> q1 = new PriorityQueue<>();
     PriorityQueue<Node> q2 = new PriorityQueue<>();
 
    q1.offer(new Node(root,-mm[0]));
 
    while(!q1.isEmpty()){
        int size=q1.size();
        while(size-->0){
        Node rn = q1.poll();
 
        result.get(rn.level).add(rn.node.val);
 
        if(rn.node.left!=null)
            q2.offer(new Node(rn.node.left,rn.level-1));
        if(rn.node.right!=null)
             q2.offer(new Node(rn.node.right,rn.level+1));
        }
        
            PriorityQueue<Node> temp=q1;
             q1=q2;
             q2=temp;
    }
 
    return result;
        
    }
    
      
 
private void getMinMax(TreeNode node, int[] mm, int order){
    if(node == null){
        return;
    }
 
    mm[0] = Math.min(mm[0], order);
    mm[1] = Math.max(mm[1], order);
 
    getMinMax(node.left, mm, order-1);
    getMinMax(node.right, mm, order+1);
}

}