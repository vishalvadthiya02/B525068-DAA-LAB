/*
Method 2 : Pairwise Merge of K Sorted Arrays
Worst Case Time Complexity : O(k*n*log k)

This implementation repeatedly merges adjacent pairs of sorted arrays.
After each round, the number of arrays is approximately halved.
Execution times are written to method2.dat.
*/
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
    FILE *fp=fopen("method2.dat","w");

    if(fp==NULL)
    {
        printf("File Error\n");
        return 0;
    }

    srand((unsigned)time(NULL));

    for(int k=2;k<=10;k++)
    {
        int n=1000;

        int **arr=malloc(k*sizeof(int*));
        int *size=malloc(k*sizeof(int));

        for(int i=0;i<k;i++)
        {
            arr[i]=malloc(n*sizeof(int));
            size[i]=n;

            for(int j=0;j<n;j++)
                arr[i][j]=rand()%100000;

            qsort(arr[i],n,sizeof(int),cmp);
        }

        int current=k;
 clock_t start=clock();

for(int repeat=0;repeat<100;repeat++)
{
    int **a=(int**)malloc(k*sizeof(int*));
    int *s=(int*)malloc(k*sizeof(int));

    for(int i=0;i<k;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        s[i]=n;

        for(int j=0;j<n;j++)
            a[i][j]=arr[i][j];
    }

    int current=k;

    while(current>1)
    {
        int next=(current+1)/2;
        int **newArr=(int**)malloc(next*sizeof(int*));
        int *newSize=(int*)malloc(next*sizeof(int));

        for(int i=0,p=0;i<current;i+=2,p++)
        {
            if(i+1<current)
            {
                newSize[p]=s[i]+s[i+1];
                newArr[p]=malloc(newSize[p]*sizeof(int));

                merge(a[i],s[i],a[i+1],s[i+1],newArr[p]);

                free(a[i]);
                free(a[i+1]);
            }
            else
            {
                newArr[p]=a[i];
                newSize[p]=s[i];
            }
        }

        free(a);
        free(s);

        a=newArr;
        s=newSize;
        current=next;
    }

    free(a[0]);
    free(a);
    free(s);
}

clock_t end=clock();

double t=(double)(end-start)/(CLOCKS_PER_SEC*100);
        fprintf(fp,"%d %lf\n",k,t);
        printf("k=%d Time=%lf\n",k,t);

        free(arr[0]);
        free(arr);
        free(size);
    }

    fclose(fp);

    printf("\nData saved to method2.dat\n");
    printf("Worst Case Time Complexity: O(n*k*log k)\n");

    return 0;
}
 