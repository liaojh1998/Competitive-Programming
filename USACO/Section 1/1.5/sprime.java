/*
ID: liaojh11
LANG: JAVA
TASK: sprime
*/
/*Type: DFS/Brute Force
 *Solution: DFS Strings downward and find the superprime ribs.*/

import java.util.*;
import java.io.*;

public class sprime {
	private static List<Integer> solutions;
	private static int length;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("sprime.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sprime.out")));
		length = Integer.parseInt(in.readLine());
		solutions = new ArrayList<Integer>();
		
		//Ignore 1 since 1 is not a prime
		for(int i = 2; i <= 9; i++){
			dfs(Integer.toString(i));
		}
		
		//Solution is already sorted
		for(int i : solutions){
			out.println(i);
		}
		out.close();
		System.exit(0);
	}
	
	public static void dfs(String num){
		//Check if prime each DFS
		if(!prime(num)) return;
		
		//Concatenate numbers, check, until full length
		for(int i = 0; i <= 9; i++){
			String temp = num + i;
			dfs(temp);
		}
	}
	
	public static boolean prime(String num){
		int temp = Integer.parseInt(num);
		
		//1 is not prime, but 2, 3, 5 is.
		if(temp == 2 || temp == 3 || temp == 5) return true;
		
		//Even or divisible by 3?
		if(temp%2 == 0 || temp%3 == 0) return false;
		//Not a prime?
		for(int i = 5; i*i <= temp; i+=2){
			if(temp % i == 0)
				return false;
		}
		
		//Full length and prime?
		if(Integer.toString(temp).length() == length){
			solutions.add(temp);
			return false;
		}
		
		//Still prime?
		return true;
	}
}