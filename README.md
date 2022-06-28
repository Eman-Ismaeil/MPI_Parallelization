# MPI_Parallelization
This is a C program that uses MPI parallelization to compute the value of cos(x) using the known formula: ∑(((−1)^k)*(x^2k))/((2k)!) where k is from 0 to ∞.
The upper value of i and the value of x are inputted from the user
The program makes the computation by dividing i equally among the processes, it uses n processes to do this computation, where n is provided as input by user. Then, it displays the computed value of cos(x). 
The value of cos(x) and the time taken by the program to compute it are displayed. 

## Requirements:

1-Install Visual Studio 2019

2-For serial computation code:
just run the code on the IDE

3-For MPI pararllelization code:
video link for installation of MPI and linking with Visual Studio: https://www.youtube.com/watch?v=BA_Mqi3a9HI

## Steps:

1-Download mpi sdks --> Microsoft MPI

2-Download MS-MPI v10.1.2 under the header of "MS-MPI Downloads" in Microsoft MPI website

3-Select the files "msmpisetup.exe" and "msmpisdk.msi"

4-Run the msmpisdk.msi and finish installation on your pc

5-Open Visual studio 2019

6-From project select project properties

7-In C/C++ section choose "General" and edit the "Additional Include Directories"

8-Select Local disk C>>Program Files (x86)>>Microsoft SDKs>> MPI>> Include folder>>Apply>>OK

9-Going back to the same bar which contains the "C/C++" section in point 8 -go to the "Linker" section and select "General" and edit the "Additional Library Directories"

10-Select Local disk C>>Program Files (x86)>>Microsoft SDKs>> MPI>>Lib folder>> x86 >>Apply>>OK

11-Still in the "Linker" section select "Input" and edit Additional dependencies and type "msmpi.lib"

12-You are able to build the code and run it using the cmd in the debug folder

13-Command used in cmd is:
mpiexec -n <no of processes>  filename.exe; where n is the number of processes entered by the user
e.g: mpiexec -n 5 MPI_parallel.exe

14-Angle x is inputed in rad where:
x in rad=((angle x in degrees* pi)/180)
