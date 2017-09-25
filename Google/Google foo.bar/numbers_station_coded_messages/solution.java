package com.google.challenges;

public class Answer {   
    public static int[] answer(int[] l, int t) { 
        int map[] = new int[10010];
        int psum[] = new int[l.length+1];
        int ans[] = new int[2];
        ans[0] = -1;
        ans[1] = -1;
        boolean found = false;
        map[0] = 1;
        for(int i = 0; i < l.length && !found; i++){
            psum[i+1] = psum[i]+l[i];
            if(psum[i+1]-t >= 0 && map[psum[i+1]-t] > 0){
                found = true;
                ans[0] = map[psum[i+1]-t]-1;
                ans[1] = i;
            }else{
                map[psum[i+1]] = i+2;
            }
        }
        return ans;
    } 
}