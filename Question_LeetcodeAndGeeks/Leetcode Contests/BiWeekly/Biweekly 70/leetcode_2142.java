import java.util.*;

class Solution {
    private class pair {
        int distance = 0, price = 0, r = 0, c = 0;

        pair(int distance, int price, int r, int c) {
            this.distance = distance;
            this.price = price;
            this.r = r;
            this.c = c;
        }
    }

    public List<List<Integer>> highestRankedKItems(int[][] grid, int[] pricing, int[] start, int k) {
        List<List<Integer>> ans = new ArrayList<>();

        PriorityQueue<pair> pq = new PriorityQueue<pair>((a, b) -> {
            if (a.distance != b.distance)
                return a.distance - b.distance;
            else if (a.price != b.price)
                return a.price - b.price;
            else if (a.r != b.r)
                return a.r - b.r;
            else
                return a.c - b.c;
        });

        int[][] dir = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
        int sr = start[0], sc = start[1], lr = pricing[0], rr = pricing[1], n = grid.length, m = grid[0].length;
        boolean[][] vis = new boolean[n][m];

        pq.add(new pair(0, grid[sr][sc], sr, sc));
        vis[sr][sc] = true;

        while (pq.size() != 0) {
            pair rp = pq.remove();

            if(rp.price >= lr && rp.price <= rr && --k >= 0){
                ArrayList<Integer> sa = new ArrayList<>();
                sa.add(rp.r);
                sa.add(rp.c);
                ans.add(sa);
            }

            if(k == 0) break;

            for (int[] d : dir) {
                int r = rp.r + d[0];
                int c = rp.c + d[1];

                if (r >= 0 && c >= 0 && r < n && c < m && !vis[r][c] && grid[r][c] != 0) {
                    pq.add(new pair(rp.distance + 1, grid[r][c], r, c));
                    vis[r][c] = true;
                }
            }
        }

        return ans;
    }
}