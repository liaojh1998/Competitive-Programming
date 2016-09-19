/*
ID: liaojh11
LANG: JAVA
TASK: pprime
*/
/*Type: DFS/Brute Force
 *Solution: Generate all palindromes and see if they're prime.*/
 //Fun fact: All even-lengthed palindromes are divisible by 11, that means only 11 is the only prime palindrome for even-lengthed palindromes.

import java.util.*;
import java.io.*;

public class pprime {
	private static SortedSet<Integer> solutions;
	private static String[] range;
	private static String[] numbers;
	private static int last;
	private static int first;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("pprime.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pprime.out")));
		//2 types, odd-length or even-length
		numbers = new String[]{"0","1","2","3","4","5","6","7","8","9","00","11","22","33","44","55","66","77","88","99"};
		range = in.readLine().split(" ");
		first = Integer.parseInt(range[0]);
		last = Integer.parseInt(range[1]);
		solutions = new TreeSet<Integer>();
		
		for(String i : numbers){
			dfs(i);
		}
		
		List<Integer> sol = new ArrayList<Integer>();
		sol.addAll(solutions);
		
		for(int i : sol){
			out.println(i);
		}
		out.close();
		System.exit(0);
	}
	
	public static void dfs(String num){
		prime(num);
		
		//Stop if palindrome's length is about to be bigger than the range's length
		if(num.length() + 2 > range[1].length()) return;
		
		for(int i = 0; i <= 9; i++){
			String temp = i + num + i;
			dfs(temp);
		}
	}
	
	public static void prime(String num){
		int temp = Integer.parseInt(num);
		
		//Even or divisible by 3?
		if(temp%2 == 0 || temp%3 == 0) return;
		//Not in range?
		if(temp < first || temp > last) return;
		//Has a 0 in front?
		if(Integer.toString(temp).length() != num.length()) return;
		//Not a prime?
		for(int i = 5; i*i <= temp; i+=2){
			if(temp % i == 0)
				return;
		}
		
		solutions.add(temp);
	}
}