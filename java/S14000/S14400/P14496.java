package S14000.S14400;
import java.util.*;

public class P14496 {

    private final int MAX_VALUE = 1000000;

    public static void main(String[] args) {
        new P14496().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);

        int startIndex = sc.nextInt();
        int endIndex = sc.nextInt();
        int maxCount = sc.nextInt();
        int roadCount = sc.nextInt();

        Edge edges[] = new Edge[maxCount + 1];
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new Edge(i);
        }

        for (int i = 0; i < roadCount; i++) {
            int start = sc.nextInt();
            int goal = sc.nextInt();
            edges[start].addRoad(goal, 1);
            edges[goal].addRoad(start, 1);
        }

        PriorityQueue<Edge> q = new PriorityQueue();
        edges[startIndex].len = 0;
        for (Edge edge : edges) {
            q.add(edge);
        }
        while (q.isEmpty() == false) {
            Edge edge = q.poll();
            for (Road road : edge.roads) {
                if (edge.len + road.length < edges[road.goal].len) {
                    edges[road.goal].len = edge.len + road.length;
                    q.add(edges[road.goal]);
                }
            }
        }



        if (edges[endIndex].len == MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(edges[endIndex].len);
        }
    }

    private class Edge implements Comparable<Edge> {
        int index;
        int len = MAX_VALUE;
        List<Road> roads = new ArrayList<>();

        @Override
        public int compareTo(Edge o) {
            return len - o.len;
        }

        public Edge(int index) {
            this.index = index;
        }

        public void addRoad(int index, int length) {
            roads.add(new Road(this.index, index, length));
        }
    }

    private class Road {
        int start;
        int goal;
        int length;

        public Road(int start, int goal, int length) {
            this.start = start;
            this.goal = goal;
            this.length = length;
        }
    }
}