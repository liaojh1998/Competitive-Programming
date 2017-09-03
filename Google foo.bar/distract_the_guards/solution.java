package com.google.challenges;

import java.util.*;

public class Answer {   
    public static int answer(int[] banana_list) { 
        /*
        int mat[][] = new int[banana_list.length][banana_list.length];
        for(int i = 0; i < banana_list.length; i++)
            for(int j = i; j < banana_list.length; j++)
                mat[i][j] = mat[j][i] = check(banana_list[i], banana_list[j]); */

        /* The check is correct, the dp is absolutely wrong where dp[j][k-1] does not combine with dp[k+1][i-1] to produce dp[j][i].
        Problem is modeled as maximum matching, thus require either use of Hopcroft-Karp or any max flow algorithm.
        I was wrong, no max flow or Hopcroft-Karp will help out because the graph is a general graph, not a bipartite graph.
        Therefore, refer to Edmonds' algorithm for maximum matching in a general graph, O(V^3) algorithm. */

        /* int dp[][] = new int[banana_list.length][banana_list.length];
        for(int i = 0; i < banana_list.length; i++){
            dp[i][i] = mat[i][i];
            for(int j = i-1; j >= 0; j--){
                dp[j][i] = dp[j][i-1] + dp[i][i];
                if(i - j == 1){
                    if(dp[j][i] > mat[j][i])
                        dp[j][i] = mat[j][i];
                }else{
                    if(dp[j][i] > mat[j][i] + dp[j+1][i-1])
                        dp[j][i] = mat[j][i] + dp[j+1][i-1];
                    if(dp[j][i] > mat[i-1][i] + dp[j][i-2])
                        dp[j][i] = mat[i-1][i] + dp[j][i-2];
                    for(int k = j+1; k < i-1; k++)
                        if(dp[j][i] > dp[j][k-1] + mat[k][i] + dp[k+1][i-1])
                            dp[j][i] = dp[j][k-1] + mat[k][i] + dp[k+1][i-1];
                }
            }
        }
        return dp[0][banana_list.length-1];*/
        ArrayList<Integer> adjlist[] = new ArrayList[banana_list.length];
        for(int i = 0; i < banana_list.length; i++)
            adjlist[i] = new ArrayList<Integer>();
        for(int i = 0; i < banana_list.length; i++)
            for(int j = i; j < banana_list.length; j++)
                if(check(banana_list[i], banana_list[j])){
                    adjlist[i].add(j);
                    adjlist[j].add(i);
                }
        return banana_list.length-blossom(adjlist);
    } 
    private static boolean check(int a, int b){
        int div = gcd(a, b);
        a /= div;
        b /= div;
        int sum = a+b;
        return ((sum & (sum-1)) != 0);
    }
    private static int gcd(int a, int b){
        int t;
        while(b > 0){
            t = a%b;
            a = b;
            b = t;
        }
        return a;
    }
    private static int blossom(ArrayList<Integer>[] adjlist){
        int size = adjlist.length;
        int match[] = new int[size];
        int unmatch[] = new int[size];
        Arrays.fill(match, -1);
        //Search and augment
        for(int i = 0; i < size; i++){
            if(match[i] == -1){
                int v = augmentPath(match, unmatch, adjlist, i);
                while(v != -1){
                    int nextv = match[unmatch[v]];
                    match[v] = unmatch[v];
                    match[unmatch[v]] = v;
                    v = nextv;
                }
            }
        }
        //Count matched
        int matched = 0;
        for(int i = 0; i < size; i++)
            if(match[i] != -1)
                matched++;
        return matched;
    }
    private static int augmentPath(int[] match, int[] unmatch, ArrayList<Integer>[] adjlist, int s){
        int size = adjlist.length;
        int q[] = new int[size], qi = 0, qsize = 0;
        boolean queued[] = new boolean[size];
        boolean mark[] = new boolean[size];
        Arrays.fill(unmatch, -1);
        int group[] = new int[size];
        for(int i = 0; i < size; i++)
            group[i] = i;
        queued[s] = true;
        q[qsize++] = s;
        //Attempts to augment paths starting from s and reconstructs unmatched array
        //Polls matched nodes and exposed nodes until another exposed node has been found
        while(qi < qsize){
            int u = q[qi++];
            for(int v : adjlist[u]){
                if(group[v] != group[u] && match[v] != u){
                    //Not in same blossoms and unrepeated search (remove for a bipartite graph, because in bipartite, no blossom exists)
                    if(v == s || match[v] != -1 && unmatch[match[v]] != -1){
                        //Found blossom
                        int lca = LCA(u, v, unmatch, match, group);
                        //Combine blossoms
                        Arrays.fill(mark, false);
                        int start = u, end = v;
                        while(group[end] != lca){
                            mark[group[end]] = mark[match[group[end]]] = true;
                            unmatch[end] = start;
                            start = match[end];
                            end = unmatch[start];
                        }
                        start = v;
                        end = u;
                        while(group[end] != lca){
                            mark[group[end]] = mark[match[group[end]]] = true;
                            unmatch[end] = start;
                            start = match[end];
                            end = unmatch[start];
                        }
                        //Queue combined blossoms and contracts them
                        //This works because all nodes on the blossom are assumed to be matched,
                        //and augmenting them when there's 2 exposed node always give a valid increase in match count.
                        for(int i = 0; i < size; i++){
                            if(mark[group[i]]){
                                group[i] = lca;
                                if(!queued[i]){
                                    q[qsize++] = i;
                                    queued[i] = true;
                                }
                            }
                        }
                    }else if(unmatch[v] == -1){
                        //Found unmarked node
                        unmatch[v] = u;
                        if(match[v] == -1)
                            return v; //Found exposed node
                        q[qsize++] = match[v];
                        queued[match[v]] = true;
                    }
                }
            }
        }
        return -1;
    }
    //Fast LCA in skipping blossoms after contracting them
    private static int LCA(int a, int b, int[] unmatch, int[] match, int[] group){
        int size = unmatch.length;
        boolean has[] = new boolean[size];
        has[group[a]] = true;
        while(match[group[a]] != -1){
            a = unmatch[match[group[a]]];
            has[group[a]] = true;
        }
        while(match[group[b]] != -1 && !has[group[b]])
            b = unmatch[match[group[b]]];
        return b;
    }
}