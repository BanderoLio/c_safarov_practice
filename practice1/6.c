#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define INF 100000007

int count(int n) {
    int dp[n + 1];
    for (int i = 0; i <= n; ++i) 
        dp[i] = INF;
    dp[0] = 0;
    for (int i = 2; i <= n; ++i) {
        if (dp[i - 2] < dp[i])
            dp[i] = dp[i - 2];
        if (i - 3 >= 0 && dp[i - 3] < dp[i])
            dp[i] = dp[i - 3];
        if (i - 4 >= 0 && dp[i - 4] < dp[i])
            dp[i] = dp[i - 4];
        if (dp[i] != INF)
            dp[i] += 1;
    }
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    int res = count(n);
    if (res == INF) {
        printf("Not possible");
    }
    else {
        printf("Possible with minimum of %d ships", res);
    }
}
