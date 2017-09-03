package com.google.challenges;

import java.math.BigInteger;

public class Answer {   
    public static String answer(String M, String F) { 
        boolean impossible = false;
        BigInteger a = new BigInteger(M), b = new BigInteger(F), ans = new BigInteger("0");
        while(!impossible && !a.equals(BigInteger.ONE) && !b.equals(BigInteger.ONE)){
            if(a.compareTo(b) > 0){
                ans = ans.add(a.divide(b));
                if(a.mod(b).equals(BigInteger.ZERO))
                    impossible = true;
                else
                    a = a.mod(b);
            }else{
                ans = ans.add(b.divide(a));
                if(b.mod(a).equals(BigInteger.ZERO))
                    impossible = true;
                else
                    b = b.mod(a);
            }
        }
        if(a.compareTo(b) > 0)
            ans = ans.add(a.subtract(BigInteger.ONE));
        else
            ans = ans.add(b.subtract(BigInteger.ONE));
        return impossible ? "impossible" : ans.toString();
    } 
}