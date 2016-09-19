/*
ID: liaojh11
LANG: JAVA
TASK: dualpal
*/

import java.io.*;
import java.util.*;

public class dualpal {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("dualpal.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("dualpal.out")));
        String[] number = in.readLine().split(" ");
        int N = Integer.parseInt(number[0]);
        int S = Integer.parseInt(number[1]);
        int amount = 0;
        int i = 0;
        while(amount < N){
        	int index = 0;
        	i++;
        	for(int j = 2; j <= 10; j++){
        		String num = Long.toString(S+i, j);
        		if(pal(num)){
        			index++;
        			if(index >= 2){
        				break;
        			}
        		}
        	}
        	if(index >= 2){
        		out.println(S+i);
        		amount++;
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