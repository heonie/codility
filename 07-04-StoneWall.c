int solution(int H[], int N) {
    int stack[100001];
    int top = -1;
    int count = 0;
    
    for(int i=0; i<N; i++) {
        if(top >= 0 && stack[top] == H[i]) {
            // pass
        }
        else {
            while(top >= 0 && stack[top] > H[i]) {
                top--;  // higher wall could not be reused.
            }
            if(top != -1 && stack[top] == H[i]) {
                // reuse
            }
            else {
                // smaller than this. use new block for this height.
                count++;
                stack[++top] = H[i];
            }
        }
    }
    return count;
}
