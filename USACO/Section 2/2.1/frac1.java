/*
ID: liaojh11
LANG: JAVA
TASK: frac1
*/
/*Type: DFS
 *Solution: Brute force every possible fraction and sort.*/

import java.util.*;
import java.io.*;

public class frac1 {
	private static int N;
	private static boolean[][] checked;
	private static List<frac> solution;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("frac1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));
		N = Integer.parseInt(in.readLine());
		checked = new boolean[N+1][N+1];
		solution = new ArrayList<frac>();
		DFS(0, 1);
		
		Collections.sort(solution);
		
		for(int i = 0; i < solution.size(); i++){
			out.println(solution.get(i));
		}
		out.close();
		System.exit(0);
	}
	
	public static void DFS(int a, int b){
		if(a > b || b > N) return;
		if(checked[a][b]) return;
		checked[a][b] = true;
		
		int deno = gcf(a, b);
		if(deno == 1) solution.add(new frac(a, b));
		else{
			int a1 = a/deno;
			int b1 = b/deno;
			if(!checked[a1][b1]){
				solution.add(new frac(a1, b1));
				checked[a1][b1] = true;
			}
		}
		
		DFS(a, b+1);
		DFS(a+1, b);
	}
	
	public static int gcf(int a, int b){
		if(b == 0)
			return a;
		return gcf(b, a % b);
	}
	
	private static class frac implements Comparable<frac>{
		private int a;
		private int b;
		public frac(int a, int b){
			this.a = a;
			this.b = b;
		}
		public int compareTo(frac f){
			if(f.deci() > this.deci()) return -1;
			else return 1;
		}
		public double deci(){
			return (double) a/b;
		}
		public String toString(){
			return a + "/" + b;
		}
	}
}

/* Russ's Solution, simple recursion (On what level of math and logic will I get this?!?!?!?!)
public class frac1 {
	private static int N;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("frac1.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("frac1.out")));
		N = Integer.parseInt(in.readLine());
		
		out.println("0/1");
		out.print(genfrac(0,1,1,1));
		out.println("1/1");
		
		out.close();
		System.exit(0);
	}
	
	public static String genfrac(int n1, int d1, int n2, int d2){
		if(d1+d2 > N) return "";
		return genfrac(n1, d1, n1+n2, d1+d2) + Integer.toString(n1 + n2) + "/" + Integer.toString(d1 + d2) + "\n" + genfrac(n1+n2, d1+d2, n2, d2);
	}
}
*/