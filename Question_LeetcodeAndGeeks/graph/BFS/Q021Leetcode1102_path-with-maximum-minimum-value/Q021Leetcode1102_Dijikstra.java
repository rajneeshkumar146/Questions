import java.util.PriorityQueue;

class Solution {
    public int maximumMinimumPath(int[][] grid) {
        int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        int n = grid.length, m = grid[0].length;
        boolean[][] vis = new boolean[n][m];

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return grid[b / m][b % m] - grid[a / m][a % m];
        });

        pq.add(0);
        int minVal = grid[0][0];
        while (pq.size() != 0) {
            int p = pq.remove();
            int i = p / m, j = p % m;
            if (vis[i][j])
                continue;
            minVal = Math.min(minVal, grid[i][j]);
            if (i == n - 1 && j == m - 1)
                break;
            vis[i][j] = true;
            for (int[] d : dir) {
                int r = i + d[0];
                int c = j + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c]) {
                    pq.add(r * m + c);

                }
            }
        }

        return minVal;
    }
}