int stack[200001];
int top = -1;
int solution(char *S) {
    while(*S) {
        if(*S == '(' || *S == '[' || *S == '{') {
            stack[++top] = *S;
        }
        else {
            if( top < 0
                || (*S == ')' && stack[top] != '(')
                || (*S == '}' && stack[top] != '{')
                || (*S == ']' && stack[top] != '[') ) {
                return 0;
            }
            top--;
        }
        S++;
    }
    return top == -1 ? 1 : 0;
}
