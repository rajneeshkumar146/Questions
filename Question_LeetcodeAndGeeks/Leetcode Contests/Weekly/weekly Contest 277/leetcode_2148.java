class Solution {
    public int countElements(int[] nums) {
        int minEle = nums[0], maxEle = nums[0];
        for (int ele : nums) {
            minEle = Math.min(ele, minEle);
            maxEle = Math.max(ele, maxEle);
        }

        int count = 0;
        for (int ele : nums)
            if (ele > minEle && ele < maxEle)
                count++;

        return count;
    }
}