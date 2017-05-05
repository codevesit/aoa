#include<stdio.h>
#include<string.h>

void main()
{
    int i,j,n1,n2,lcs[10][10];
    char a[10],b[10];
    printf("Enter first and second strings:\n");
    gets(a);
    gets(b);
    n1=strlen(a);
    n2=strlen(b);
    for(i=0;i<=n2;i++)
    {
        for(j=0;j<=n1;j++)
        {
            if(i==0 || j==0)
            lcs[i][j]=0;
        }
    }
    for(i=0;i<=n2;i++)
    {
        for(j=0;j<=n1;j++)
        {
            if(b[i]==a[j])
            {
                lcs[i+1][j+1]=lcs[i][j]+1;
            }
            else
            {
                if(lcs[i+1][j]>lcs[i][j+1])
                    lcs[i+1][j+1]=lcs[i+1][j];
                else
                    lcs[i+1][j+1]=lcs[i][j+1];
            }
        }
    }
    printf("\t");
    for(i=0;i<=n1;i++)
        printf("\t%c",a[i]);
    printf("\n");
    for(i=0;i<=n2;i++)
    {
        if(i!=0)
            printf("%c\t",b[i-1]);
        else
            printf("\t");
        for(j=0;j<=n1;j++)
        {
            printf("%d\t",lcs[i][j]);
        }
        printf("\n");
    }

    printf("Longest common substring is %d",lcs[i-1][j-1]);
}
