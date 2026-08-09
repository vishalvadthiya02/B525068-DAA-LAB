#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a)-(*(int*)b);
}

void merge(int a[],int n1,int b[],int n2,int c[])
{
    int i=0,j=0,k=0;

    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
            c[k++]=a[i++];
        else
            c[k++]=b[j++];
    }

    while(i<n1)
        c[k++]=a[i++];

    while(j<n2)
        c[k++]=b[j++];
}

int main()
{
    FILE *fp=fopen("method1.dat","w");

    if(fp==NULL)
    {
        printf("File Error\n");
        return 0;
    }

    srand((unsigned)time(NULL));

    for(int k=2;k<=10;k++)
    {
        int n=1000;

        int **arr=(int**)malloc(k*sizeof(int*));

        for(int i=0;i<k;i++)
        {
            arr[i]=(int*)malloc(n*sizeof(int));

            for(int j=0;j<n;j++)
                arr[i][j]=rand()%100000;

            qsort(arr[i],n,sizeof(int),cmp);
        }

        clock_t start=clock();

        for(int repeat=0;repeat<100;repeat++)
        {
            int *result=(int*)malloc(n*sizeof(int));

            for(int i=0;i<n;i++)
                result[i]=arr[0][i];

            int resultSize=n;

            for(int i=1;i<k;i++)
            {
                int *temp=(int*)malloc((resultSize+n)*sizeof(int));

                merge(result,resultSize,arr[i],n,temp);

                free(result);
                result=temp;
                resultSize+=n;
            }

            free(result);
        }

        clock_t end=clock();

        double t=(double)(end-start)/(CLOCKS_PER_SEC*100);

        fprintf(fp,"%d %lf\n",k,t);

        printf("k=%d Time=%lf\n",k,t);

        for(int i=0;i<k;i++)
            free(arr[i]);

        free(arr);
    }

    fclose(fp);

    printf("\nData saved to method1.dat\n");
    printf("Worst Case: O(n*k^2)\n");

    return 0;
}