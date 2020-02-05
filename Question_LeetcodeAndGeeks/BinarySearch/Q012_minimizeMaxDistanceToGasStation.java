public class Q012_minimizeMaxDistanceToGasStation{

    public static void main(String[] args) {
        int[] arr={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //9
        // int[] arr={4, 3, 3}; // 3
        // int[] arr={6,7}; //12
        solveByBinarySearch(arr, 9);
    }

    public static void solveByBinarySearch(int[] arr, int k) {
        double lo = 0.0, hi = 1e8, mid = 0.0;

        while ((hi - lo) > 1e-5) {
            mid = lo + (hi - lo) / 2.0;
            if (checkIsValid(arr, mid, k))
                lo = mid;
            else
                hi = mid;
        }
        System.out.printf("%.4f",mid);

    }

    public static boolean checkIsValid(int[] arr, double noOfPumps, int k) {
        int count = 0;
        for (int i=1;i<arr.length;i++) {
            count +=  (int)((arr[i]-arr[i-1])/ noOfPumps);
            if (count> k)
                return true;
        }
        return false;

    }
}