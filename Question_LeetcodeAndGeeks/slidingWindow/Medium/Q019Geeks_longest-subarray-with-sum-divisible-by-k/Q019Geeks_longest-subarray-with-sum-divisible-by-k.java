public class Q019Geeks_longest-subarray-with-sum-divisible-by-k{
	int longSubarrWthSumDivByK(int a[], int n, int k)
    {
            HashMap<Integer,Integer> map = new HashMap<>();
	        map.put(0,-1);
	        int maxLen = 0;
	        int sum = 0;
	        
	        for(int i=0;i<n;i++){
	           sum  += a[i];
	           int val = ( sum%k + k )%k;
	           
	           if(map.containsKey(val)) maxLen = Math.max(maxLen, i - map.get(val));
	           
	           if(!map.containsKey(val)) map.put(val,i);
	        }
	        
	        return maxLen;
    }
}