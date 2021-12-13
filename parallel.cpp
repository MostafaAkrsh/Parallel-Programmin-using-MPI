#include <stdio.h>
#include <iostream>
#include <math.h>
#include <mpi.h>
#include <limits>

using namespace std;

long double fact(long double n) {
   if ((n==0)||(n==1))
        return 1;
   else
        return n*fact(n-1);
}

int main() {

int rank,size;

//Initializes the MPI execution enviornment
MPI_Init(NULL,NULL);

//Get Process' rank
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

//Get the total number ranks in this communicator
MPI_Comm_size(MPI_COMM_WORLD,&size);

if (rank == 0){

//Get The value of x in radian and the number of summation
int iteration =0;
double x = 0;

cout<<"Enter The value of x & i";
cin>>x>>iteration;

double start_time= MPI_Wtime();

//Broadcast to all processes, the number of segments you want
MPI_Bcast(&x , 1, MPI_INT, 0, MPI_COMM_WORLD);
MPI_Bcast(&iteration , 1, MPI_INT, 0, MPI_COMM_WORLD);

//Define total value that gather all the values from the processes
long double total_value = 0;
long double local_value = 0;

int k = rank;

//Make the root process do the calculation
int task = 0;
while(k + task*size < iteration){
	
//Temp values for each i
int temp = k + task * size;
long double t = (pow((-1),temp) * pow(x,2*temp))/(fact(2*temp));

//add all the temp values to the process local value
local_value += t;

task++;
}

// Add all of value calculated by rank 0 to the total value
total_value += local_value;

//loop to receive all the local values from the processes
for(int i = 1; i < size ; i++)
{

// if process rank bigger than number of iteration don't receive data	
if( i >= iteration ) break;
 
MPI_Recv(&local_value,1,MPI_LONG_DOUBLE,i,MPI_ANY_TAG,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

total_value += local_value;
}

//end the timer and calculate the time
double end_time=MPI_Wtime();
double Timespent = end_time-start_time;

//print the results
cout<<"T:"<<Timespent<<endl;
cout.precision((iteration>33)?33:iteration);
cout<<endl<<"result="<<total_value<<endl;

}
//Other Processes
else
{
// get the rank value
int k = rank;
int x , iteration = 0;

// receive form ronk 0 x and iteration
MPI_Bcast(&x , 1, MPI_INT, 0, MPI_COMM_WORLD);
MPI_Bcast(&iteration , 1, MPI_INT, 0, MPI_COMM_WORLD);

// if rank is bigger than number of  iterations don't do anything
if(k > iteration);

// else do the algorithm
else {

long double local_value = 0;

int task = 0;

while(k + task*size < iteration){

//temp values for each i
int temp = k + task * size;
long double t = (pow((-1),temp) * pow(x,2*temp))/(fact(2*temp));

//add all the temp values to the process local value
local_value += t;

task++;
}

// Send process local value to the root
MPI_Send(&local_value,1,MPI_LONG_DOUBLE,0,0,MPI_COMM_WORLD);
}

}

//End the mpi program
MPI_Finalize();
return 0;
}
