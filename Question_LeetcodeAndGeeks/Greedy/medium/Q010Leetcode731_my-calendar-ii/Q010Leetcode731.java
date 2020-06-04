import java.util.TreeMap;
import java.util.Map;
public class Q010Leetcode731 {
    class MyCalendarTwo {

        TreeMap < Integer, Integer > map = new TreeMap < > ();
        public MyCalendarTwo() {
            map.clear();
        }

        public boolean book(int start, int end) {
            map.put(start, map.getOrDefault(start, 0) + 1);
            map.put(end, map.getOrDefault(end, 0) - 1);

            int count = 0;
            for (Map.Entry < Integer, Integer > key: map.entrySet()) {
                count += key.getValue();
                if (count > 2) {
                    map.put(start, map.getOrDefault(start, 0) - 1);
                    map.put(end, map.getOrDefault(end, 0) + 1);
                    if (map.get(start) == 0) map.remove(start);
                    if (map.get(end) == 0) map.remove(end);
                    return false;
                }
            }
            return true;
        }
    }
}