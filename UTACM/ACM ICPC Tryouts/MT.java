//Title: Movie Title
//Type: Just DO IT
import java.util.*;
import java.io.*;
public class MT {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int t = Integer.parseInt(s.nextLine());
        while(t-- > 0){
        	String input = s.nextLine();
        	if(input.split(" ").length > 1)
        		System.out.println(input + ": Age of Darkness");
        	else
        		System.out.println(input + " Returns");
        }
    }
}
