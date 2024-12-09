#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

void insertionSort(Item items[], int n) 
{
    int i;
    for (i = 1; i < n; i++) {
        Item key = items[i];
        int j = i - 1;
        while (j >= 0 && items[j].ratio < key.ratio) {
            items[j + 1] = items[j];
            j--;
        }
        items[j + 1] = key;
    }
}


int randomValue(int min, int max) {
    return rand() % (max - min + 1) + min;
}


void fractionalKnapsack(Item items[], int n, int capacity) 
{
    int i;
    float totalWeight = 0;
    float totalProfit = 0;

    printf("\nItems selected:\n");
    for (i = 0; i < n && totalWeight < capacity; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            
            printf("Item %d - Weight: %d, Profit: %d (taken fully)\n", i + 1, items[i].weight, items[i].profit);
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            int remainingCapacity = capacity - totalWeight;
            float fraction = (float)remainingCapacity / items[i].weight;
            printf("Item %d - Weight: %d, Profit: %d (taken %.2f fraction)\n", i + 1, items[i].weight, items[i].profit, fraction);
            totalProfit += items[i].profit * fraction;
            totalWeight += items[i].weight * fraction;
            break;
        }
    }
    printf("\nTotal Weight in Knapsack: %.2f\n", totalWeight);
    printf("Total Profit: %.2f\n", totalProfit);
}

int main() {
    int N,i, M, minRange, maxRange;
    printf("Enter the number of items (N): ");
    scanf("%d", &N);
    printf("Enter the capacity of the knapsack (M): ");
    scanf("%d", &M);
    printf("Enter the minimum range for weight and profit: ");
    scanf("%d", &minRange);
    printf("Enter the maximum range for weight and profit: ");
    scanf("%d", &maxRange);

    Item items[N];
    srand(time(0)); 

    for (i = 0; i < N; i++) {
        items[i].weight = randomValue(minRange, maxRange);
        items[i].profit = randomValue(minRange, maxRange);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    insertionSort(items, N);

    printf("\nGenerated items (weight, profit, ratio):\n");
    for (i = 0; i < N; i++) {
        printf("Item %d - Weight: %d, Profit: %d, Ratio: %.2f\n", i + 1, items[i].weight, items[i].profit, items[i].ratio);
    }

    fractionalKnapsack(items, N, M);

    return 0;
}

#include <stdio.h>
#include<stdlib.h>

void printarr(float a[], int n)
{
    int i;
  for( i=0;i<n;i++)
    printf("%f  ",a[i]);
  printf("\n");
}

float knapsack(int m,float n,float p[], float w[])
{
  int i,j;
  float max=0,x[100],s,k,temp,prot,weit;
  
  for(i=0;i<n;i++)
    x[i]=p[i]/w[i];

  printf("output of x array...\n");
  printarr(x,n);
    
  
  
  for(i=1;i<n;i++)
  {
    k=x[i];
    prot=p[i];
    weit=w[i];
    j=i-1; 
    while(j>=0 && x[j]<k)
    {
      x[j+1]=x[j];   
      p[j+1]=p[j];
      w[j+1]=w[j];
      j=j-1;
    }
    x[j+1]=k;
    p[j+1]=prot;
    w[j+1]=weit;
  }





  printf("output of x array...\n");
  printarr(x,n);
  
  printf("output of profit array...\n");
  printarr(p,n);

  printf("output of weight array...\n");
  printarr(w,n);  
  
  temp=m;
  for(i=0;i<n;i++)
  {
    if(w[i]>temp)
      break;
    max=max+(p[i]);
    temp =temp-w[i];
    printf("The details of knapsack %d :- 1*%f\n",i+1,p[i]);
  }

  if(i<=n-1)
  {
    s=(temp/w[i]);
    max=max+(s* p[i]);
    printf(" the details of knapsack %d :- %f*%f\n",i+1,s,p[i]);
  }
return max;
}

int main() 
{
  int m,n,i;
  float profit[50],weight[50],a=0;
  printf("enter the size M:-");
  scanf("%d",&m);
  printf("enter the no of objects:- ");
  scanf("%d",&n);
  
  printf("enter the profit of objects:- ");
  for( i=0;i<n;i++) 
  scanf("%f",&profit[i]);
  
  printf("enter the weight of objects:- ");
  for(i=0;i<n;i++)
  scanf("%f",&weight[i]);
  
  a=knapsack(m,n,profit,weight);
  
  printf("the maximum profit is %f ",a);
  return 0;
}
