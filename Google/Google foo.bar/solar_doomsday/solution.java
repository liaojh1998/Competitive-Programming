package com.google.challenges;

import java.util.*;

public class Answer {   
    public static int[] answer(int area) { 
        ArrayList<Integer> squares = new ArrayList<Integer>();
        while(area > 0){
            int side = (int)(Math.sqrt(area));
            int block = side*side;
            squares.add(block);
            area -= block;
        }
        int size = squares.size();
        int ans[] = new int[size];
        for(int i = 0; i < size; i++)
            ans[i] = squares.get(i);
        return ans;
    } 
}