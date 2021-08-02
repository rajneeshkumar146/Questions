public class Q023Leetcode560{
    
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        if(n == 0 ) return 0;
        
        
        HashMap<Integer,Integer> map = new HashMap<>();
        map.put(0,1);
        int count = 0;
        int sum = 0;
        for(int ele: nums){
            sum += ele;
            if(map.containsKey(sum-k)) count += map.get(sum-k);
            
            map.put(sum,map.getOrDefault(sum,0)+1);
        }
        
        return count; 
    }
}