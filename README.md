# MPI_Parallelization
This is a C program that uses MPI parallelization to compute the value of cos(x) using the known formula: ∑(((−1)^k)*(x^2k))/((2k)!) where k is from 0 to ∞.
The upper value of i and the value of x are inputted from the user
The program makes the computation by dividing i equally among the processes, it uses n processes to do this computation, where n is provided as input by user. Then, it displays the computed value of cos(x). 
The value of cos(x) and the time taken by the program to compute it are displayed. 
