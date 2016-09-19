/*
ID: liaojh11
LANG: JAVA
TASK: palsquare
*/

import java.io.*;
import java.util.*;

public class palsquare {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("palsquare.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("palsquare.out")));
        int base = Integer.parseInt(in.readLine());
        for(int i = 1; i <= 300; i++){
        	String number = Long.toString(i, base);
        	String squared = Long.toString((int)Math.pow(i,2), base);
        	if(pal(squared)){
        		out.println(number.toUpperCase() + " " + squared.toUpperCase());
        	}
        }
        
        out.close();
        System.exit(0);
    }
    
    public static boolean pal(String number){
    	boolean b = true;
    	for(int i = 0; i < number.length()/2; i++){
    		if(number.charAt(i) != number.charAt(number.length()-1-i))
    			b = false;
    	}
    	return b;
    }
}