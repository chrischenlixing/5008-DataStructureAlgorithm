// name: <your name here>
// email: <your email here>

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if(n==0||n==1||n==2) return n;
    d[0] = 0;
    d[1] = 1;
    d[2] = 2;
    int i;
    for (i=3; i<= 20; i++){
        d[i] = d[i-1] + 2*d[i-2];
    }
    return d[n];

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
