/*
ID: liaojh11
LANG: JAVA
TASK: crypt1
*/
/*Type: Greedy
 *Solution: Iterate 5 times and see if each part results with numbers that are given and allowed.*/

import java.io.*;
import java.util.*;

public class crypt1 {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("crypt1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("crypt1.out")));
        int N = Integer.parseInt(in.readLine());
        String digits = in.readLine().replaceAll("\\s", "");
        int count = 0;
        
        /*Condition for a valid solution:
         *All parts of crypt has digits that are allowed.
         */
        for(int a = 0; a < N; a++){
        	for(int b = 0; b < N; b++){
        		for(int c = 0; c < N; c++){
        			int topline = Integer.parseInt("" + digits.charAt(a) + digits.charAt(b) + digits.charAt(c));
        			for(int d = 0; d < N; d++){
        				String partial1 = String.valueOf(Integer.parseInt("" + digits.charAt(d)) * topline); //digits.charAt(d) - '0' can also give the same results as Integer.parseInt()
        				if(partial1.length() > 3 || !check(partial1, digits)){
        					continue; //this continues to the next iteration
        				}
        				for(int e = 0; e < N; e++){
        					String partial2 = String.valueOf(Integer.parseInt("" + digits.charAt(e)) * topline);
        					if(partial2.length() > 3 || !check(partial2, digits)){
        						continue;
        					}
        					String product = String.valueOf(Integer.parseInt(partial1)*10 + Integer.parseInt(partial2));
        					if(!check(product, digits)){
        						continue;
        					}
        					count++;
        				}
        			}
        		}
        	}
        }
        
        out.println(count);
        out.close();
        System.exit(0);
    }
    
    public static boolean check(String a, String b){
    	for(int i = 0; i < a.length(); i++){
    		if(!b.contains("" + a.charAt(i))){
    			return false;
    		}
    	}
    	return true;
    }
}