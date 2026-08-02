/*TOH(n, Source, Auxiliary, Destination)

If n = 1
    Move disk from Source to Destination
Else
    TOH(n-1, Source, Destination, Auxiliary)
    Move nth disk
    TOH(n-1, Auxiliary, Source, Destination)*/

    #include <stdio.h>

void TOH(int n, char source,
         char auxiliary,
         char destination)
{
    if(n == 1)
    {
        printf("Move Disk 1 from %c to %c\n",
               source, destination);
        return;
    }

    TOH(n - 1, source,
        destination,
        auxiliary);

    printf("Move Disk %d from %c to %c\n",
           n, source, destination);

    TOH(n - 1, auxiliary,
        source,
        destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');

    return 0;
}
/*Best Case   : O(2^n)
Average Case: O(2^n)
Worst Case  : O(2^n)

Space       : O(n)*/