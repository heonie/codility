int solution(int A[], int N) {
    float min = 987654321;
    float tmp;
    int minIdx = -1;
    
    for(int i=0; i<N; i++) {
        // 2 elements
        if(i+1 < N) {
            tmp = (A[i]+A[i+1])/(float)2;
            if(min > tmp) {
                min = tmp;
                minIdx = i;
            }
        }
        // 3 elements
        if(i+2 < N) {
            tmp = (A[i]+A[i+1]+A[i+2])/(float)3;
            if(min > tmp) {
                min = tmp;
                minIdx = i;
            }
        }
    }
    return minIdx;
}
