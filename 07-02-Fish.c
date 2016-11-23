int stack[100001];
int top = -1;
int solution(int A[], int B[], int N) {
    int count = 0;
    for(int i=0; i<N; i++) {
        //printf("#%d size: %d, dir: %d -", i, A[i], B[i]);
        if(B[i] == 0) {
            while(top >= 0 && A[stack[top]] < A[i]) {
                //printf(" eat%d", stack[top]);
                top--;
            }
            if(top < 0) {
                count++;
                //printf(" alive!");
            }
            else {
                //printf(" eatenby%d", stack[top]);
            }
        }
        else if(B[i] == 1) {
            stack[++top] = i;
            //printf(" keep flowing");
        }
        //printf("\n");
    }
    //printf("%d fishes alive", count + top + 1);
    return count + (top+1);
}
