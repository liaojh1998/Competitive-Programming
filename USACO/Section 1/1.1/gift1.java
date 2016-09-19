/*
ID: liaojh11
LANG: JAVA
TASK: gift1
*/

import java.util.*;
import java.io.*;

public class gift1 {
    public gift1() {
    }
    public static void main(String[] args) throws IOException{
        Scanner s = new Scanner(new FileReader("gift1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("gift1.out")));
        ArrayList<person> group = new ArrayList<person>();
        int start = Integer.parseInt(s.nextLine());
        for(int i = 0; i < start; i++){
        	group.add(new person(s.nextLine()));
        }
        while(s.hasNext()){
        	String name = s.nextLine();
        	String[] m = s.nextLine().split(" ");
        	int m1 = Integer.parseInt(m[0]);
        	int m2 = Integer.parseInt(m[1]);
        	for(int i = 0; i < group.size(); i++){
        		if(group.get(i).name().equals(name)){
        			group.get(i).startmoney(m1);
        			if(m2!= 0) group.get(i).add(m1%m2);
        			i = group.size();
        		}
        	}
        	for(int i = 0; i < m2; i++){
        		String indexname = s.nextLine();
        		for(int j = 0; j < group.size(); j++){
        			if(group.get(j).name().equals(indexname)){
        				if(m2 != 0) group.get(j).add(m1/m2);
        				j = group.size();
        			}
        		}
        	}
        }
        for(int i = 0; i < group.size(); i++){
        	out.println(group.get(i).name() + " " + (group.get(i).money()-group.get(i).startmoney()));
        }
        out.close();
        System.exit(0);
    }
}

class person{
	private String name;
	private int money;
	private int startmoney;
	public person(String name){
		this.name = name;
		this.money = 0;
	}
	public String name(){
		return name;
	}
	public void startmoney(int m){
		startmoney = m;
	}
	public int startmoney(){
		return startmoney;
	}
	public void add(int amount){
		money+= amount;
	}
	public int money(){
		return money;
	}
}