#include<stdio.h>

void print(float a[][4], int n)
{
    int i,j;
    for(i=0;i<=3;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%.2f\t",a[j][i]);
        }
        printf("\n");
    }
}

void swap(float a[][4], int n)
{
    int i;
    float temp;
    for(i=0;i<3;i++)
    {
        temp=a[n][i];
        a[n][i]=a[n-1][i];
        a[n-1][i]=temp;
    }
}

void insertion_sort(float a[][4],int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        //temp=a[i];
        j=i;
        while(j>0 && a[j-1][2]<a[j][2])
        {
            swap(a,j);
            j=j-1;
        }
        //a[j]=temp;
    }
}

void main()
{
    int i,j=0,n;
    float a[50][4],w,profit;
    printf("Enter number of terms :");
    scanf("%d",&n);
    printf("Enter the weight of sack\n");
    scanf("%f",&w);
    printf("Enter profit of elements :\n");
    for(i=0;i<n;i++)
    {
        printf("%d : ",i+1);
        scanf("%f",&a[i][0]);
    }
    printf("Enter weight of elements :\n");
    for(i=0;i<n;i++)
    {
        printf("%d : ",i+1);
        scanf("%f",&a[i][1]);
    }
    for(i=0;i<n;i++)
    {
        a[i][2]=a[i][0]/a[i][1];
    }
    insertion_sort(a,n);
    while(w>0&&j<n)
    {
        if(a[j][1]<=w)
        {
            w=w-a[j][1];
            a[j][3]=1;
        }
        else if(a[j][1]>w)
        {
            a[j][3]=w/a[j][1];
            w=0;
        }
        j++;
    }
    while(j<n)
    {
        a[j][3]=0;
        j++;
    }
    for(i=0;i<n;i++)
    {
        profit+=a[i][0]*a[i][3];
    }
    print(a,n);
    printf("Profit is %f",profit);
}
