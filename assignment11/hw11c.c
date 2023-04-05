// name: <your name here>
// email: <your email here>

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if(n==0||n==1||n==2) return n;
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;
    int i, j;
    for (i = 3; i <= 20; i++) {
        d[i] = 3 * d[i-2];
        for (j = 4; j <= i; j += 2) {
            d[i] += 2 * d[i-j];
        }
    }

    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
