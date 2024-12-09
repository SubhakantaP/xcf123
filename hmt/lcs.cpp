#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LCS(char *X, char *Y, int m, int n) {
    int **L = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++)
        L[i] = (int *)malloc((n + 1) * sizeof(int));
    
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = (L[i - 1][j] > L[i][j - 1]) ? L[i - 1][j] : L[i][j - 1];
        }
    }

    int index = L[m][n];
    
    char *lcs = (char *)malloc((index + 1) * sizeof(char));
    lcs[index] = '\0';  

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; 
            i--;
            j--;
            index--;  
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("LCS of %s and %s is %s\n", X, Y, lcs);

    for (int i = 0; i <= m; i++)
        free(L[i]);
    free(L);
    free(lcs);
}

int main() {
    char X[] = "NIST";
    char Y[] = "UNIVERSY";
    int m = strlen(X);
    int n = strlen(Y);
    LCS(X, Y, m, n);
    return 0;
}

