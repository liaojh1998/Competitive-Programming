/*
ID: liaojh11
LANG: JAVA
TASK: beads
*/

import java.util.*;
import java.io.*;

class beads {
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new FileReader("beads.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("beads.out")));
        int num = Integer.parseInt(s.nextLine());
        String bline = s.nextLine();
        String bstring = bline+bline;
        int loc = 0;
        int max = 0;
        while(loc < bstring.length()){
        	int temp = recur(bstring.substring(loc), bstring.charAt(loc), 0);
        	if(max < temp){
        		max = temp;
        	}
        	loc++;
        }
        if(max == 0 || max > num){
        	out.println(num);
        }else{
        	out.println(max);
        }
        out.close();
        System.exit(0);
    }
    
    public static int recur(String a, char b, int c){
    	if(c == 2){
    		return 0;
    	}
    	
    	if(a.length() != 1){
    		a = a.substring(1);
    		if(b == 'w'){
    			b = a.charAt(0);
    		}else if(b != a.charAt(0) && a.charAt(0) != 'w'){
    			c++;
    			b = a.charAt(0);
    		}
    		return recur(a, b, c) + 1;
    	}
    	
    	return 0;
    }
}