/*
ID: liaojh11
LANG: JAVA
TASK: milk3
*/
/*Type: DFS/BFS
 *Solution: DFS/BFS everything possible, boolean used to check if solution has been checked (pruning the search).*/

import java.io.*;
import java.util.*;

public class milk3 {
	public static int Acap, Bcap, Ccap;
	public static boolean[][][] check;
	public static SortedSet<Integer> S = new TreeSet<Integer>();
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("milk3.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk3.out")));
        StringTokenizer st = new StringTokenizer(in.readLine());
        Acap = Integer.parseInt(st.nextToken());
        Bcap = Integer.parseInt(st.nextToken());
        Ccap = Integer.parseInt(st.nextToken());
        check = new boolean[Acap+1][Bcap+1][Ccap+1];
        
        //Initial condition, 0 in A & B, C is capped
        dfs(0, 0, Ccap);
        ArrayList<Integer> A = new ArrayList<Integer>(S);
        String s = "";
        for(int i = 0; i < A.size(); i++){
        	if(i == A.size()-1){
        		s+= A.get(i);
        		break;
        	}
        	s+= A.get(i) + " ";
        }
        
        out.println(s);
        out.close();
        System.exit(0);
    }
    
    public static void dfs(int a, int b, int c){
    	if(check[a][b][c] == true) return;
    	check[a][b][c] = true;
    	
    	if(a == 0){
    		S.add(c);
    	}
    	
    	//DFS everything possible
    	//c to a
    	dfs(a+Math.min(c, Acap - a), b, c-Math.min(c, Acap - a));
    	//a to c
    	dfs(a-Math.min(a, Ccap - c), b, c+Math.min(a, Ccap - c));
    	//b to a
    	dfs(a+Math.min(b, Acap - a), b-Math.min(b, Acap - a), c);	
    	//a to b
    	dfs(a-Math.min(a, Bcap - b), b+Math.min(a, Bcap - b), c);
    	//c to b
    	dfs(a, b+Math.min(c, Bcap - b), c-Math.min(c, Bcap - b));
    	//b to c
    	dfs(a, b-Math.min(b, Ccap - c), c+Math.min(b, Ccap - c));
    }
}

//A BFS Solution
/*
BFS, ??????a???????
ID: skyzhan1
LANG: JAVA
TASK: milk3
*/
/*

import java.util.*;
import java.io.*;
 
public class milk3 {
	public static void main(String[] args) throws Exception {
		BufferedReader f = new BufferedReader(new FileReader("milk3.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"milk3.out")));
		StringTokenizer st = new StringTokenizer(f.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
 
		boolean[] cAmount = BFS(a, b, c);
		print(cAmount, out);
		out.close();
	}
 
	public static void print(boolean[] amount, PrintWriter out){
		String s ="";
		for(int i=0; i<amount.length; i++){
			if(amount[i]){
				s +=i+" ";
			}
		}
		out.println(s.trim());
	}
 
	public static boolean[] BFS(int a, int b, int c){
		boolean[][] reach = new boolean[a+1][b+1];
		boolean[] cAmount = new boolean[c+1];
		List<State> states = new ArrayList<State>();
		State state;
		states.add(new State(0, 0));
//		if(reach[0][0]){
//			System.out.println("damn it");
//		}
		reach[0][0] = true;
		cAmount[c] = true;
		int x, y;
		int an, bn, cn;
		while(!states.isEmpty()){
			state = states.remove(states.size()-1);
			x = state.getX();
			y = state.getY();
			//a to b
			if(x>0){
				bn = Math.min(b, x+y);
				an = x+y-bn;
				if(!reach[an][bn]){
					states.add(new State(an, bn));
					reach[an][bn]= true;
					if(an==0){
					cAmount[c-x-y]= true;
					}
				}
			}
			//a to c
			if(x>0){
				if(!reach[0][y]){
					states.add(new State(0, y));
					reach[0][y] = true;
					cAmount[c-y]= true;
				}
			}
			//b to a
			if(y>0){
				an = Math.min(a, x+y);
				bn = x+y-an;
				if(!reach[an][bn]){
					states.add(new State(an, bn));
					reach[an][bn]= true;
//					cAmount[x+y]= true;
				}
			}
			//b to c
			if(y>0){
				if(!reach[x][0]){
					states.add(new State(x, 0));
					reach[x][0] = true;
//					cAmount[c-y]= true;
				}
			}
			//c to a
			if(c>0){
				an = Math.min(a, c-y);
				if(!reach[an][y]){
					states.add(new State(an, y));
					reach[an][y] = true;
				}
			}
			//c to b
			if(c>0){
				bn = Math.min(b, c-x);
				if(!reach[x][bn]){
					states.add(new State(x, bn));
					reach[x][bn] = true;
//					System.out.println(x+" "+bn);
					if(x==0){
						cAmount[c-bn] = true;
					}
				}
			}
		}
		return cAmount;
	}
}
 
class State{
	private int a;
	private int b;
	public State(int a, int b){
		this.a = a;
		this.b = b;
	}
	public int getX(){
		return a;
	}
	public int getY(){
		return b;
	}
}
*/