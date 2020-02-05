public class Q011_MaximumAreaServingCake {
    public static void main(String[] args) {
        // int[] arr={ 1, 1, 1, 2, 2, 3}; //6
        // int[] arr={4, 3, 3}; // 3
        int[] arr={6,7}; //12
        solveByBinarySearch(arr, 12);
    }

    public static void solveByBinarySearch(int[] arr, int k) {
        double[] area = new double[arr.length];
        double lo = 0.0, hi = 0.0, mid = 0.0;
        for (int i = 0; i < arr.length; i++) {
            area[i] = (double) arr[i] * Math.PI * arr[i];
            hi = Math.max(hi, area[i]);
        }

        while ((hi - lo) >= 1e-5) {
            mid = lo + (hi - lo) / 2;
            if (checkIsValid(area, mid, k))
                lo = mid;
            else
                hi = mid;
        }
        System.out.printf("%.4f",mid);

    }

    public static boolean checkIsValid(double[] area, double piece, int k) {
        int count = 0;
        for (double ele : area) {
            count += ele / piece;
            if (count >= k)
                return true;
        }
        return false;

    }
}