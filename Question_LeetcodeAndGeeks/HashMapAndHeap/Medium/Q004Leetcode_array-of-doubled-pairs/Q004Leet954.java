class Solution {
    public boolean canReorderDoubled(int[] arr) {
        if(arr.length == 0) return true;
        
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int ele : arr){
            map.put(ele,map.getOrDefault(ele,0) + 1);
            
        }
        
        Integer[] A = new Integer[arr.length];
        for(int i = 0;i<arr.length;i++) A[i] = arr[i];
        
        Arrays.sort(A, (a,b)->{
            return Math.abs(a) - Math.abs(b);
        });
        
        for(int ele : A){
            if(map.get(ele) == 0) continue;
            
            if(map.getOrDefault(2 * ele,0) <= 0) return false;
            
            map.put(ele, map.get(ele) - 1);
            map.put(2 * ele, map.get( 2 * ele) - 1);
            
           
        }
        return  true;       
    }
}