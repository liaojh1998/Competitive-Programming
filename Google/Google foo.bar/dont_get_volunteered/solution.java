package com.google.challenges;

import java.util.*;

public class Answer {   
    public static int answer(int src, int dest) { 
        //I'll just solve this in BFS for now
        //Will come back later for the mathematical solution
        int board[] = new int[64];
        int r[] = {-1, 1, 2, 2, 1, -1, -2, -2};
        int c[] = {2, 2, 1, -1, -2, -2, -1, 1};
        for(int i = 0; i < 64; i++)
            board[i] = 64;
        board[src] = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(src);
        while(!q.isEmpty()){
            int next = q.poll();
            int y = next/8, x = next%8;
            for(int i = 0; i < 8; i++){
                if(y+r[i] >= 0 && y+r[i] < 8 && x+c[i] >= 0 && x+c[i] < 8){
                    int num = (y+r[i])*8+x+c[i];
                    if(board[num] > board[next]+1){
                        board[num] = board[next]+1;
                        q.add(num);
                    }
                }
            }
        }
        return board[dest];
    } 
}