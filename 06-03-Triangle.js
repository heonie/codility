function solution(A) {
    // write your code in JavaScript (Node.js 6.4.0)
    A.sort(function (a, b) {
        if(a < b) return -1;
        if(a > b) return 1;
        return 0;
    });
    for(var i=0; i<A.length-2; i++) {
        if(A[i]+A[i+1]>A[i+2] && A[i+1]+A[i+2]>A[i] && A[i+2]+A[i]>A[i+1]) {
            return 1;
        }
    }
    return 0;
}
