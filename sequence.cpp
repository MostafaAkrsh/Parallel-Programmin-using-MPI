#include "iostream"
#include "math.h"
#include "mpi.h"

using namespace std;

long double fact(long double n) {
   if ((n==0)||(n==1))
        return 1;
   else
        return n*fact(n-1);
}

int main()
{


int i;
double x;

cout<<endl<<"Enter x and i (x in radian)";
cin>>x>>i;

double start_time= MPI_Wtime();

long double total_value = 0;

for(int j = 0; j < i ; j++)
{
long double local_value = (pow((-1),j) * pow(x,2*j))/(fact(2*j));

total_value += local_value;
}

double end_time=MPI_Wtime();

double Timespent = end_time-start_time;
cout <<"T="<< Timespent<<endl;

cout.precision((i>33)?33:i);
cout<<endl<<"result="<<total_value<<endl;

return 0;
}