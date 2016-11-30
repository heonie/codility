#define MAX(X, Y) (((X)>(Y))?(X):(Y))
int solution(int A[], int N) {
    int B[100000] = {0, };
    int C[100000] = {0, };
    for(int i=1; i<N-1; i++) {
        B[i] = MAX(B[i-1]+A[i], 0);
    }
    for(int i=N-2; 0<i; i--) {
        C[i] = MAX(C[i+1]+A[i], 0);
    }
    int max = 0;
    for(int i=1; i<N-1; i++) {  // i is Y
        max = MAX(max, B[i-1]+C[i+1]);
    }
    return max;
}
