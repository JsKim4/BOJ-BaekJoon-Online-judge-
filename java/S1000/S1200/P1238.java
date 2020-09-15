package S1000.S1200;
import java.util.*;

public class P1238 {

    private final int MAX_VALUE = 1000000000;

    public static void main(String[] args) {
        new P1238().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);


        int maxCount = sc.nextInt();
        int roadCount = sc.nextInt();
        int endIndex = sc.nextInt();

        Edge edges[] = new Edge[maxCount + 1];
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new Edge(i);
        }

        for (int i = 0; i < roadCount; i++) {
            int start = sc.nextInt();
            int goal = sc.nextInt();
            int length = sc.nextInt();
            edges[start].addRoad(goal, length);
        }
        int max = 0;
        for (int i = 1; i < maxCount + 1; i++) {
            int go = getCount(i, endIndex, edges.clone());
            int back = getCount(endIndex, i, edges.clone());
            if(go+back > max)
                max = go+back;
        }
        System.out.println(max);
    }

    private int getCount(int startIndex, int endIndex, Edge[] edges) {
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

        int result = edges[endIndex].len;
        for (Edge edge : edges) {
            edge.init();
        }
        return result;
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

        public void init() {
            len = MAX_VALUE;
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
