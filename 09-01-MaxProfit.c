#define MAX(X, Y) (((X)>(Y))?(X):(Y))

int solution(int A[], int N) {
    int max_profit = 0;
    int max_slice = 0;
    int diff = 0;
    for(int i=1; i<N; i++) {
        diff = A[i]-A[i-1];
        max_slice = MAX(0, max_slice+diff);
        max_profit = MAX(max_profit, max_slice);
    }
    return max_profit;
}
