
#include <stdio.h>
#include <math.h>
#include "mpi.h"


long double factorial(long double n)
{
    if (n == 0)
        return 1;
    else
        return(n * factorial(n - 1));
}

long double cosine_calc(int start, int end, double x) {
    long double result=0;
    for (long double i = start; i < end; i++)
    {
        long double fact = (factorial((2 * i)));
        result +=(long double) (pow(-1, i) * (long double)pow(x, (2 * i))) / fact;
        
    }

    return result;
}

int main(int argc, char** argv)
{
    int comm_size,myrank;
    long double upper_limit_k; // counter
    double x;
    int n;
    int start = 0;
    

    long double time1, time2;
    long double time_diff;
    long double total_time;
    
 
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

   
    if (myrank == 0)
    {
        printf("Enter the upper limit to k : ");
        fflush(stdout);
        scanf_s("%Lf", &upper_limit_k);
        
        printf("Enter the value of the angle in rad x: "); //double datatype
        fflush(stdout);
        scanf_s("%lf", &x);
        
        for (int dest = 1; dest < comm_size; dest++) {
            MPI_Send(&upper_limit_k, 1, MPI_LONG_DOUBLE, dest, 0, MPI_COMM_WORLD); //tag is 0
            MPI_Send(&x, 1, MPI_DOUBLE, dest, 0, MPI_COMM_WORLD);
        }

    }

    else {
        MPI_Recv(&upper_limit_k, 1, MPI_LONG_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&x, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    }
    time1 = MPI_Wtime();

    long double local_k = upper_limit_k / comm_size;
    long double local_start = start + myrank * local_k;
    long double local_end = start + (myrank + 1) * local_k;

    long double local_sum = cosine_calc(local_start, local_end, x);
    long double total_sum=0;

    if (myrank != 0) {
        MPI_Send(&local_sum, 1, MPI_LONG_DOUBLE, 0, 0, MPI_COMM_WORLD);

    }
    else { //rank is 0
        total_sum = local_sum;
        for (int source = 1; source < comm_size; source++) {
            MPI_Recv(&local_sum, 1, MPI_LONG_DOUBLE, source, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total_sum += local_sum;
        }
    }
    time2 = MPI_Wtime();
    time_diff = time2 - time1;
    // Get the max time value from all processes to print
    MPI_Reduce(&time_diff, &total_time, 1, MPI_LONG_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);

    if (myrank == 0)
    {
        printf("result of cosine x is %Lf \n", total_sum);
        //printf("Total time to calculate the cosine function in parallel MPI is %Lf\n", time_diff);
        printf("Total time to calculate the cosine function in parallel MPI is %Lf\n", total_time);

    }
    
    MPI_Finalize();
}

//command used in the cmd to run the program
//mpiexec -n 5 MPI_parallel.exe