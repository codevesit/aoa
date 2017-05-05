#include<stdio.h>

void tour(int a[][50], int r, int n)
{
    int i,j,k;
    for(i=0;i<n;i=i+r)
    {
        for(j=i;j<i+r/2;j++)
        {
            for(k=0;k<r/2;k++)
            {
                a[j+r/2][k+r/2]=a[j][k];
            }
        }
        for(j=i+r/2;j<i+r;j++)
        {
            for(k=0;k<r/2;k++)
            {
                a[j-r/2][k+r/2]=a[j][k];
            }
        }
    }
}

void main()
{
    int n,a[50][50],i,j,r=2;
    printf("Enter number of players\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        a[i][0]=i+1;
    }
    while(r<=n)
    {
        tour(a,r,n);
        r=r*2;
    }

    printf("Tournament table :\n");
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            printf("Players\t");
        }
        else
        {
                printf("Day %d\t",i);
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
