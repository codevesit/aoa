#include<stdio.h>

void insertion_sort(int a[],int n)
{
    int i,value,hole;
    for(i=1;i<n;i++)
    {
        value=a[i];
        hole=i;
        while(i>0 && a[hole-1]>value)
        {
            a[hole]=a[hole-1];
            hole=hole-1;
        }
        a[hole]=value;
    }
    printf("\nsorted array is :\t");
    for(i=0;i<n;i++)
    {
        printf("%d\n ",a[i]);
    }
}

void main()
{
    int a[10],i,n,j=100000,k=99999, b[10];
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements to sort\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
}
