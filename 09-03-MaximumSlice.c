// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");
#define MAX(X, Y) (((X)>(Y))?(X):(Y))

int solution(int A[], int N) {
    int max_ending_here = A[0];
    int max_so_far = A[0];
    for(int i=1; i<N; i++) {
        max_ending_here = MAX(max_ending_here+A[i], A[i]);
        max_so_far = MAX(max_so_far, max_ending_here);
    }
    return max_so_far;
}
