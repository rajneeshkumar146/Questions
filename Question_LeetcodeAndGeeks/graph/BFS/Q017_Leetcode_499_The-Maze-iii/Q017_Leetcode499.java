import java.util.*;

class Solution {

    public class pair implements Comparable<pair> {
        int r, c, dis;
        String psf = "";

        pair(int r, int c, int dis, String psf) {
            this.r = r;
            this.c = c;
            this.dis = dis;
            this.psf = psf;
        }

        public int compareTo(pair o) {
            if (dis != o.dis)
                return dis - o.dis;
            else
                return psf.compareTo(o.psf);
        }
    }

    public String findShortestWay(int[][] maze, int[] start, int[] destination) {
        if (start[0] == destination[0] && start[1] == destination[1])
            return "";
        int[][] dir = { { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, 0 } };
        String[] dirS = { "d", "l", "r", "u" };

        PriorityQueue<pair> que = new PriorityQueue<>();

        int n = maze.length, m = maze[0].length, len = Math.max(n, m);
        pair[][] distance = new pair[n][m];
        for (int i = 0; i < n * m; i++)
            distance[i / m][i % m] = new pair(i / m, i % m, (int) 1e9, "");

        pair s = new pair(start[0], start[1], 0, "");
        que.add(s);
        distance[start[0]][start[1]] = s;

        while (que.size() != 0) {
            pair p = que.remove();
            int sr = p.r, sc = p.c, dis = p.dis;

            for (int d = 0; d < 4; d++) {
                int fr = sr, fc = sc, l = dis;
                while (fr >= 0 && fc >= 0 && fr < n && fc < m && maze[fr][fc] == 0
                        && (fr != destination[0] || fc != destination[1])) {
                    fr += dir[d][0];
                    fc += dir[d][1];
                    l++;
                }

                if (fr != destination[0] || fc != destination[1]) {
                    fr -= dir[d][0];
                    fc -= dir[d][1];
                    l--;
                }

                pair cp = new pair(fr, fc, l, p.psf + dirS[d]);
                if (distance[fr][fc].compareTo(cp) <= 0)
                    continue;

                distance[fr][fc] = cp;
                que.add(cp);
            }
        }

        return distance[destination[0]][destination[1]].dis != (int) 1e9 ? distance[destination[0]][destination[1]].psf
                : "impossible";
    }
}