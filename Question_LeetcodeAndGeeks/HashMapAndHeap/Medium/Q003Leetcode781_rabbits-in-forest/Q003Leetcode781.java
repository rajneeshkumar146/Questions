class Q003Leetcode781 {
    public int numRabbits(int[] arr) {
        if(arr.length == 0) return 0;
        
        int n = arr.length;
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        

        int ans = 0;
        for(int ele : arr){
            map.put(ele, map.getOrDefault( ele, 0 ) + 1);
            if(map.get(ele) == 1) ans += ele + 1;
            
            if(map.get(ele) == ele + 1) map.remove(ele);
        }
        
        return ans;     
    }
}