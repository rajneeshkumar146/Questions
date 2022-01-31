import java.util.PriorityQueue;

class Solution {
    public class pair implements Comparable<pair> {
        int r = 0, c = 0, diff = 0, maxDiff = 0;

        pair(int r, int c, int diff, int maxDiff) {
            this.r = r;
            this.c = c;
            this.diff = diff;
            this.maxDiff = maxDiff;
        }

        @Override
        public int compareTo(pair o) {
            return this.diff - o.diff;
        }
    }

    public int minimumEffortPath(int[][] heights) {
        int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        PriorityQueue<pair> pq = new PriorityQueue<>();

        int n = heights.length, m = heights[0].length;
        boolean[][] vis = new boolean[n][m];
        pair[][] dis = new pair[n][m];
        for (int i = 0; i < n * m; i++)
            dis[i / m][i % m] = new pair(i / m, i % m, (int) 1e9, 0);

        pq.add(new pair(0, 0, 0, 0));
        dis[0][0].diff = 0;
        while (pq.size() != 0) {
            pair p = pq.remove();
            if (vis[p.r][p.c])
                continue;

            vis[p.r][p.c] = true;
            for (int[] d : dir) {
                int r = p.r + d[0];
                int c = p.c + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c]) {
                    int val = Math.abs(heights[r][c] - heights[p.r][p.c]);
                    int maxDiff = Math.max(p.maxDiff, val);
                    if (val < dis[r][c].diff) {
                        pair cp = new pair(r, c, val, maxDiff);
                        dis[r][c] = cp;
                        pq.add(cp);
                    }
                }
            }
        }

        return dis[n - 1][m - 1].maxDiff;
    }
}