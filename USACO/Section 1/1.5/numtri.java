/*
ID: liaojh11
LANG: JAVA
TASK: numtri
*/
/*Type: DFS
 *Solution: Non-recursive DFS, compare and sum up last triangle into the top (less time-consuming and energy efficient and top to bot depth search).*/

import java.util.*;
import java.io.*;

public class numtri {
	private static int N;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("numtri.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("numtri.out")));
		
		N = Integer.parseInt(in.readLine());
		int[][] array = new int[N][N];
		for(int i = 0; i < array.length; i++){
			StringTokenizer st = new StringTokenizer(in.readLine());
			for(int j = 0; j < i + 1; j++){
				array[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		int sum = DFS(N, array);
		out.println(sum);
		out.close();
		System.exit(0);
	}
	
	public static int DFS(int n, int[][] array){
		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j <= i; j++){
				array[i][j]+= Math.max(array[i+1][j], array[i+1][j+1]);
			}
		}
		return array[0][0];
	}
}