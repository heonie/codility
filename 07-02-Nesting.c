int stack[1000001];
int top = -1;
int solution(char *S) {
    while(*S) {
        if(*S == '(') {
            stack[++top] = *S;
        }
        else if(*S == ')') {
            if(top < 0) {
                return 0;
            }
            top--;
        }
        S++;
    }
    return top == -1 ? 1 : 0;
}
