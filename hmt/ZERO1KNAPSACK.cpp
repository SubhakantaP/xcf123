#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100 

void knapsack(int N, int W[], int P[], int M) 
{
    int dp[N + 1][M + 1],i,w;

    for (i = 0; i <= N; i++) 
    {
        for (w = 0; w <= M; w++) 
        {
            if (i == 0 || w == 0) 
            {
                dp[i][w] = 0;
            } 
            else if (W[i - 1] <= w) 
            {
                dp[i][w] = dp[i - 1][w] > (P[i - 1] + dp[i - 1][w - W[i - 1]]) 
                           ? dp[i - 1][w] 
                           : (P[i - 1] + dp[i - 1][w - W[i - 1]]);
            } 
            else 
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nDP Table:\n");
    for (i = 0; i <= N; i++) 
    {
        for (w = 0; w <= M; w++) 
        {
            printf("%4d", dp[i][w]);
        }
        printf("\n");
    }

    printf("\nMaximum Profit: %d\n", dp[N][M]);
}

int main() 
{
    int N,max,min,i;
    int W[MAX], P[MAX];
    int sum_weights = 0, M;

    srand(time(0));

    printf("Enter the number of objects (N): ");
    scanf("%d", &N);
    printf("Enter Knapsack Capacity (M): ");
    scanf("%d",&M);
    printf("Enter the minimum range for weight and profit: ");
    scanf("%d", &min);
    printf("Enter the maximum range for weight and profit: ");
    scanf("%d", &max);


    printf("\nWeights and Profits:\n");
    for (i = 0; i < N; i++) 
    {
        W[i] = min + rand()%(max-min+1); 
        P[i] = min + rand()%(max-min+1); 
        sum_weights += W[i];
        printf("Object %d: Weight = %d, Profit = %d\n", i + 1, W[i], P[i]);
    }

    M = sum_weights / 2;
    printf("\nKnapsack Capacity (M): %d\n", M);

    knapsack(N, W, P, M);

    return 0;
}

#include <stdio.h>
#define MAX_OBJECTS 100
#define MAX_CAPACITY 100

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

void knapsack(int n, int c, int wt[], int pt[]) 
{
    int i,w;
    int dp[MAX_OBJECTS][MAX_CAPACITY] = {0};

    for (i = 1; i <= n; i++) 
    {
        for (w = 1; w <= c; w++) 
        
        {
            if (wt[i - 1] <= w) 
            {
                dp[i][w] = max(dp[i - 1][w], pt[i-1] + dp[i - 1][w - wt[i-1]]);
            } 
            else 
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nDP Table:\n");
    for (i = 0; i <=n; i++) 
    {
        for (w = 1; w <= c; w++) 
        {
            printf("%4d\t", dp[i][w]);
        }
        printf("\n");
    }
    printf("\n");

    printf("The maximum profit is: %d\n", dp[n][c]);
}

int main() {
    int n,i,c;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &c);
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int wt[MAX_OBJECTS], pt[MAX_OBJECTS];

    printf("Enter the weights of objects:\n ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter the profits of objects:\n ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &pt[i]);
    }

    knapsack(n, c, wt, pt);

    return 0;
}
