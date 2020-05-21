import java.util.TreeMap;
public class Q001Leetcode180{

    public boolean isNStraightHand(int[] hand, int W) {
         TreeMap<Integer,Integer> tree=new TreeMAp<>();
         for(int& ele: hand) tree.put(val,tree.getOrDefault(val,0)+1);

         while(tree.size()>0){
            int val=tree.fisrtKey();
            for(int count=1;count<=W;count++){
                if(tree.count(val)){
                    tree.put(val,tree.getOrDefault(val,0)-1);
                    if(tree.get(val)==0)tree.remove(val);
                    val++;
                }else return false;
            }
        }
      return true;
         
    }
