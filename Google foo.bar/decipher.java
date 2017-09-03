import java.util.*;
import java.lang.*;
import java.io.*;
import javax.xml.bind.DatatypeConverter;

public class decipher{
	public static void main (String[] args) throws IOException{
		Scanner in = new Scanner(System.in);
		System.out.println("Please enter your private message:");
		String msg = in.nextLine();
		System.out.println("Please enter your username:");
		String name = in.nextLine();
		byte[] bytes = DatatypeConverter.parseBase64Binary(msg);
		String pass = name;
		for (int i = 0; i < bytes.length; i++) {
			bytes[i] ^= (byte)pass.charAt(i % pass.length());
			System.out.print((char)bytes[i]);
		}
		System.out.println();
		in.close();
	}
}