package S1000.S1400;

import com.sun.javafx.geom.Edge;

import java.util.*;
import java.util.stream.Collectors;

public class P1486 {
    public static void main(String[] args) {
        new P1486().solve();
    }

    private final int MAX_VALUE = 1000000000;

    private final int way[][] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    public boolean avail(int y, int x, int row, int column) {
        if (y >= 0 && y < row && x >= 0 && x < column)
            return true;
        return false;
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);
        List<Integer> orders = Arrays.asList(sc.nextLine().split(" ")).stream().map(Integer::parseInt).collect(Collectors.toList());

        int row = orders.get(0);
        int column = orders.get(1);
        int maxDifferent = orders.get(2);
        int remainTime = orders.get(3);

        Edge edges[][] = new Edge[row][column];
        for (int i = 0; i < row; i++) {
            String[] inputs = sc.nextLine().split("");
            for (int j = 0; j < column; j++) {
                char input = inputs[j].charAt(0);
                int high = input >= 'A' && input <= 'Z' ? input - 'A' : input - 'a' + 26;
                edges[i][j] = new Edge(high, i, j);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                for (int w = 0; w < 4; w++) {
                    int wy = way[w][0] + i;
                    int wx = way[w][1] + j;
                    if (avail(wy, wx, row, column) && edges[i][j].addAvail(edges[wy][wx], maxDifferent)) {
                        edges[i][j].addRoad(edges[wy][wx]);
                    }
                }
            }
        }


        int max = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                if (max < edges[i][j].high) {
                    int go = getCount(edges, 0, 0, i, j);
                    int back = getCount(edges, i, j, 0, 0);
                    if (go + back <= remainTime)
                        max = edges[i][j].high;
                }
            }
        }
        System.out.println(max);

    }

    private int getCount(Edge[][] edges, int startY, int startX, int endY, int endX) {
        PriorityQueue<Edge> q = new PriorityQueue();
        edges[startY][startX].len = 0;
        for (Edge edgesRow[] : edges) {
            for (Edge edge : edgesRow) {
                q.add(edge);
            }
        }
        while (q.isEmpty() == false) {
            Edge edge = q.poll();
            for (Road road : edge.roads) {
                if (edge.len + road.length < edges[road.goal.y][road.goal.x].len) {
                    edges[road.goal.y][road.goal.x].len = edge.len + road.length;
                    q.add(edges[road.goal.y][road.goal.x]);
                }
            }
        }
        int result = edges[endY][endX].len;
        for (Edge[] edge : edges) {
            for (Edge edge1 : edge) {
                edge1.init();
            }
        }
        return result;
    }


    private class Edge implements Comparable<Edge> {
        Pair location;
        int high;
        int len = MAX_VALUE;
        List<Road> roads = new ArrayList<>();

        @Override
        public int compareTo(Edge o) {
            return len - o.len;
        }

        public Edge(int high, int y, int x) {
            this.high = high;
            location = new Pair(y, x);
        }

        public boolean addAvail(Edge edge, int maxDifferent) {
            if (Math.abs(edge.high - high) > maxDifferent)
                return false;
            return true;
        }

        public void addRoad(Edge edge) {
            roads.add(new Road(this.location, edge.location, calculatorLength(edge)));
        }

        private int calculatorLength(Edge edge) {
            if (high >= edge.high)
                return 1;
            return (edge.high - high) * (edge.high - high);
        }

        public void init() {
            len = MAX_VALUE;
        }
    }

    private class Road {
        Pair start;
        Pair goal;
        int length;

        public Road(Pair start, Pair goal, int length) {
            this.start = start;
            this.goal = goal;
            this.length = length;
        }
    }

    private class Pair {
        int y;
        int x;

        public Pair(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
