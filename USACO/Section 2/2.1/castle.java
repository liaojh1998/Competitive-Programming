/*
ID: liaojh11
LANG: JAVA
TASK: castle
*/
/*Type: Graph Theory
 *Solution: Brute force, DFS each module for amount of rooms and max room size, store room name and size and use each edge module's walls to find the wall to cut.*/

import java.util.*;
import java.io.*;

public class castle {
	private static String[][] modules; //walls of each modules
	private static boolean[][] checked; //dfs check
	private static int[][] group; //nametag
	private static int[][] roomsize; //room size
	private static int M;
	private static int N;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("castle.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("castle.out")));
		PrintWriter debug = new PrintWriter(new BufferedWriter(new FileWriter("castle.txt")));
		StringTokenizer st = new StringTokenizer(in.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		modules = new String[N+1][M+1];
		checked = new boolean[N+1][M+1];
		group = new int[N+1][M+1];
		roomsize = new int[N+1][M+1];
		
		//Wall reader
		for(int i = 1; i <= N; i++){
			st = new StringTokenizer(in.readLine());
			for(int j = 1; j <= M; j++){
				modules[i][j] = "";
				int wall = Integer.parseInt(st.nextToken());
				if(wall >= 8){
					wall -= 8;
					modules[i][j]+= "S";
				}
				if(wall >= 4){
					wall -= 4;
					modules[i][j]+= "E";
				}
				if(wall >= 2){
					wall -= 2;
					modules[i][j]+= "N";
				}
				if(wall >= 1){
					wall -= 1;
					modules[i][j]+= "W";
				}
			}
		}
		
		int rooms = 0;
		int max = 0;
		//DFS
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(checked[i][j]) continue;
				rooms++;
				int count = dfs(j, i, rooms); //assign the nametag number and dfs for max room size
				max = count > max ? count : max;
				size(j, i, count); //dfs assign the room size for each module
			}
		}
		
		String remove = "";
		int removemax = 0;
		//Check the edges, downward then leftward, only E and N walls are counted
		for(int i = M; i >= 1; i--){
			for(int j = 1; j <= N; j++){
				if(i != M && group[j][i+1] != group[j][i]){
					int tempsize = roomsize[j][i+1] + roomsize[j][i];
					if(tempsize >= removemax){
						remove = j + " " + i + " " + "E";
						removemax = tempsize;
					}
				}
				if(j != 1 && group[j][i] != group[j-1][i]){
					int tempsize = roomsize[j-1][i] + roomsize[j][i];
					if(tempsize >= removemax){
						remove = j + " " + i + " " + "N";
						removemax = tempsize;
					}
				}
			}
		}
		
		out.println(rooms);
		out.println(max);
		out.println(removemax);
		out.println(remove);
		debug.print(drawCastle());
		debug.close();
		out.close();
		System.exit(0);
	}
	
	//If there's no wall after a module, let's add 1 to the size and move to next module (and keep going until the end)
	public static int dfs(int x, int y, int name){
		if(checked[y][x]) return 0;
		group[y][x] = name;
		checked[y][x] = true;
		int count = 1;
		
		if(!modules[y][x].contains("W")) count+= dfs(x-1, y, name);
		if(!modules[y][x].contains("N")) count+= dfs(x, y-1, name);
		if(!modules[y][x].contains("E")) count+= dfs(x+1, y, name);
		if(!modules[y][x].contains("S")) count+= dfs(x, y+1, name);
		
		return count;
	}
	
	//Each module will get a size of the room they're in
	public static void size(int x, int y, int num){
		if(roomsize[y][x] != 0) return;
		roomsize[y][x] = num;
		if(!modules[y][x].contains("W")) size(x-1, y, num);
		if(!modules[y][x].contains("N")) size(x, y-1, num);
		if(!modules[y][x].contains("E")) size(x+1, y, num);
		if(!modules[y][x].contains("S")) size(x, y+1, num);
	}
	
	//Debug drawing
	public static String drawCastle(){
		String map = "";
		for(int i = 1; i <= M; i++){
			map+= " _";
		}
		map+= " \n";
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(modules[i][j].contains("W")) map+= "|"; else map+= " ";
				if(modules[i][j].contains("S")) map+= "_"; else map+= " ";
			}
			map+= "|\n";
		}
		return map;
	}
}