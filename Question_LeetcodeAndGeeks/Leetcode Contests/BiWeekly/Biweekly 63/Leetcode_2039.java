import java.util.*;

public class Leetcode_2039 {
    public int networkBecomesIdle(int[][] edges, int[] patience) {
        int n = patience.length;
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++)
            graph[i] = new ArrayList<>();

        for (int[] e : edges) {
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }

        int[] dist = new int[n];
        Arrays.fill(dist, -1);
        LinkedList<Integer> que = new LinkedList<>();

        que.addLast(0);
        dist[0] = 0;

        int level = 1;
        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                int vtx = que.removeFirst();

                for (int nbr : graph[vtx]) {
                    if (dist[nbr] == -1) {
                        dist[nbr] = 2 * level;
                        que.addLast(nbr);
                    }
                }
            }
            level++;
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            int d = dist[i];
            int val = d + (d - d % patience[i]); // first Signal arival Time - last signal arival Time.
            if (d % patience[i] == 0)
                val -= patience[i];

            ans = Math.max(ans, val + 1);
        }

        return ans;
    }

}