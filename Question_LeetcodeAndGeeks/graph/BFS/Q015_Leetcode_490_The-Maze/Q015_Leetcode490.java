import java.util.*;
class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        if (start[0] == destination[0] && start[1] == destination[1])
            return true;
        int[][] dir = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };
        LinkedList<Integer> que = new LinkedList<>();
        int n = maze.length, m = maze[0].length, len = Math.max(n, m);
        boolean[][] vis = new boolean[n][m];

        que.addLast(start[0] * m + start[1]);
        vis[start[0]][start[1]] = true;
        while (que.size() != 0) {
            int idx = que.removeFirst(), sr = idx / m, sc = idx % m;

            for (int d = 0; d < 4; d++) {
                int fr = sr, fc = sc;
                for (int rad = 1; rad <= len; rad++) {
                    int r = sr + rad * dir[d][0];
                    int c = sc + rad * dir[d][1];

                    if (r >= 0 && c >= 0 && r < n && c < m && maze[r][c] == 0) {
                        fr = r;
                        fc = c;
                    } else
                        break;
                }

                if (vis[fr][fc])
                    continue;
                vis[fr][fc] = true;
                que.addLast(fr * m + fc);
                if (fr == destination[0] && fc == destination[1])
                    return true;
            }
        }

        return false;
    }
}