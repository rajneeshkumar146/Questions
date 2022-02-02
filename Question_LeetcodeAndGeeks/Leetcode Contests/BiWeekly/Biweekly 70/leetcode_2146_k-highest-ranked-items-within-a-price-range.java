import java.util.*;

class Solution {
    private class pair implements Comparable<pair> {
        int distance = 0, price = 0, row = 0, col = 0;

        pair(int distance, int price, int row, int col) {
            this.distance = distance;
            this.price = price;
            this.row = row;
            this.col = col;
        }

        public int compareTo(pair o) {
            if (this.distance != o.distance)
                return this.distance - o.distance;
            else if (this.price != o.price)
                return this.price - o.price;
            else if (this.row != o.row)
                return this.row - o.row;
            else
                return this.col - o.col;
        }
    }

    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing, int[] start, int k) {
        int n = grid.length, m = grid[0].length, sr = start[0], sc = start[1], lr = pricing[0], rr = pricing[1];
        List<List<Integer>> ans = new ArrayList<>();

        PriorityQueue<pair> pq = new PriorityQueue<pair>();
        boolean[][] vis = new boolean[n][m];
        int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

        pq.add(new pair(0, grid[sr][sc], sr, sc));
        vis[sr][sc] = true;

        while (pq.size() != 0) {
            pair rp = pq.remove();

            if (rp.price >= lr && rp.price <= rr && --k >= 0) {
                ArrayList<Integer> sa = new ArrayList<>();
                sa.add(rp.row);
                sa.add(rp.col);

                ans.add(sa);
            }

            if (k == 0)
                break;

            for (int[] d : dir) {
                int r = rp.row + d[0];
                int c = rp.col + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m && grid[r][c] > 0 && !vis[r][c]) {
                    pq.add(new pair(rp.distance + 1, grid[r][c], r, c));
                    vis[r][c] = true;
                }
            }
        }

        return ans;
    }
}