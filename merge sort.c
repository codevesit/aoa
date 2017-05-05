#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,temp[100];
    k=low;
    i=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=a[i];
        i++;
        k++;
    }
    while(j<=high)
    {
        temp[k]=a[j];
        j++;
        k++;
    }
    for(k=low;k<=high;k++)
    {
        a[k]=temp[k];
    }
}

void MergeSort(int a[],int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
    MergeSort(a,0,n-1);
    printf("\nsorted array is :\t");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
