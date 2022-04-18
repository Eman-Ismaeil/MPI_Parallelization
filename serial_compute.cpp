

#include <stdio.h>
#include <math.h>
#include <time.h>

long double factorial(long double n)
{
    if (n == 0)
        return 1;
    else
        return(n * factorial(n - 1));
}

int main()
{
    double x;
    long double k;
    printf("Enter the value of the angle x in rad to calculate the cosine fn and then the value of upepr limit k:\n");
    scanf_s("%lf %Lf", &x, &k);

    clock_t t;
    t = clock();

    long double result = 0;

    for (long double i = 0; i < k; i++) {
        long double fact = factorial(2 * i);
        result += (pow(-1, i) *(long double) pow(x, (2 * i))) / fact;
    }

    printf("Result of cosine x is %Lf \n", result);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds

    printf("Time taken is %lf seconds to execute \n", time_taken);


}
