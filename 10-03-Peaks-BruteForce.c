int hasTrue(int A[], int N) {
    for(int i=0; i<N; i++) {
        if(A[i]) return 1;
    }
    return 0;
}

int solution(int A[], int N) {
    int peak[100001] = {0, };
    for(int i=1; i<N-1; i++) {
        if(A[i-1] < A[i] && A[i] > A[i+1]) {
            peak[i] = 1;
        }
    }
    int maxBlockSize = 0;
    for(int size=1; size<=N; size++) {
        if(N % size != 0) {
            continue;
        }
        int canDivide = 1;
        for(int block=0; block*size<N; block++) {
            int hasPeak = hasTrue(&peak[block*size], size);
            if(!hasPeak) {
                canDivide = 0;
                break;
            }
        }
        if(canDivide) {
            maxBlockSize = size;
            break;
        }
    }
    if(maxBlockSize == 0) {
        return 0;
    }
    return (int)(N / maxBlockSize);
}
