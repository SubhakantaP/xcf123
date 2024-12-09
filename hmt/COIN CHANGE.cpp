#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX_COINS 100

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[MAX_COINS];
    srand(time(0));

    printf("Randomly generated coin denominations: ");
    for (int i = 0; i < n; i++) {
        coins[i] = (rand() % 20) + 1; 
        printf("%d ", coins[i]);
    }
    printf("\n");

    printf("Enter the amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if (result == -1) {
        printf("It's not possible to make the amount with the given denominations.\n");
    } else {
        printf("Minimum number of coins required: %d\n", result);
    }

    return 0;
}




#include <stdio.h>
#include <limits.h>

#define MAX_COINS 100

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = (dp[i] < dp[i - coins[j]] + 1) ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[MAX_COINS];
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if (result == -1) {
        printf("It's not possible to make the amount with the given denominations.\n");
    } else {
        printf("Minimum number of coins required: %d\n", result);
    }

    return 0;
}

