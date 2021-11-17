#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Tartaruga(int n, double* global_result_p);

int main(int argc, char* argv[])
{
	int n;
	int thread_count;

	thread_count = strtol(argv[1], NULL, 10);
	scanf(&n);
      # pragma omp parallel num_threads(thread_count)
	Tartaruga(n, &global_result);

	printf("With n = %d,our estimate\n",n);
	printf("ln(n) = %d", global_result);
	return 0;
}

void Tartaruga (int n, double* global_result_p)
{
	int i,j,l;
	double my_result,h;
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
	
	my_result = 0;
	j = n/thread_count;
	k = my_rank*j;
	m = n%thread_count;

	if(my_rank == 1)
	{
	 l = 1;
	}
	else
	{
	 l = (my_rank-1)*j;
	}

	if(my_rank == thread_count )
	{
	 for(i = my_rank; i<k+m; i++)
	 {
	   h = (double)i
	   my_result = my_result+(1/h);
	 }
	}
	else
	{
	 for(i = my_rank; i<k; i++)
	 {
	   h = (double)i
	   my_result = my_result+(1/h);
	 }
	}
      # pragma omp critical
	*global_result_p += my_result;
}
