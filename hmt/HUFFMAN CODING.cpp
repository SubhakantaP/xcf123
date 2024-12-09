#include<stdio.h>
#include<stdlib.h>
void bs(int *arr,int n)
{
    int i=0,j=0;
    int temp;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int i,n,j,*arr,m=0,t,s=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
    arr=(int*)malloc((n+1)*sizeof(int));
    printf("Now enter the frequencies:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
   
    for(i=0;i<n;i++)
    {
        s=s+arr[i];
    }
    arr[n]=s+1;
     bs(arr,n);
    printf("\n");
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<(n-i);j++)
        {
            printf("%d\t",arr[j]);
        }
        
        printf("\n");
        t=arr[n-i];
        arr[n-i]=arr[0]+arr[1];
        arr[0]=t;
        arr[1]=t;
        bs(arr,(n-i));

    }
    
    
}
