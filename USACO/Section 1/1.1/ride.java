/*
ID: liaojh11
LANG: JAVA
TASK: ride
*/

import java.io.*;
import java.util.*;

public class ride {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("ride.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ride.out")));
        String a = in.readLine();
        String b = in.readLine();
        
        int anum = 1;
        int bnum = 1;
        for(int i = 0; i < a.length(); i++){
        	anum*= Character.getNumericValue(a.charAt(i))-9;
        }
        for(int i = 0; i < b.length(); i++){
        	bnum*= Character.getNumericValue(b.charAt(i))-9;
        }
        
        out.println((anum%47 == bnum%47) ? "GO" : "STAY");
        out.close();
        System.exit(0);
    }
}