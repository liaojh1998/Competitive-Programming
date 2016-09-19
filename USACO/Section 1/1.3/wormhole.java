/*
ID: liaojh11
LANG: JAVA
TASK: wormhole
*/
/*Type: DFS/BFS
 *Solution: Sort all wormholes so they'll be 'in the +x direction', DFS/BFS because needs to check all solutions, then check to see if they loop.*/

import java.io.*;
import java.util.*;

public class wormhole {
	public static int N;
	public static int[] locate;
	public static Coord[] coords;
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("wormhole.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("wormhole.out")));
        N = Integer.parseInt(in.readLine());
        locate = new int[N];
        //set all pairing indexes to -1, basically mark them as not paired
        for(int i = 0; i < N; i++){
        	locate[i] = -1;
        }
        coords = new Coord[N];
        
        for(int i = 0; i < N; i++){
        	StringTokenizer st = new StringTokenizer(in.readLine());
        	coords[i] = new Coord(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }
        //sort them such that same y-coords next to each other, but bigger x-coords on the right (travel on +x direction)
        mergeSort(coords);
        //pair up and solve
        int total = pair();
        
        out.println(total);
        out.close();
        System.exit(0);
    }
    
    public static int pair(){
    	//set i as the locating index, if i arrives at anything unpaired, break loop and do not check
    	int i, total = 0;
    	for(i = 0; i < N; i++){
    		if(locate[i] == -1) break;
    	}
    	
    	//check for the +x direction because all paired up
    	if(i >= N){
    		if(check())
    			return 1;
    		return 0;
    	}
    	
    	//depth first search, iterate all and arrive at i index and pair up and check, then go to next index and pair up with i, then go to next index and pair up with i
    	for(int j = i + 1; j < N; j++){
    		if(locate[j] == -1){
    			locate[i] = j;
    			locate[j] = i;
    			total+= pair();
    			//reset once done to pair up again
    			locate[i] = locate[j] = -1;
    		}
    	}
    	return total;
    }
    
    public static boolean check(){
    	//for all elements
    	for(int i = 0; i < N; i++){
    		int index = i;
    		//if index has travelled all elements and still hasn't stopped, there is a loop
    		for(int j = 0; j < N; j++){
    			index = locate[index];
    			//check to the right of current coord with same Y and bigger X
    			if(index + 1 != N && coords[index].getY() == coords[index+1].getY()){
    				//if so, next index
    				index++;
    			}else{
    				//set index as no loop
    				index = -1;
    				break;
    			}
    		}
    		//if index was not set, there is loop
    		if(index != -1){
    			return true;
    		}
    	}
    	return false;
    }
    
    public static void mergeSort(Coord[] array){
    	int size = array.length;
    	if(size < 2)
    		return;
    	int mid = size/2;
    	int lSize = mid;
    	int rSize = size - mid;
    	Coord[] left = new Coord[lSize];
    	Coord[] right = new Coord[rSize];
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
    
    public static void merge(Coord[] larr, Coord[] rarr, Coord[] arr){
    	int lSize = larr.length;
    	int rSize = rarr.length;
    	int i = 0, j = 0, k = 0;
    	while(i < lSize && j < rSize){
    		//equal Y will be merged based on smaller X at the front
    		if(larr[i].getY() == rarr[j].getY()){
    			if(larr[i].getX() <= rarr[j].getX())
    				arr[k++] = larr[i++];
    			else
    				arr[k++] = rarr[j++];
    		}else{
    			//this part doesn't matter, but does organize well.
    			if(larr[i].getY() < rarr[j].getY())
    				arr[k++] = larr[i++];
    			else
    				arr[k++] = rarr[j++];
    		}
    	}
    	while(i < lSize)
    		arr[k++] = larr[i++];
    	while(j < rSize)
    		arr[k++] = rarr[j++];
    }
}

class Coord{
	private int x;
	private int y;
	public Coord(int x, int y){
		this.x = x;
		this.y = y;
	}
	public int getX(){
		return x;
	}
	public int getY(){
		return y;
	}
}