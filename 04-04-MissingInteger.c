int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int count[1000001] = {0, };
    for(int i=0; i<N; i++) {
        if(A[i] > 0) {
            count[A[i]]++;
        }
    }
    int n = 1;
    while(count[n] > 0) {
        n++;
    }
    return n;
}
