int compareAsc(const void *a, const void *b) {
    if(*(int*)a == *(int*)b) return 0;
    return *(int*)a - *(int*)b;
}
int solution(int A[], int N) {
    int lower[100000];
    int upper[100000];
    int pairs = 0;
    int intesect = 0;
    for(int i=0; i<N; i++) {
        lower[i] = i - A[i];
        upper[i] = i + A[i];
    }
    qsort(lower, N, sizeof(int), compareAsc);
    qsort(upper, N, sizeof(int), compareAsc);
    int j = 0;
    for(int i=0; i<N; i++) {
        //printf("%d: ", upper[i]);
        while(j < N && lower[j] <= upper[i]) {
            //printf("%d ", lower[j]);
            intesect++;
            j++;
        }
        intesect--;    // exclude itself
        pairs += intesect;
        //printf("- %d pairs found currently\n", pairs);
        if(pairs > 10000000) {
            return -1;
        }
    }
    return pairs;
}
