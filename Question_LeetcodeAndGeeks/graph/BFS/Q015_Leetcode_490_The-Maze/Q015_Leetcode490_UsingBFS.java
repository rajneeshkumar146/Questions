import java.util.*;
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        int n = maze.length, m = maze[0].length, sr = start[0], sc = start[1], er = destination[0], ec = destination[1];
        LinkedList<Integer> que = new LinkedList<>();
        boolean[][] vis = new boolean[n][m];
        int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        que.add(sr * m + sc);
        vis[sr][sc] = true;

        int len = Math.max(n, m);
        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                int idx = que.removeFirst(), i = idx / m, j = idx % m;
                for (int[] d : dir) {
                    int r = i, c = j;
                    while (r >= 0 && c >= 0 && r < n && c < m && maze[r][c] == 0) {
                        r += d[0];
                        c += d[1];
                    }

                    r -= d[0];
                    c -= d[1];

                    if (vis[r][c])
                        continue;

                    vis[r][c] = true;
                    que.addLast(r * m + c);
                    if (r == er && c == ec)
                        return true;
                }

            }
        }

        return false;
    }
}