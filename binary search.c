#include<stdio.h>

int binary(int a[],int low,int high, int val)
{
    int mid;
   if(high==low)
   {
       if(val==a[low])
            return low;
       else
            return (-1);
   }
   else
   {
       mid=(high+low)/2;
       if(val==a[mid])
            return mid;
       else if(val<a[mid])
            return binary(a,low,mid-1,val);
       else if(val>a[mid])
            return binary(a,mid+1,high,val);
   }
}

void insertion_sort(int a[],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)
        {
               a[j+1]=a[j];
        }
        a[j+1]=temp;

    }
}

void main()
{
    int a[100],mid,low,high,n,i,val,index;
    printf("\nEnter number of elements\n");
    scanf("%d",&n);
    printf("\nEnter elements of array\n");
    for(i=0;i<n;i++)
    {
            scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
    printf("\nEnter value to search\n");
    scanf("%d",&val);
    low=0;
    high=n-1;
    index=binary(a,low,high,val);
    if(index==(-1))
        printf("\nValue not found!\n");
    else
        printf("\nValue found at %d\n",(index+1));
}
