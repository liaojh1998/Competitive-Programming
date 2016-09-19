/*
ID: liaojh11
LANG: JAVA
TASK: namenum
*/

import java.util.*;
import java.io.*;

public class namenum {
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new FileReader("namenum.in"));
		BufferedReader din = new BufferedReader(new FileReader("dict.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"namenum.out")), true);
		
		ArrayList<cow> dict = new ArrayList<cow>();
		int index = 0;
		while(din.ready()){
			dict.add(new cow(din.readLine()));
		}
		
		String name = in.readLine();
		ArrayList<String> namelist = new ArrayList<String>();
		
		for(int i = 0; i < dict.size(); i++){
			if(name.equals(dict.get(i).getNum())){
				namelist.add(dict.get(i).getName());
			}
		}
		
		if(namelist.size() > 0){
			for(int i = 0; i < namelist.size(); i++){
				out.println(namelist.get(i));
			}
			System.exit(0);
		}
		
		out.println("NONE");
		System.exit(0);
	}
}

class cow {
	private String number = "";
	private String name;
	public cow(String n){
		name = n;
		for(int i = 0; i < n.length(); i++){
			switch(name.charAt(i)){
				case 'A': number+= "2"; break;
				case 'B': number+= "2"; break;
				case 'C': number+= "2"; break;
				case 'D': number+= "3"; break;
				case 'E': number+= "3"; break;
				case 'F': number+= "3"; break;
				case 'G': number+= "4"; break;
				case 'H': number+= "4"; break;
				case 'I': number+= "4"; break;
				case 'J': number+= "5"; break;
				case 'K': number+= "5"; break;
				case 'L': number+= "5"; break;
				case 'M': number+= "6"; break;
				case 'N': number+= "6"; break;
				case 'O': number+= "6"; break;
				case 'P': number+= "7"; break;
				case 'R': number+= "7"; break;
				case 'S': number+= "7"; break;
				case 'T': number+= "8"; break;
				case 'U': number+= "8"; break;
				case 'V': number+= "8"; break;
				case 'W': number+= "9"; break;
				case 'X': number+= "9"; break;
				case 'Y': number+= "9"; break;
			}
		}
	}
	public String getNum(){
		return number;
	}
	public String getName(){
		return name;
	}
}