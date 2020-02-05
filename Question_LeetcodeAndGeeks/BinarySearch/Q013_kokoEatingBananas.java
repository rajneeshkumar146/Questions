public class Q013_kokoEatingBananas{
    public static void main(String[] args) {
        int[] arr={ 30,11,23,4,20}; //6
        // int[] arr={4, 3, 3}; // 3
        // int[] arr={6,7}; //12
        solveByBinarySearch(arr, 6);
    }

    public static void solveByBinarySearch(int[] arr, int k) {
        int lo = 1, hi = 0, mid = 0;
        for(int ele : arr) hi=Math.max(hi,ele);

        while (lo<hi) {
            mid = lo + (hi - lo) / 2;
            if (checkIsValid(arr, mid, k))
                lo = mid+1;
            else
                hi = mid;
        }
        System.out.println(lo);

    }

    public static boolean checkIsValid(int[] arr, int noOfBananas, int k) {
        int count = 0;
        for (int ele:arr) {
            count+=(int)Math.ceil(ele/(double)noOfBananas );
        }
        return count>k;

    }


}