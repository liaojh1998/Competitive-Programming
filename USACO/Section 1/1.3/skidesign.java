/*
ID: liaojh11
LANG: JAVA
TASK: skidesign
*/
/*Type: Brute Force
 *Solution: Check each different intervals and make sure each hill fits in that interval, check each cost and find the smallest summed up cost.*/

import java.io.*;
import java.util.*;

public class skidesign {
	public static int[] hill;
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("skidesign.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("skidesign.out")));
        int N = Integer.parseInt(in.readLine());
        hill = new int[N];
        for(int i = 0; i < N; i++){
        	hill[i] = Integer.parseInt(in.readLine());
        }
        //troll question, looks hard, all that's required is brute force because 1000 and 100 is small range
        int cost = 100000000;
        int start = 0;
        int tempcost = 0;
        //place i+17 range inverval and calculate cost of all range changes to fit that interval
        while(start+17 <= 100){
        	tempcost = 0;
        	for(int i = 0; i < N; i++){
        		if(hill[i] < start){
        			tempcost+= Math.pow(start - hill[i],2);
        		}else if(hill[i] > start+17){
        			tempcost+= Math.pow(hill[i] - (start+17),2);
        		}
        	}
        	if(tempcost < cost){
        		cost = tempcost;
        	}
        	start++;
    	}
        
        out.println(cost);
        out.close();
        System.exit(0);
    }
}