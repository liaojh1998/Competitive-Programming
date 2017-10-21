import java.util.*;

public class ImperfectGps {
    public static void main(String... args) {
        Scanner scan = new Scanner(System.in);
        String[] first2 = scan.nextLine().split(" ");
        int n = Integer.parseInt(first2[0]);
        int delt = Integer.parseInt(first2[1]);
        Map<Integer, Double> xMap = new HashMap<>();
        Map<Integer, Double> yMap = new HashMap<>();
        double lastX = 0.0;
        double lastY = 0.0;
        String[] trip = scan.nextLine().split(" ");
        lastX = Double.parseDouble(trip[0]);
        lastY = Double.parseDouble(trip[1]);
        xMap.put(0, lastX);
        yMap.put(0, lastY);
        double realDistance = 0.0;
        int maxTime = 0;
        List<Integer> timeList = new ArrayList<>();
        timeList.add(0);
        for(int i = 1; i < n; i++) {
            String[] triple = scan.nextLine().split(" ");
            double curX = Double.parseDouble(triple[0]);
            double curY = Double.parseDouble(triple[1]);
            realDistance += Math.sqrt((curX - lastX) * (curX - lastX) + (curY - lastY) * (curY - lastY));
            int time = Integer.parseInt(triple[2]);
            timeList.add(time);
            xMap.put(time, curX);
            yMap.put(time, curY);
            lastX = curX;
            lastY = curY;
            maxTime = time;
        }
        int time = delt;
        lastX = xMap.get(0);
        lastY = yMap.get(0);
        int index = 0;
        double gpsDistance = 0.0;
        while(time < maxTime) {
            while(timeList.size() != index + 1 && timeList.get(index + 1) <= time) {
                index++;
            }
            int beforeTime = timeList.get(index);
            int afterTime = timeList.get(index + 1);
            double diffX = xMap.get(afterTime) - xMap.get(beforeTime);
            double diffY = yMap.get(afterTime) - yMap.get(beforeTime);
            double curX = diffX * (double)(time - beforeTime) / (double)(afterTime - beforeTime);
            double curY = diffY * (double)(time - beforeTime) / (double)(afterTime - beforeTime);
            


            gpsDistance += Math.sqrt((curX - lastX) * (curX - lastX) + (curY - lastY) * (curY - lastY));

            lastX = curX;
            lastY = curY;

            time += delt;
        }

//        gpsDistance += Math.sqrt((xMap.get(maxTime) - lastX) * (xMap.get(maxTime) - lastX) + (yMap.get(maxTime) - lastY) * (yMap.get(maxTime) - lastY));

        System.out.println(realDistance);
        System.out.println(gpsDistance);

        System.out.println(Math.abs(realDistance - gpsDistance) / realDistance * 100);
    }
}

