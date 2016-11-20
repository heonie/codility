int compare(const void *a, const void *b) {
    if(*(int*)a < *(int*)b) {
        return -1;
    }
    else if(*(int*)a > *(int*)b) {
        return 1;
    }
    else {
        return 0;
    }
}
int solution(int A[], int N) {
    qsort(A, N, sizeof(int), compare);
    return A[N-1] * A[N-2] * A[N-3];
}
