/*
ID: liaojh11
LANG: JAVA
TASK: sort3
*/
/*Type: Greedy
 *Solution: (As proposed from IOI '96) Have an unsorted and a sorted array,
 *			let us denote x:y as x in place of y in the sorted array. Find
 *			the minimum amount of x:y and y:x, which are numbers that can 
 *			be sorted by simply swapping each other. Then the leftover amo-
 *			unt of unsorted numbers are ones that will require swapping 2  
 *			times with 2 different values, such as 1 swap with 3 which then
 *			swaps with 2 to sort all. Denote amount of as A[x:y]. Thus, mi-
 *			nimum amount of sorting required is:
 *			min(A[1:2], A[2:1]) + (swapping 1 and 2 in place)
 *			min(A[1:3], A[3:1]) +
 *			min(A[2:3], A[3:2]) +
 *			2*abs(A[1:2] - A[2:1]) (the leftover amount will always be same
 *			for all differences in amounts, because they all require sorti-
 *			ng twice. Simply multiply 2 with leftover = total amount for 3-
 *			way swaps.)
 *
 *			For IOI's turns, make array of A[x:y] and A[y:x], the first few
 *			minimum of A[x:y] and A[y:x] will directly swap x and y, so pr-
 *			int those:
 *			A[2:1] will swap A[1:2]
 *			A[3:1] will swap A[1:3]
 *			A[3:2] will swap A[2:3]
 *			The indirect ones will be written in this order:
 *			A[2:1] will swap A[1:3]
 *			A[3:2] will swap A[1:3]
 *			then
 *			A[3:1] will swap A[1:2]
 *			A[2:3] will swap A[1:2]
 *
 *Shame on me for trying bubble sort O(N^2) when there is O(N) solution.*/

import java.util.*;
import java.io.*;

public class sort3 {
	private static int N;
	private static int[] sorted;
	private static int[] unsorted;
	private static int[] count;
	private static int[] misplace;
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("sort3.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("sort3.out")));
		N = Integer.parseInt(in.readLine());
		sorted = new int[N];
		unsorted = new int[N];
		count = new int[4]; //Count for amount of 1, 2, and 3 in the array
		misplace = new int[6]; //We'll define misplace as array to store A[1:2][2:1][1:3][3:1][2:3][3:2]
		
		//unsorted and sorted array
		for(int i = 0; i < N; i++){
			unsorted[i] = Integer.parseInt(in.readLine());
			count[unsorted[i]]++;
		}
		int index;
		for(index = 0; index < count[1]; index++){
			sorted[index] = 1;
		}
		for(index = index; index < count[1] + count[2]; index++){
			sorted[index] = 2;
		}
		for(index = index; index < count[1] + count[2] + count[3]; index++){
			sorted[index] = 3;
		}
		
		for(int i = 0; i < N; i++){
			if(unsorted[i] != sorted[i]){
				if(unsorted[i] == 1 && sorted[i] == 2) misplace[0]++;
				if(unsorted[i] == 2 && sorted[i] == 1) misplace[1]++;
				if(unsorted[i] == 1 && sorted[i] == 3) misplace[2]++;
				if(unsorted[i] == 3 && sorted[i] == 1) misplace[3]++;
				if(unsorted[i] == 2 && sorted[i] == 3) misplace[4]++;
				if(unsorted[i] == 3 && sorted[i] == 2) misplace[5]++;
			}
		}
		
		/*min(A[1:2], A[2:1]) +
		 *min(A[1:3], A[3:1]) +
		 *min(A[2:3], A[3:2]) +
		 *2*abs(A[1:2] - A[2:1]) */
		out.println(Math.min(misplace[0],misplace[1]) + Math.min(misplace[2],misplace[3]) + Math.min(misplace[4],misplace[5]) + 2*Math.abs(misplace[0] - misplace[1]));
		
		/*
		//for IOI '96
		int[] locate12 = new int[misplace[0]];
		int[] locate21 = new int[misplace[1]];
		int[] locate13 = new int[misplace[2]];
		int[] locate31 = new int[misplace[3]];
		int[] locate23 = new int[misplace[4]];
		int[] locate32 = new int[misplace[5]];
		int index12 = 0;
		int index21 = 0;
		int index13 = 0;
		int index31 = 0;
		int index23 = 0;
		int index32 = 0;
		for(int i = 0; i < N; i++){
			if(unsorted[i] != sorted[i]){
				if(unsorted[i] == 1 && sorted[i] == 2){
					locate12[index12] = i+1;
					index12++;
				}
				if(unsorted[i] == 2 && sorted[i] == 1){
					locate21[index21] = i+1;
					index21++;
				}
				if(unsorted[i] == 1 && sorted[i] == 3){
					locate13[index13] = i+1;
					index13++;
				}
				if(unsorted[i] == 3 && sorted[i] == 1){
					locate31[index31] = i+1;
					index31++;
				};
				if(unsorted[i] == 2 && sorted[i] == 3){
					locate23[index23] = i+1;
					index23++;
				};
				if(unsorted[i] == 3 && sorted[i] == 2){
					locate32[index32] = i+1;
					index32++;
				};
			}
		}
		//For direct swap
		int swap21;
		for(swap21 = 0; swap21 < Math.min(locate21.length, locate12.length); swap21++){
			out.println(locate21[swap21] + " " + locate12[swap21]);
		}
		int swap13;
		for(swap13 = 0; swap13 < Math.min(locate13.length, locate31.length); swap13++){
			out.println(locate31[swap13] + " " + locate13[swap13]);
		}
		int swap32;
		for(swap32 = 0; swap32 < Math.min(locate32.length, locate23.length); swap32++){
			out.println(locate32[swap32] + " " + locate23[swap32]);
		}
		//For indirect swap
		if(locate21.length > locate12.length){
			for(swap21 = swap21; swap21 < locate21.length; swap21++){
				out.println(locate21[swap21] + " " + locate13[swap13]);
				out.println(locate32[swap32] + " " + locate13[swap13]);
				swap13++;
				swap32++;
			}
		}
		if(locate21.length < locate12.length){
			for(swap21 = swap21; swap21 < locate12.length; swap21++){
				out.println(locate31[swap13] + " " + locate12[swap21]);
				out.println(locate23[swap32] + " " + locate12[swap21]);
				swap32++;
				swap13++;
			}
		}
		*/
		
		out.close();
		System.exit(0);
	}
}