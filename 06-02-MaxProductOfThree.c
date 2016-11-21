int compare(const void *a, const void *b) {
    if(*(int*)a < *(int*)b) return -1;
    if(*(int*)a > *(int*)b) return 1;
    return 0;
}

int solution(int A[], int N) {
    qsort(A, N, sizeof(int), compare);
    if(A[0] * A[1] * A[N-1] > A[N-3] * A[N-2] * A[N-1]) {
        return A[0] * A[1] * A[N-1];
    }
    else {
        return A[N-3] * A[N-2] * A[N-1];
    }
}
