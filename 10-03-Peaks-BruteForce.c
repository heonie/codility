int hasTrue(int A[], int N) {
    for(int i=0; i<N; i++) {
        if(A[i]) return 1;
    }
    return 0;
}

int solution(int A[], int N) {
    int peak[100001] = {0, };
    int minSize = 0;
    //printf("PEAK: 0");
    for(int i=1; i<N-1; i++) {
        if(A[i-1] < A[i] && A[i] > A[i+1]) {
            peak[i] = 1;
            if(minSize == 0) {
                minSize = i+1;
            }
        }
        //printf(" %d", peak[i]);
    }
    //printf(" 0\n");
    int maxBlockSize = 2;
    for(int size=minSize; size<=N; size++) {
        if(N % size != 0) {
            continue;
        }
        //printf("Attempted divide with size: %d,", size);
        int canDivide = 1;
        for(int block=0; block*size<N; block++) {
            int hasPeak = hasTrue(&peak[block*size], size);
            if(!hasPeak) {
                canDivide = 0;
                break;
            }
        }
        //printf("%s\n", canDivide ? "O" : "X");
        if(canDivide) {
            maxBlockSize = size;
            break;
        }
    }
    return (int)(N / maxBlockSize);
}
