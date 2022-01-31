import java.util.*;

class Solution {
    public List<Integer> findLonely(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int ele : nums)
            map.put(ele, map.getOrDefault(ele, 0) + 1);

        List<Integer> ans = new ArrayList<>();
        for (int ele : nums) {
            if (map.get(ele) > 1 || map.containsKey(ele - 1) || map.containsKey(ele + 1))
                continue;

            ans.add(ele);
        }

        return ans;
    }
}