package com.google.challenges;

public class Answer {   
    private static boolean mark[][];
    private static boolean take[];
    private static int num, tnum;
    public static int[][] answer(int num_buns, int num_required) {
        //Reduce problem to numbers of keys required such that
        //different num_required-1 bunnies combinations of num_buns would not have one key.
        int ans[][];
        tnum = num = nCr(num_buns, num_required-1);
        ans = new int[num_buns][num-nCr(num_buns-1, num_required-2)];
        mark = new boolean[num_buns][num];
        take = new boolean[num_buns];
        //It's not an efficient way of structuring, I just haven't found the pattern to directly output the keys yet.
        //I will probably, one day, if I'm really interested in this.
        if(num_required-1 > 0)
            for(int i = 0; i <= num_buns-num_required+1; i++){
                take[i] = true;
                recur(i+1, num_buns, num_required-2);
                take[i] = false;
            }
        for(int i = 0; i < num_buns; i++){
            int size = 0;
            for(int j = 0; j < num; j++)
                if(!mark[i][j])
                    ans[i][size++] = j;
        }
        return ans;
    } 
    private static void recur(int index, int n, int r){
        if(r == 0){
            tnum--;
            for(int i = 0; i < n; i++)
                if(take[i])
                    mark[i][tnum] = true;
            return;
        }
        for(int i = index; i <= n-r; i++){
            take[i] = true;
            recur(i+1, n, r-1);
            take[i] = false;
        }
    }
    private static int nCr(int n, int k){
        if(k < 0)
            return 0;
        //From n pick k
        int ans = 1;
        for(int i = 0; i < k; i++){
            ans = ans*(n-i)/(i+1);
        }
        return ans;
    }
}