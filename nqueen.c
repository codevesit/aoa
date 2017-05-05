#include<stdio.h>
int x[100];

void nqueen(int k,int n)
{
    int i,z,w;
    for(i=1;i<=n;i++)
    {
        if (place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                printf("\nSolution:\n");
                printf("1\t2\t3\t4\n");
                for(z=1;z<=n;z++)
                {
                    for(w=1;w<=n;w++)
                    {
                        if(w==x[z])
                            printf("Q\t");
                        else
                            printf(".\t");
                    }
                    printf("\n");
                }
            }
            else
                nqueen(k+1,n);
        }
    }
}
int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if ((x[j]==i) || (abs(x[j]-i)==abs(j-k)))
        {
            return 0;
        }
    }
     return 1;
}
void main()
{
    int n;
    printf("Enter the number of Queens: ");
    scanf("%d",&n);
    printf("Possible solutions are:");
    nqueen(1,n);
}
