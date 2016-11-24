// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    int stack[100001];
    int top = -1;
    for(int i=0; i<N; i++) {
        stack[++top] = A[i];
        if(top >= 1 && stack[top-1] != stack[top]) {
            top -= 2;
        }
    }
    int candidate = -1;
    if(top < 0) {
        candidate = A[N-1];
    }
    else {
        candidate = stack[top];
    }
    int count = 0;
    for(int i=0; i<N; i++) {
        if(A[i] == candidate) {
            count++;
        }
    }
    if( count > N/(double)2 ) {
        for(int i=0; i<N; i++) {
            if(A[i] == candidate) {
                return i;
            }
        }
        return -1; // ???
    }
    else {
        return -1;
    }
}
