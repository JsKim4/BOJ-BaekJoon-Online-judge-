package S19000.S19200;

import java.util.*;
import java.util.stream.Collectors;

public class P19238 {
    public static void main(String[] args) {
        new P19238().solve();
    }

    private void solve() {
        Scanner sc = new Scanner(System.in);
        String[] orders = sc.nextLine().split(" ");
        int n = Integer.parseInt(orders[0]);
        int m = Integer.parseInt(orders[1]);
        int fuel = Integer.parseInt(orders[2]);
        boolean indexArray[] = new boolean[m];
        MapItem[][] map = new MapItem[n][n];
        for (int i = 0; i < n; i++) {
            String[] mapLine = sc.nextLine().split(" ");
            for (int j = 0; j < n; j++) {
                map[i][j] = new MapItem(Integer.parseInt(mapLine[j]));
            }
        }

        String[] s = sc.nextLine().split(" ");
        int sy = Integer.parseInt(s[0]) - 1;
        int sx = Integer.parseInt(s[1]) - 1;
        for (int i = 0; i < m; i++) {
            List<Integer> list = Arrays.asList(sc.nextLine().split(" ")).stream().map(Integer::parseInt).collect(Collectors.toList());
            map[list.get(0) - 1][list.get(1) - 1].addItem(i, ItemType.START);
            map[list.get(2) - 1][list.get(3) - 1].addItem(i, ItemType.END);
        }

        ItemType nowType = ItemType.END;

        int index = -1;
        while (true) {
            int now = 0;
            Queue<Taxi> taxiQueue = new ArrayDeque<>();
            Item nowItem = new Item(index, nowType);
            taxiQueue.add(new Taxi(sy, sx, nowType));
            boolean success = false;
            if (map[sy][sx].visit(now, index, nowType)) {
                index = map[sy][sx].getAndPollNowVisitIndex();
                nowType = ItemType.START;
                continue;
            }
            while (taxiQueue.isEmpty() == false) {
                List<Taxi> availStatTaxi = new ArrayList<>();
                int len = taxiQueue.size();
                while (len-- > 0) {
                    Taxi taxi = taxiQueue.poll();
                    List<Taxi> taxis = taxi.availMoveTaxi(map, n);
                    for (Taxi taxiItem : taxis) {
                        if (map[taxiItem.getY()][taxiItem.getX()].visit(now, nowItem.index, nowItem.itemType)) {
                            availStatTaxi.add(taxiItem);
                        }
                        taxiQueue.add(taxiItem);
                    }
                }
                now++;
                if (availStatTaxi.isEmpty() == false) {

                    fuel -= now;
                    if (fuel < 0) {
                        System.out.println(-1);
                        return;
                    }

                    availStatTaxi.sort(Taxi::compareTo);
                    sy = availStatTaxi.get(0).location.first;
                    sx = availStatTaxi.get(0).location.second;

                    if (nowType == ItemType.START) {
                        indexArray[index] = true;
                        nowType = ItemType.END;
                        fuel += now * 2;
                        index = -1;
                        map[sy][sx].removeIndex(index);
                    } else{
                        index = map[sy][sx].getAndPollNowVisitIndex();
                        nowType = ItemType.START;
                    }
                    success = true;
                    break;
                }
            }
            if (success == false) {
                break;
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j].init();
                }
            }

        }
        for (boolean isTrue : indexArray) {
            if (isTrue == false) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(fuel);
    }

    class Taxi implements Comparable<Taxi> {
        Pair location;
        ItemType nowType;

        private final int[][] way = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        public Taxi(int y, int x, ItemType nowType) {
            location = new Pair(y, x);
            this.nowType = nowType;
        }

        @Override
        public int compareTo(Taxi o) {
            int first = location.first - o.location.first;
            if (first != 0)
                return first;

            return location.second - o.location.second;
        }

        public List<Taxi> availMoveTaxi(MapItem[][] map, int n) {
            List<Taxi> taxis = new ArrayList<>();
            for (int[] w : way) {
                int wy = location.first + w[0];
                int wx = location.second + w[1];

                if (moveAvail(wy, wx, n) && map[wy][wx].isAvail()) {
                    taxis.add(new Taxi(wy, wx, nowType));
                }
            }
            return taxis;
        }

        private boolean moveAvail(int y, int x, int n) {
            if (y >= 0 && y < n && x >= 0 && x < n)
                return true;
            return false;
        }

        public int getX() {
            return location.second;
        }

        public int getY() {
            return location.first;
        }

    }

    class Pair {
        int first;
        int second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }


    }

    class MapItem {
        int now;
        boolean isWall;
        List<Item> items;

        public void init() {
            int n = 0;
        }

        public void removeIndex(int index) {
            Item item = items.stream().filter(i -> i.itemType == ItemType.END && i.index == index).findFirst().get();
            items.remove(item);
        }

        public int getAndPollNowVisitIndex() {
            Item item = items.stream().filter(i -> i.itemType == ItemType.START).findFirst().get();
            items.remove(item);
            return item.index;
        }

        public boolean visit(int now, int index, ItemType itemType) {
            this.now = now;
            if (itemType == ItemType.END) {
                boolean b = items.stream().anyMatch(i -> i.itemType == ItemType.START);
                return b;
            } else {
                boolean b = items.stream().anyMatch(i -> i.index == index && i.itemType == ItemType.END);
                return b;
            }
        }

        public MapItem(int n) {
            now = -1;
            if (n == 1) {
                isWall = true;
            } else {
                isWall = false;
            }
            items = new ArrayList<>();
        }

        public boolean isAvail() {
            if (now == -1 && isWall == false) {
                return true;
            }
            return false;

        }

        public void addItem(int index, ItemType itemType) {
            items.add(new Item(index, itemType));
        }
    }

    class Item {
        int index;
        ItemType itemType;

        public Item(int index, ItemType itemType) {
            this.index = index;
            this.itemType = itemType;
        }
    }

    private enum ItemType {
        START, END
    }
}
