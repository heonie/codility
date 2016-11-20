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
    // write your code in C99 (gcc 4.8.2)
    int prev = -9999999, count = 0;
    qsort(A, N, sizeof(int), compare);
    for(int i=0; i<N; i++) {
        if(i==0 || prev != A[i]) {
            count ++;
        }
        prev = A[i];
    }
    return count;
}
