/*Algorithm OrderGrowth

1. Take list of functions.
2. Convert each function into its asymptotic form.
3. Remove constants and lower-order terms.
4. Compare growth rates:
      1/n
      log n
      sqrt(n)
      n
      n log n
      n²
      n³
      2ⁿ
5. Arrange functions from smallest to largest.
6. Print the order.
End  */

#include <stdio.h>

int main()
{
    printf("Increasing Order of Growth:\n");

    printf("1/n\n");
    printf("log2(n)\n");
    printf("sqrt(n)\n");
    printf("0.5n\n");
    printf("2 + 6n\n");
    printf("100n\n");
    printf("nlog2(n)\n");
    printf("32nlog2(n)\n");
    printf("50n^2 - 324\n");
    printf("n^3\n");
    printf("2^n\n");

    return 0;
}

/*Best Case   : O(1)
Average Case: O(1)
Worst Case  : O(1)

Space Complexity : O(1)*/