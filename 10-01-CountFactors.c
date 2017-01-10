int solution(int N) {
    int count = 0;
    for(int i=1; (long int)i*i<=N; i++) {
        if(N % i == 0) {
            if((long int)i*i == N) {
                count += 1;
            }
            else {
                count += 2;
            }
        }
    }
    return count;
}
