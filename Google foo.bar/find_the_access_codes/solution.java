package com.google.challenges;

public class Answer {   
    public static int answer(int[] l) { 
        //Is there a better solution than this? Like using sparse tables?
        int div[] = new int[l.length];
        int ans = 0;
        for(int i = 1; i < l.length; i++)
            for(int j = i-1; j >= 0; j--)
                if(l[i]%l[j] == 0){
                    ans += div[j];
                    div[i]++;
                }
        return ans;
    } 
}