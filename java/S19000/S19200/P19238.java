package S19000.S19200;

import java.util.*;
import java.util.stream.Collectors;

public class P19238 {
    public static void main(String[] args) {
        try {
            new P19238().solve();
        } catch (RuntimeException e) {
            //e.printStackTrace();
            System.out.println(-1);
        }
    }

    private void solve() throws RuntimeException {
        Scanner sc = new Scanner(System.in);
        String[] orders = sc.nextLine().split(" ");
        int n = Integer.parseInt(orders[0]);
        int m = Integer.parseInt(orders[1]);
        int fuel = Integer.parseInt(orders[2]);
        MapItem[][] map = new MapItem[n][n];
        for (int i = 0; i < n; i++) {
            String[] mapLine = sc.nextLine().split(" ");
            for (int j = 0; j < n; j++) {
                map[i][j] = new MapItem(Integer.parseInt(mapLine[j]), i, j);
            }
        }

        String[] s = sc.nextLine().split(" ");
        FuelStore fuelStore = new FuelStore(fuel);
        StartTaxi startTaxi = new StartTaxi(Integer.valueOf(s[0]) - 1, Integer.valueOf(s[1]) - 1, 0, TaxiState.NONE, 0);
        for (int i = 0; i < m; i++) {
            List<Integer> inputs = Arrays.asList(sc.nextLine().split(" ")).stream().map(Integer::parseInt).collect(Collectors.toList());
            int sy = inputs.get(0) - 1;
            int sx = inputs.get(1) - 1;
            int ey = inputs.get(2) - 1;
            int ex = inputs.get(3) - 1;
            map[sy][sx].passengerIndex = i + 1;
            map[ey][ex].addGoalIndexes(i + 1);
        }
        while (m > 0) {

            StartTaxi nextTaxi = getStartTaxi(startTaxi, map);
            //System.out.println(nextTaxi);
            if (startTaxi.nowState == nextTaxi.nowState)
                throw new RuntimeException();
            if (startTaxi.nowState == TaxiState.NONE) {
                fuelStore.rideOnFuel(nextTaxi.useFuel);
            } else {
                fuelStore.takeOffFuel(nextTaxi.useFuel);
                m--;
            }
            startTaxi = nextTaxi;
            startTaxi.useFuel = 0;
            for (int i = 0; i < map.length; i++) {
                for (int j = 0; j < map[i].length; j++) {
                    map[i][j].init();
                }
            }
        }
        System.out.println(fuelStore.nowFuel);


    }

    private StartTaxi getStartTaxi(StartTaxi startTaxi, MapItem[][] map) {
        int fuel = 0;
        Queue<MapItem> q = new ArrayDeque<>();
        q.add(map[startTaxi.y][startTaxi.x]);
        map[startTaxi.y][startTaxi.x].visitCount = 0;
        if (startTaxi.nowState == TaxiState.NONE) {
            if (map[startTaxi.y][startTaxi.x].isPassenger()) {
                int index = map[startTaxi.y][startTaxi.x].passengerIndex;
                if (map[startTaxi.y][startTaxi.x].ride()) {
                    return new StartTaxi(startTaxi.y, startTaxi.x, index, TaxiState.RIDE, fuel);
                }
            }
        }

        while (q.isEmpty() == false) {
            int len = q.size();
            List<StartTaxi> list = new ArrayList<>();
            while (len-- > 0) {
                MapItem mapItem = q.poll();
                for (int w = 0; w < 4; w++) {
                    if (mapItem.moveAvail(w, map)) {
                        MapItem moveMapItem = mapItem.move(w, map, fuel + 1);
                        if (moveMapItem.y == 2 && moveMapItem.x == 1) {
                            ;
                        }
                        if (startTaxi.nowState == TaxiState.NONE) {
                            if (moveMapItem.isPassenger()) {
                                int index = moveMapItem.passengerIndex;
                                list.add(new StartTaxi(moveMapItem.y, moveMapItem.x, index, TaxiState.RIDE, fuel + 1));
                            }
                        }
                        if (startTaxi.nowState == TaxiState.RIDE) {
                            if (moveMapItem.isGoal(startTaxi.index)) {
                                moveMapItem.takeOff(startTaxi.index);
                                return new StartTaxi(moveMapItem.y, moveMapItem.x, 0, TaxiState.NONE, fuel + 1);
                            }
                        }
                        q.add(moveMapItem);
                    }
                }
            }
            list.sort((o1, o2) -> {
                int row = o1.y - o2.y;
                if (row == 0)
                    return o1.x - o2.x;
                return row;
            });
            if (list.isEmpty() == false) {
                map[list.get(0).y][list.get(0).x].ride();
                return list.get(0);
            }
            fuel++;
        }

        return startTaxi;
    }


