class Solution {

    private int verifyArrangment(int[][] statements, int arrangment) {
        int count = 0, n = statements.length;
        for (int i = 0; i < n; i++) {
            int mask = (1 << i);
            if ((arrangment & mask) == 0)
                continue;

            count++;
            for (int j = 0; j < n; j++) {
                if (statements[i][j] == 2)
                    continue;
                if (((arrangment & (1 << j)) != 0 && statements[i][j] == 0)
                        || ((arrangment & (1 << j)) == 0 && statements[i][j] == 1))
                    return -1;
            }

        }
        return count;
    }

    public int maximumGood(int[][] statements) {
        int n = statements.length, binaryArrangments = 1 << n, ans = 0;
        for (int arrangment = 0; arrangment < binaryArrangments; arrangment++) {
            int count = verifyArrangment(statements, arrangment);
            ans = Math.max(ans, count);
        }

        return ans;
    }
}