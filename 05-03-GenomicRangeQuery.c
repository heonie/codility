// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int getFactor(char c) {
    if(c == 'A') return 1;
    if(c == 'C') return 2;
    if(c == 'G') return 3;
    if(c == 'T') return 4;
    return -1;
}

struct Results solution(char *S, int P[], int Q[], int M) {
    struct Results result;
    int cA[100000] = {0, };
    int cC[100000] = {0, };
    int cG[100000] = {0, };
    //int cT[100000] = {0, };
    int N = strlen(S);
    for(int i=0; i<N; i++) {
        cA[i] = (i==0 ? 0 : cA[i-1]) + (S[i] == 'A' ? 1 : 0);
        cC[i] = (i==0 ? 0 : cC[i-1]) + (S[i] == 'C' ? 1 : 0);
        cG[i] = (i==0 ? 0 : cG[i-1]) + (S[i] == 'G' ? 1 : 0);
        //cT[i] = (i==0 ? 0 : cT[i-1]) + (S[i] == 'T' ? 1 : 0);
    }
    
    result.A = (int *)malloc(sizeof(int) * M);
    result.M = M;
    
    for(int i=0; i<M; i++) {
        if((P[i]<=0 && cA[Q[i]] > 0) || (P[i] > 0 && cA[Q[i]] - cA[P[i]-1] > 0)) result.A[i] = 1;
        else if((P[i]<=0 && cC[Q[i]] > 0) || (P[i] > 0 && cC[Q[i]] - cC[P[i]-1] > 0)) result.A[i] = 2;
        else if((P[i]<=0 && cG[Q[i]] > 0) || (P[i] > 0 && cG[Q[i]] - cG[P[i]-1] > 0)) result.A[i] = 3;
        else result.A[i] = 4;
    }
    
    return result;
}
