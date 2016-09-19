/*
ID: liaojh11
LANG: JAVA
TASK: milk
*/

import java.io.*;
import java.util.*;

public class milk {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("milk.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("milk.out")));
        String farmerneeds[] = in.readLine().split(" ");
        int need = Integer.parseInt(farmerneeds[0]);
        int farmers = Integer.parseInt(farmerneeds[1]);
        farmer[] f = new farmer[farmers];
        for(int i = 0; i < farmers; i++){
        	StringTokenizer st = new StringTokenizer(in.readLine());
        	f[i] = new farmer(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        mergeSort(f);
        int have = 0;
        int cost = 0;
        int index = 0;
        while(have < need){
        	if(f[index].getOffer() > 0){
        		have++;
        		cost+= f[index].getCost();
        		
        		f[index].decre();
        	}else{
        		index++;
        	}
        }
        out.println(cost);
        
        out.close();
        System.exit(0);
    }
    
    public static void mergeSort(farmer[] array){
    	int size = array.length;
    	if(size < 2)
    		return;
    	int mid = size/2;
    	int lSize = mid;
    	int rSize = size - mid;
    	farmer[] left = new farmer[lSize];
    	farmer[] right = new farmer[rSize];
    	for(int i = 0; i < mid; i++){
    		left[i] = array[i];
    	}
    	for(int i = mid; i < size; i++){
    		right[i-mid] = array[i];
    	}
    	mergeSort(left);
    	mergeSort(right);
    	merge(left, right, array);
    }
    
    public static void merge(farmer[] larr, farmer[] rarr, farmer[] arr){
    	int lSize = larr.length;
    	int rSize = rarr.length;
    	int i = 0, j = 0, k = 0;
    	while(i < lSize && j < rSize){
    		if(larr[i].getCost() <= rarr[j].getCost())
    			arr[k++] = larr[i++];
    		else
    			arr[k++] = rarr[j++];
    	}
    	while(i < lSize)
    		arr[k++] = larr[i++];
    	while(j < rSize)
    		arr[k++] = rarr[j++];
    }
}

class farmer{
	private int cost;
	private int offer;
	public farmer(int c, int o){
		cost = c;
		offer = o;
	}
	public int getCost(){
		return cost;
	}
	public int getOffer(){
		return offer;
	}
	public void decre(){
		offer--;
	}
}