    private class FuelStore {
        int nowFuel;

        public FuelStore(int nowFuel) {
            this.nowFuel = nowFuel;
        }

        public void rideOnFuel(int fuel) {
            nowFuel -= fuel;
            if (fuel < 0)
                throw new RuntimeException();
        }

        public void takeOffFuel(int fuel) {
            if(nowFuel < fuel)
                throw new RuntimeException();
            nowFuel += fuel;
        }
    }

    private class StartTaxi {
        @Override
        public String toString() {
            return "StartTaxi{" +
                    "y=" + y +
                    ", x=" + x +
                    ", index=" + index +
                    ", useFuel=" + useFuel +
                    ", nowState=" + nowState +
                    '}';
        }

        int y;
        int x;
        int index;
        int useFuel;
        TaxiState nowState;

        public StartTaxi(int y, int x, int index, TaxiState nowState, int useFuel) {
            this.y = y;
            this.x = x;
            this.index = index;
            this.nowState = nowState;
            this.useFuel = useFuel;
        }
    }

    private static class MapItem {
        boolean isWall;
        int passengerIndex;
        int visitCount = -1;
        int y;
        int x;
        List<Integer> goalIndexes = new ArrayList<>();

        @Override
        public String toString() {
            return "MapItem{" +
                    "isWall=" + isWall +
                    ", passengerIndex=" + passengerIndex +
                    ", visitCount=" + visitCount +
                    ", y=" + y +
                    ", x=" + x +
                    ", goalIndexes=" + goalIndexes +
                    '}';
        }

        private final static int way[][] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        public MapItem(int n, int y, int x) {
            this.isWall = n == 1;
            this.y = y;
            this.x = x;
        }

        public boolean isPassenger() {
            return passengerIndex != 0;
        }

        public void addGoalIndexes(int index) {
            goalIndexes.add(index);
        }

        public boolean isGoal(int index) {
            return goalIndexes.isEmpty() == false && goalIndexes.contains(index);
        }

        public boolean isVisit() {
            return visitCount == -1 && isWall == false;
        }

        public boolean ride() {
            if (isPassenger() == false)
                return false;
            passengerIndex = 0;
            return true;
        }

        public boolean takeOff(int index) {
            if (goalIndexes.contains(index)) {
                for (int i = 0; i < goalIndexes.size(); i++) {
                    if (index == goalIndexes.get(i)) {
                        goalIndexes.remove(i);
                        return true;
                    }
                }
            }
            return false;
        }

        public void init() {
            visitCount = -1;
        }

        public boolean moveAvail(int w, MapItem[][] map) {
            int len = map.length;
            int wy = y + way[w][0];
            int wx = x + way[w][1];
            if (wy >= 0 && wy < len && wx >= 0 && wx < len && map[wy][wx].isVisit()) {
                return true;
            }
            return false;
        }

        public MapItem move(int w, MapItem[][] map, int count) {
            int wy = y + way[w][0];
            int wx = x + way[w][1];
            map[wy][wx].visitCount = count;
            return map[wy][wx];
        }
    }

    private enum TaxiState {
        RIDE, NONE
    }
}
