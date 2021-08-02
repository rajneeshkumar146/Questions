public class Q022Geeks_longest-sub-array-with-sum-k{
    public static void main (String[] args)
	{
	    Scanner scn = new Scanner(System.in);
	    int t = scn.nextInt();
	    while(t-->0){
	        int n = scn.nextInt();
	        int k = scn.nextInt();
	        
	        HashMap<Integer,Integer> map = new HashMap<>();
	        map.put(0,-1);
	        int maxLen = 0;
	        int sum = 0;
	        
	        for(int i=0;i<n;i++){
	           sum  += scn.nextInt();
	           int val = ( sum - k );
	           
	           if(map.containsKey(val)) maxLen = Math.max(maxLen, i - map.get(val));
	           
	           if(!map.containsKey(sum)) map.put(sum,i);
	        }
	        
	        System.out.println(maxLen);
	    }
	}
}