int solution(int N) {
    int ans = -1;
    for(int i=1; (long int)i*i<=N; i++) {
        if(N % i == 0) {
            ans = 2 * ((long int)i + (long int)N/i);
        }
    }
    return ans;
}
