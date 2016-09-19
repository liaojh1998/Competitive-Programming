/*
ID: liaojh11
LANG: JAVA
TASK: barn1
*/

import java.io.*;
import java.util.*;

public class barn1 {
    public static void main(String[] args) throws IOException{
        BufferedReader in = new BufferedReader(new FileReader("barn1.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("barn1.out")));
        String[] pre = in.readLine().split(" ");
        int maxboard = Integer.parseInt(pre[0]);
        int occu = Integer.parseInt(pre[2]);
        int[] boards = new int[occu];
		for(int i = 0; i < occu; i++){
        	StringTokenizer st = new StringTokenizer(in.readLine());
        	boards[i] = Integer.parseInt(st.nextToken());
        }
        mergeSort(boards);
        ArrayList<int[]> boardlist = new ArrayList<int[]>();
        for(int i = 0; i < boards.length; i++){
        	for(int j = i; j < boards.length; j++){
        		if(j+1 == boards.length){
        			int[] array = new int[j+1 - i];
        			for(int p = 0; p < array.length; p++)
        				array[p] = boards[p + i];
        			boardlist.add(array);
        			i = j;
        			j = boards.length;
        		}else if(boards[j+1]-boards[j] > 1){
        			int[] array = new int[j+1 - i];
        			for(int p = 0; p < array.length; p++)
        				array[p] = boards[p + i];
        			boardlist.add(array);
        			i = j;
        			j = boards.length;
        		}
        	}
        }
        while(boardlist.size() > maxboard){
        	int diff = boardlist.get(1)[0]-boardlist.get(0)[boardlist.get(0).length-1];
        	int begin = 0;
        	int end = 1;
        	for(int i = 0; i < boardlist.size()-1; i++){
        		int temp = boardlist.get(i+1)[0]-boardlist.get(i)[boardlist.get(i).length-1];
        		if(temp < diff){
        			diff = temp;
        			begin = i;
        			end = i+1;
        		}
        	}
        	int[] newarray = new int[boardlist.get(end).length + boardlist.get(begin).length];
        	System.arraycopy(boardlist.get(begin), 0, newarray, 0, boardlist.get(begin).length);
        	System.arraycopy(boardlist.get(end), 0, newarray, boardlist.get(begin).length, boardlist.get(end).length);
        	boardlist.remove(end);
        	boardlist.set(begin, newarray);
        }
        for(int i = 0; i < boardlist.size(); i++){
        	String s = "";
        	for(int j = 0; j < boardlist.get(i).length; j++){
        		s+= boardlist.get(i)[j] + " ";
        	}
        	System.out.println("array " + i + ": " + s);
        }
        int sum = 0;
        for(int i = 0; i < boardlist.size(); i++){
        	sum+= boardlist.get(i)[boardlist.get(i).length-1] - boardlist.get(i)[0]+1;
        }
        out.println(sum);
        out.close();
        System.exit(0);
    }
    
    public static void mergeSort(int[] array){
    	int size = array.length;
    	if(size < 2)
    		return;
    	int mid = size/2;
    	int lSize = mid;
    	int rSize = size - mid;
    	int[] left = new int[lSize];
    	int[] right = new int[rSize];
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
    
    public static void merge(int[] larr, int[] rarr, int[] arr){
    	int lSize = larr.length;
    	int rSize = rarr.length;
    	int i = 0, j = 0, k = 0;
    	while(i < lSize && j < rSize){
    		if(larr[i] <= rarr[j])
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