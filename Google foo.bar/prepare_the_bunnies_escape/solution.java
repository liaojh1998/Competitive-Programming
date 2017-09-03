package com.google.challenges;

import java.util.*;

public class Answer {   
    public static int answer(int[][] maze) { 
        //At most 2*w*h states?
        int y[] = {1, 0, -1, 0};
        int x[] = {0, 1, 0, -1};
        int h = maze.length, w = maze[0].length;
        int sp[][][] = new int[2][h][w];
        sp[0][0][0] = 1;
        Queue<tuple> q = new LinkedList<tuple>();
        q.add(new tuple(0, 0, 0));
        while(!q.isEmpty()){
            tuple temp = q.poll();
            int s = temp.a, cy = temp.b, cx = temp.c;
            for(int i = 0; i < 4; i++){
                int ny = cy+y[i], nx = cx+x[i];
                if(ny < h && ny >= 0 && nx < w && nx >= 0)
                    if(s == 1 && maze[ny][nx] != 1 && ((sp[0][ny][nx] != 0 && sp[0][ny][nx] > sp[1][cy][cx]+1) || (sp[0][ny][nx] == 0 && (sp[1][ny][nx] == 0 || sp[1][ny][nx] > sp[1][cy][cx]+1)))){
                        sp[1][ny][nx] = sp[1][cy][cx]+1;
                        q.add(new tuple(1, ny, nx));
                    }else if(s == 0){
                        if(maze[ny][nx] == 1 && (sp[1][ny][nx] == 0 || sp[1][ny][nx] > sp[0][cy][cx]+1)){
                            sp[1][ny][nx] = sp[0][cy][cx]+1;
                            q.add(new tuple(1, ny, nx));
                        }else if(maze[ny][nx] == 0 && (sp[0][ny][nx] == 0 || sp[0][ny][nx] > sp[0][cy][cx]+1)){
                            sp[0][ny][nx] = sp[0][cy][cx]+1;
                            q.add(new tuple(0, ny, nx));
                        }
                    }
            }
        }
        int ans = h*w;
        if(sp[0][h-1][w-1] != 0 && sp[0][h-1][w-1] < ans)
            ans = sp[0][h-1][w-1];
        if(sp[1][h-1][w-1] != 0 && sp[1][h-1][w-1] < ans)
            ans = sp[1][h-1][w-1]; 
        return ans;
    } 
    private static class tuple{
        int a, b, c;
        tuple(int a, int b, int c){
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }
}