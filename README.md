# Parallel-Programmin-using-MPI
Calculate the value of cos(x) by taylor expansion method using parallel programming techniques using MPI<br/>

![](equation.png)

## Steps to run the codes
Program should run on UBUNTU OS <br/>
1- Start UBUNTU <br/>
2- install mpich package on ubuntu <br/>
   run this command  `sudo apt-get install -y mpich` <br/>
3- Compile the two .cpp files <br/>
   `mpic++ -o sequence sequence.cpp` <br/>
   `mpic++ -o parallel parallel.cpp` <br/>
4- Run The output files (N -> number of processes) <br/>
   `mpirun -np (N) ./sequence` <br/>
   `mpirun -np (N) ./parallel` <br/>
5- Enter the value of x(in radian) and i <br/>
6- Get the results  

![](graph.png)
