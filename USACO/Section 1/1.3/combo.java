/*
ID: liaojh11
LANG: JAVA
TASK: combo
*/

import java.io.*;
import java.util.*;

public class combo {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("combo.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("combo.out")));
        ArrayList<int[]> combos = new ArrayList<int[]>();
        ArrayList<int[]> allowed = new ArrayList<int[]>();
        int max = Integer.parseInt(in.readLine());
        String[] number = in.readLine().split(" ");
        int[] pcombo = new int[3];
        String[] number2 = in.readLine().split(" ");
        int[] mcombo = new int[3];
        for(int i = 0; i < 3; i++){
        	pcombo[i] = Integer.parseInt(number[i]);
        }
        for(int i = 0; i < 3; i++){
        	mcombo[i] = Integer.parseInt(number2[i]);
        }
        
        for(int i = -2; i <= 2; i++){
        	for(int j = -2; j <= 2; j++){
        		for(int k = -2; k <= 2; k++){
        			int x = 0;
        			int y = 0;
        			int z = 0;
        			if(pcombo[0] + i <= 0){
        				x = max + pcombo[0] + i;
        			}else if(pcombo[0] + i > max){
        				x = pcombo[0] + i - max;
        			}else{
        				x = pcombo[0] + i;
        			}
        			if(pcombo[1] + j <= 0){
        				y = max + pcombo[1] + j;
        			}else if(pcombo[1] + j > max){
        				y = pcombo[1] + j - max;
        			}else{
        				y = pcombo[1] + j;
        			}
        			if(pcombo[2] + k <= 0){
        				z = max + pcombo[2] + k;
        			}else if(pcombo[2] + k > max){
        				z = pcombo[2] + k - max;
        			}else{
        				z = pcombo[2] + k;
        			}
        			int[] newcombo = {x, y, z};
        			if(x > 0 && x <= max && y > 0 && y <= max && z > 0 && z <= max){
        				boolean has = false;
        				for(int allowednum = 0; allowednum < allowed.size(); allowednum++){
        					int atemp[] = allowed.get(allowednum);
        					if(atemp[0] == x && atemp[1] == y && atemp[2] == z){
        						has = true;
        						allowednum = allowed.size();
        					}
        				}
        				if(!has){
        					allowed.add(newcombo);
        				}
        			}
        		}
        	}
        }
        
        for(int i = -2; i <= 2; i++){
        	for(int j = -2; j <= 2; j++){
        		for(int k = -2; k <= 2; k++){
        			int x = 0;
        			int y = 0;
        			int z = 0;
        			if(mcombo[0] + i <= 0){
        				x = max + mcombo[0] + i;
        			}else if(mcombo[0] + i > max){
        				x = mcombo[0] + i - max;
        			}else{
        				x = mcombo[0] + i;
        			}
        			if(mcombo[1] + j <= 0){
        				y = max + mcombo[1] + j;
        			}else if(mcombo[1] + j > max){
        				y = mcombo[1] + j - max;
        			}else{
        				y = mcombo[1] + j;
        			}
        			if(mcombo[2] + k <= 0){
        				z = max + mcombo[2] + k;
        			}else if(mcombo[2] + k > max){
        				z = mcombo[2] + k - max;
        			}else{
        				z = mcombo[2] + k;
        			}
        			int[] newcombo = {x, y, z};
        			if(x > 0 && x <= max && y > 0 && y <= max && z > 0 && z <= max){
        				boolean has = false;
        				for(int allowednum = 0; allowednum < allowed.size(); allowednum++){
        					int atemp[] = allowed.get(allowednum);
        					if(atemp[0] == x && atemp[1] == y && atemp[2] == z){
        						has = true;
        						allowednum = allowed.size();
        					}
        				}
        				if(!has){
        					allowed.add(newcombo);
        				}
        			}
        		}
        	}
        }
        
        out.println(allowed.size());
        out.close();
        System.exit(0);
    }
}