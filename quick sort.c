#include<stdio.h>

void quicksort(int a[],int beg,int end)
{
    int pivot;
    if(beg<end)
    {
        pivot=partition(a,beg,end);
        quicksort(a,beg,pivot);
        quicksort(a,pivot+1,end);
    }
}

void partition(int a[],int beg,int end)
{
    int pivot,temp;
    pivot=beg;
    while(beg<end)
    {
        while(a[pivot]<a[end] && end>pivot)
        {
            end--;
        }
        if(end>pivot)
        {
            temp=a[pivot];
            a[pivot]=a[end];
            a[end]=temp;
            pivot=end;
        }
        while(a[pivot]>a[beg] && beg<pivot)
        {
            beg++;
        }
        if(beg<pivot)
        {
            temp=a[pivot];
            a[pivot]=a[beg];
            a[beg]=temp;
            pivot=beg;
        }
    }
    return pivot;
}

void main()
{
    int a[20],i,pivot,n;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    printf("Enter elements\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    quicksort(a,0,n);
    printf("Sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}
