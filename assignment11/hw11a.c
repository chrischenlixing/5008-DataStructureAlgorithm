// name: <your name here>
// email: <your email here>

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if(n == 1) return 1;

    if (n == 2) return 2;

    if(d[n]!= 0) return d[n];

    return d[n] = dp(n-1) + dp(n-2);

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
