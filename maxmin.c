#include<stdio.h>
int max,min;

void maxmin(int a[],int i, int j)
{
    int max1,min1,mid;
    if(i==j)
        max=min=a[i];
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];
        }
    }
    else
    {
        mid = (i+j)/2;
        maxmin(a,i,mid);
        max1=max;
        min1=min;
        maxmin(a,mid+1,j);
        if(max<max1)
            max=max1;
        if(min>min1)
            min=min1;
    }
}

void main()
{
    int a[100],n,i;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    maxmin(a,0,n-1);
    printf("\nMax element is %d and Min element is %d",max,min);
    printf("\nSelect option\n1.Start new search for max & min\n2.Exit\n");
    scanf("%d",&op);
}
