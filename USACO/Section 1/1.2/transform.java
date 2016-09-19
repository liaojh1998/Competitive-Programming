/*
ID: liaojh11
LANG: JAVA
TASK: transform
*/

import java.util.*;
import java.io.*;

public class transform {
	private static char[][] given;
	private static char[][] transformed;
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("transform.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"transform.out")), true);
		int c = Integer.parseInt(in.readLine());
		given = new char[c][c];
		transformed = new char[c][c];
		for(int i = 0; i < c; i++){
			given[i] = in.readLine().toCharArray();
		}
		for(int i = 0; i < c; i++){
			transformed[i] = in.readLine().toCharArray();
		}
		
		if(R90()){
			out.println("1");
			System.exit(0);
		}
		
		if(R90()){
			out.println("2");
			System.exit(0);
		}
		
		if(R90()){
			out.println("3");
			System.exit(0);
		}
		
		R90();
		
		if(refl()){
			out.println("4");
			System.exit(0);
		}
		
		if(R90()){
			out.println("5");
			System.exit(0);
		}
		
		if(R90()){
			out.println("5");
			System.exit(0);
		}
		
		if(R90()){
			out.println("5");
			System.exit(0);
		}
		
		R90();
		refl();
		
		if(refl()){
			out.println("5");
			System.exit(0);
		}
		refl();
		R90();
		if(refl()){
			out.println("5");
			System.exit(0);
		}
		refl();
		R90();
		if(refl()){
			out.println("5");
			System.exit(0);
		}
		refl();
		R90();
		
		if(nc()){
			out.println("6");
			System.exit(0);
		}
		
		out.println("7");
		System.exit(0);
	}
	
	public static boolean nc(){
		String a = "";
		String b = "";
		
		for(int i = 0; i < given.length; i++){
			a+= new String(given[i]);
		}
		for(int i = 0; i < transformed.length; i++){
			b+= new String(transformed[i]);
		}
		
		return a.equals(b);
	}
	
	public static boolean R90(){
		char temp[][] = new char[given.length][given[0].length];
		int index = given.length-1;
		for(int i = 0; i < given.length; i++){
			for(int j = 0; j < given[i].length; j++){
				temp[j][index] = given[i][j];
			}
			index--;
		}
		given = temp;
		return nc();
	}
	
	public static boolean refl(){
		char temp[][] = new char[given.length][given[0].length];
		for(int i = 0; i < given.length; i++){
			for(int j = 0; j < given[i].length; j++){
				temp[i][given[i].length-1-j] = given[i][j];
			}
		}
		given = temp;
		String a = "";
		String b = "";
		for(int i = 0; i < given.length; i++){
			a+= new String(given[i]);
		}
		for(int i = 0; i < transformed.length; i++){
			b+= new String(transformed[i]);
		}
		return nc();
	}
}