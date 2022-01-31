import java.util.*;

class Solution {
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {

        if (start[0] == destination[0] && start[1] == destination[1])
            return true;


            
        int[][] dir = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };

        class pair {
            int r, c, dis;

            pair(int r, int c, int dis) {
                this.r = r;
                this.c = c;
                this.dis = dis;
            }
        }

        PriorityQueue<pair> que = new PriorityQueue<>((a, b) -> {
            return a.dis - b.dis;
        });
        int n = maze.length, m = maze[0].length, len = Math.max(n, m);
        boolean[][] vis = new boolean[n][m];
        int[][] distance = new int[n][m];
        for (int[] d : distance)
            Arrays.fill(d, (int) 1e9);

        que.add(new pair(start[0], start[1], 0));
        distance[start[0]][start[1]] = 0;

        while (que.size() != 0) {
            pair p = que.remove();
            int sr = p.r, sc = p.c, dis = p.dis;

            for (int d = 0; d < 4; d++) {
                int fr = sr, fc = sc, l = dis;
                while (fr >= 0 && fc >= 0 && fr < n && fc < m && maze[fr][fc] == 0) {
                    fr += dir[d][0];
                    fc += dir[d][1];
                    l++;
                }
                fr -= dir[d][0];
                fc -= dir[d][1];
                l--;

                if (l >= distance[fr][fc])
                    continue;

                distance[fr][fc] = l;
                que.add(new pair(fr, fc, l));
                if (fr == destination[0] && fc == destination[1])
                    return true;
            }
        }

        return false;
    }
}