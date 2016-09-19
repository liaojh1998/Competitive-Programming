/*
ID: liaojh11
LANG: JAVA
TASK: friday
*/

import java.io.*;
import java.util.*;

public class friday {
    public static int N;
    public static int[] days;
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("friday.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("friday.out")));
        
        //set finishing year & instantiation
        N = 1900 + Integer.parseInt(in.readLine());
        days = new int[7];
        
        //call
        count(0, 1, 1, 1900);
        
        out.println(days[5] + " " + days[6] + " " + days[0] + " " + days[1] + " " + days[2] + " " + days[3] + " " + days[4]);
        out.close();
        System.exit(0);
    }
    
    public static void count(int day, int date, int month, int year){
    	//precondition: if year is less than allowed
    	if(year < N){
    		//find date where 13 appears and add a count to the day
    		if(date == 13){
    			days[day]++;
    		}
    		
    		//Feb of a leap?
    		if(month == 2 && ((year%400 == 0) || (year%100 != 0 && year%4 == 0)) && date == 29){
    			count(day(day), 1, 3, year);
    		//Feb of a non-leap?
    		}else if(month == 2 && !((year%400 == 0) || (year%100 != 0 && year%4 == 0)) && date == 28){
    			count(day(day), 1, 3, year);
    		//30-months?
    		}else if((month == 9 || month == 11 || month == 4 || month == 6) && date == 30){
    			count(day(day), 1, month+1, year);
    		//December?
    		}else if(month == 12 && date == 31){
    			count(day(day), 1, 1, year+1);
    		//31-months?
    		}else if(date == 31){
    			count(day(day), 1, month+1, year);
    		//if none of the above, change dates and days
    		}else{
    			count(day(day), date+1, month, year);
    		}
    	}
    }
    
    //date changer
    public static int day(int d){
    	if(d == 6){
    		return 0;
    	}else{
    		return d+1;
    	}
    }
}