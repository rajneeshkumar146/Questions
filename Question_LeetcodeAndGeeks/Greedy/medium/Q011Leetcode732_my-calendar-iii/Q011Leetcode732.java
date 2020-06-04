import java.util.TreeMap;
import java.util.Map;

class MyCalendarThree {
    TreeMap < Integer, Integer > map = new TreeMap < > ();
    public MyCalendarThree() {
         map.clear();
    }
    
    public int book(int start, int end) {
         map.put(start, map.getOrDefault(start, 0) + 1);
            map.put(end, map.getOrDefault(end, 0) - 1);

            int count = 0,res=0;
            for (Map.Entry < Integer, Integer > key: map.entrySet()) {
                count += key.getValue();
                res=Math.max(res,count);
            }
            return res;
    }
}