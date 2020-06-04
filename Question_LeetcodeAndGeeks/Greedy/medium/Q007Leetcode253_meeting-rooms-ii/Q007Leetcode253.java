import java.util.TreeMap;
public class Q007Leetcode253{
   
    public int minMeetingRooms(int[][] intervals) {
        if (intervals.length <= 1)
           return intervals.length;
        
        int n=intervals.length;
        Map<Integer,Integer> map=new TreeMap<>();
        for (int[] t : intervals) {
            map.put(t[0], map.getOrDefault(t[0], 0) + 1);
            map.put(t[1], map.getOrDefault(t[1], 0) - 1);
        }

        int ans=0,rooms=0;
        for(Map.Entry<Integer,Integer> ele: map.entrySet()){
            rooms += ele.getValue();
            ans = Math.max(ans, rooms);
        }
        return ans;
    }
}