package com.google.challenges; 

import java.util.*;
import java.math.BigInteger;

public class Answer {   
    private static List<BigInteger> p, q;
    public static String answer(String str_n) { 
        //There was a problem known as Euler Sum on the Codechef Long Challenge in June 2017. It had the exact same sum idea of the beatty sequence.
        //I think this is where the inspiration for that problem came from.
        //I remember using
        //https://math.stackexchange.com/questions/2052179/how-to-find-sum-i-1n-left-lfloor-i-sqrt2-right-rfloor-a001951-a-beatty-s
        //for the Euler Sum and it ran 1/2 of the time limit.
        //If you wish to see that solution, feel free to visit the JUNE17 folder in my CodeChef folder.
        //And there were also solutions that were quicker:
        //http://people.math.sfu.ca/~vjungic/tbrown/tom-27.pdf
        //I'll try the quicker one this time, since it used almost no time at all.
        //Tested, actually ran so much faster.
        //Note: sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + 1/(2 + ...))))
        p = new ArrayList<BigInteger>();
        q = new ArrayList<BigInteger>();
        p.add(BigInteger.ONE);
        q.add(new BigInteger("2"));
        p.add(new BigInteger("2"));
        q.add(new BigInteger("5"));
        BigInteger TWO = new BigInteger("2");
        for(int i = 2; i <= 400; i++){
            p.add(TWO.multiply(p.get(i-1)).add(p.get(i-2)));
            q.add(TWO.multiply(q.get(i-1)).add(q.get(i-2)));
        }
        BigInteger n = new BigInteger(str_n);
        BigInteger ans = n.multiply(n.add(BigInteger.ONE)).divide(TWO);
        for(int i = p.size()-1; i >= 0; i--)
            if(q.get(i).compareTo(n) <= 0)
                ans = ans.add(sum(n.divide(q.get(i)), n = n.mod(q.get(i)), i));
        return ans.toString();
    } 
    private static BigInteger sum(BigInteger b, BigInteger m, int i){
        BigInteger pi = p.get(i), qi = q.get(i);
        BigInteger s = m.multiply(b).multiply(pi);
        if((i+1)%2 > 0)
            s = s.add(pi.multiply(qi).multiply(b).subtract(qi).add(pi).subtract(BigInteger.ONE).multiply(b).divide(new BigInteger("2")));
        else
            s = s.add(pi.multiply(qi).multiply(b).subtract(qi).add(pi).add(BigInteger.ONE).multiply(b).divide(new BigInteger("2")));
        return s;
    }
}