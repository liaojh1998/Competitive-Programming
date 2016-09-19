/*
ID: liaojh11
LANG: JAVA
TASK: ariprog
*/
/*Type: Brute Force + Greedy
 *Solution: Find all possible p^2+q^2 and test all Nth progessions with increments greedily less than 5000.*/

import java.io.*;
import java.util.*;

public class ariprog {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("ariprog.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("ariprog.out")));
        int N = Integer.parseInt(in.readLine());
        int M = Integer.parseInt(in.readLine());
        String solutions = "";
        ArrayList<temp> t = new ArrayList<temp>();
        boolean[] S = new boolean[M*M*2+1];
        ArrayList<Integer> list = new ArrayList<Integer>();
        for(int i = 0; i <= M; i++){
        	for(int j = 0; j <= M; j++){
        		if(S[i*i+j*j]) continue;
        		S[i*i+j*j] = true;
        		list.add(i*i+j*j);
        	}
        }
        Collections.sort(list);
        
        for(int i = 0; i < list.size(); i++){
        	//Greedy 5000
        	for(int j = 1; j < 5000; j++){
        		int temp = list.get(i);
        		int k = 0;
        		//if consecutive N & number is inside max range & number is a bisquare
        		for(k = 0; k < N && temp < S.length && S[temp]; k++){
        			temp+= j;
        		}
        		if(k == N){
        			t.add(new temp(list.get(i),j));
        		}
        	}
        }
        Collections.sort(t);
        
        for(int i = 0; i < t.size(); i++){
        	solutions+= t.get(i);
        }
        
        out.print(solutions != "" ? solutions : "NONE\n");
        out.close();
        System.exit(0);
    }
}

//Remember there's also a long storage method using operators to store something like this, make sure to look into it.
class temp implements Comparable<temp>{
	public int x;
	public int y;
	public temp(int x, int y){
		this.x = x;
		this.y = y;
	}
	public int compareTo(temp t){
		if(this.y == t.y){
			if(this.x <= t.x)
				return -1;
			else
				return 1;
		}else if(this.y < t.y){
			return -1;
		}else{
			return 1;
		}
	}
	public String toString(){
		return x + " " + y + "\n";
	}
}