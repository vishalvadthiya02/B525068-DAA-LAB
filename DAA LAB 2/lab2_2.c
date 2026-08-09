#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    while(i<=m && j<=r){
        if(a[i]<a[j]){
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=m)
        temp[k++]=a[i++];
    while(j<=r)
        temp[k++]=a[j++];
    for(i=l,k=0;i<=r;i++,k++)
        a[i]=temp[k];
}
void mergeSort(int a[],int l,int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
void merge3(int a[],int l,int m1,int m2,int r){
    int temp[r-l+1];
    int i=l,j=m1+1,k=m2+1,t=0;
    while(i<=m1 && j<=m2 && k<=r){
        if(a[i]<=a[j] && a[i]<=a[k])
            temp[t++] = a[i++];
        else if(a[j]<=a[i] && a[j]<=a[k])
            temp[t++] = a[j++];
        else
            temp[t++] = a[k++];
    }
    while(i<=m1 && j<=m2)
        temp[t++]=(a[i]<a[j])?a[i++]:a[j++];
    while(j<=m2 && k<=r)
        temp[t++]=(a[j]<a[k])?a[j++]:a[k++];
    while(i<=m1 && k<=r)
        temp[t++]=(a[i]<a[k])?a[i++]:a[k++];
    while(i<=m1)
        temp[t++]=a[i++];
    while(j<=m2)
        temp[t++]=a[j++];
    while(k<=r)
        temp[t++]=a[k++];
    for(i=l,t=0;i<=r;i++,t++)
        a[i]=temp[t];
}
void modifiedMergesort(int a[],int l,int r){
    if(l<r){
        int third = (r-l)/3;
        int m1 = l + third;
        int m2 = l + 2*third;
        modifiedMergesort(a,l,m1);
        modifiedMergesort(a,m1+1,m2);
        modifiedMergesort(a,m2+1,r);
        merge3(a,l,m1,m2,r);
    }
}
int main(){
    FILE *fp;
    fp = fopen("merge.dat", "w");
    if (fp == NULL){
        printf("Error creating file!\n");
        return 1;
    }
    srand(time(NULL));
    for (int n = 10000 ;n <= 100000; n += 10000){
        int *a = (int *)malloc(n * sizeof(int));
        int *b = (int *)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 100000;
            b[i] = a[i];
        }

        clock_t start, end;
        double mergeTime, modifiedTime;

        start = clock();
        for(int x=0;x<10;x++){
            mergeSort(a, 0, n - 1);
        }
        end = clock();
        mergeTime = (double)(end - start) / CLOCKS_PER_SEC/10;

        start = clock();
        for(int x=0;x<10;x++){
            modifiedMergesort(b, 0, n - 1);
        }
        end = clock();
        modifiedTime = (double)(end - start) / CLOCKS_PER_SEC/10;

        fprintf(fp, "%d %lf %lf\n", n, mergeTime, modifiedTime);

        printf("N = %d\tMerge = %lf\tModified = %lf\n",
               n, mergeTime, modifiedTime);

        free(a);
        free(b);
    }

    fclose(fp);

    printf("\nData saved to merge.dat\n");
    printf("Use the following commands in gnuplot:\n");
    printf("gnuplot\n");
    printf("plot \"merge.dat\" using 1:2 with linespoints title \"Merge Sort\",\\\n");
    printf("  \"merge.dat\"using 1:3 with linespoints title \"Modified merge Sort\"\n");
    return 0;
}