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

## Results and Observation
Results show that the Sequence code is faster than the parallel code in small i <br/>
And this happened due to the overhead of the communication between the processes<br/>
<br/>
And this overhead increases if we increase parallelism (the number of processes)<br/>
<br/>
The problem is simple and done very quickly so that the parallelism of this code makes overheads as the communication between processes and sending the data between them takes long time compared to the operation it should do.<br/>

The Parallelism has advantage in case of complex problems that take long time in sequence programming so the overhead of communication of the processes is very tiny compared to the operation that every process do.<br/>

The speedup hits the hardware boundary at processes more than 4 because the computer which runs the code has only 4 cores in its processor.<br/>

So if we want to speed up more we must add more cores.
