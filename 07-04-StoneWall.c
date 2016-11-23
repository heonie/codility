// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int getBlocks(int H[], int left, int right) {
    int minH = 1000000001;
    printf("getBlocks %d~%d\n", left, right);
    if(left == right) {
        printf("\t1 blocks\n");
        return 1;
    }
    for(int i=left; i<=right; i++) {
        if(H[i] < minH) {
            minH = H[i];
        }
    }
    printf("\tMinimum Height: %d\n", minH);
    int count = 0;
    if(minH > 0) {
        count = 1;
    }
    int from = -1;
    int i = left;
    while(i<=right) {
        if(H[i] > minH && from < 0) {
            from = i;
        }
        else if(H[i] == minH && from >= 0) {
            count += getBlocks(H, from, i-1);
            from = -1;
        }
        else if(i == right && from >= 0) {
            count += getBlocks(H, from, i);
            from = -1;
        }
        i++;
    }
    printf("\t%d blocks\n", count);
    return count;
}

int solution(int H[], int N) {
    // write your code in C99 (gcc 4.8.2)
    return getBlocks(H, 0, N-1);
}
