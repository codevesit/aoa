#include<stdio.h>

void selection_sort(int a[],int n)
{
    int i,j,imin,temp;
    for(i=0;i<n;i++)
    {
        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
            {
                imin=j;
            }
        }
        temp=a[i];
        a[i]=a[imin];
        a[imin]=temp;
    }
    printf("\nsorted array is :\t");
    for(i=0;i<n;i++)
    {
        printf("%d\n ",a[i]);
    }
}

void main()
{
    int a[100],i,n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements to sort\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
}
