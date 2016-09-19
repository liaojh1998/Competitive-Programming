/*
ID: liaojh11
LANG: JAVA
TASK: milk2
*/

import java.util.*;
import java.io.*;

public class milk2 {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("milk2.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"milk2.out")), true);
		TimeSpan[] timespans = new TimeSpan[Integer.parseInt(in.readLine())];
		for (int i = 0; i < timespans.length; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			timespans[i] = new TimeSpan(Integer.parseInt(st.nextToken()),
					Integer.parseInt(st.nextToken()));
		}

		// sort by start
		Arrays.sort(timespans, new Comparator<TimeSpan>() {
			public int compare(TimeSpan arg0, TimeSpan arg1) {
				if (arg0.start < arg1.start)
					return -1;
				if (arg0.start > arg1.start)
					return 1;
				return 0;
			}
		});

		// merge overlapping time
		for (int i = 0; i < timespans.length - 1; i++) {
			if (timespans[i].end <= timespans[i + 1].start)
				continue;
			else if (timespans[i].end > timespans[i + 1].start
					&& timespans[i].end < timespans[i + 1].end)
				timespans[i].end = timespans[i + 1].start;
			else 
				timespans[i + 1].start = timespans[i + 1].end = timespans[i].end;
		}

		// calculate longest milked
		int longestMilked = 0;
		int curMilked = timespans[0].end - timespans[0].start;
		for (int i = 0; i < timespans.length - 1; i++) {
			if (timespans[i].end == timespans[i + 1].start)
				curMilked += timespans[i + 1].end - timespans[i + 1].start;
			else {
				longestMilked = curMilked > longestMilked ? curMilked
						: longestMilked;
				curMilked = timespans[i + 1].end - timespans[i + 1].start;
			}
		}
		longestMilked = curMilked > longestMilked ? curMilked : longestMilked;

		// calculate longest not milked
		int longestNotMilked = 0;
		if (timespans.length == 1)
			longestNotMilked = 0;
		for (int i = 0; i < timespans.length - 1; i++) {
			int notMilked = timespans[i + 1].start - timespans[i].end;
			longestNotMilked = notMilked > longestNotMilked ? notMilked
					: longestNotMilked;
		}

		// output
		out.print(longestMilked + " ");
		out.println(longestNotMilked);

		System.exit(0);
	}
}

class TimeSpan {
	public int start;
	public int end;
	public TimeSpan(int start, int end) {
		this.start = start;
		this.end = end;
	}
}