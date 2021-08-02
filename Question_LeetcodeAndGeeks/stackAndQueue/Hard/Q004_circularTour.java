public class Q004_circularTour {
    public static void main(String[] args) {

    }

    int tour(int petrol[], int distance[]) {
        int n = petrol.length;
        int spare = 0;
        int idx = 0;
        int stPoint = 0;
        while (idx < n) {
            spare += petrol[idx] - distance[idx];
            if (spare < 0) {
                stPoint = idx + 1;
                spare = 0;
            }
            idx++;
        }

        if (idx == n)
            return -1;
        for (int i = 0; i <= idx; i++) {
            spare += petrol[i] - distance[i];
            if (spare < 0) {
                return -1;
            }

        }

        return stPoint;

    }
}