#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void Tartaruga(int n, double* global_result_p);

int main(int argc, char* argv[])
{
	double global_result = 0.0;
	int n;
	int thread_count;

	thread_count = strtol(argv[1], NULL, 10);
	printf("digite o valor de n: ");
	scanf("%d",&n);
      # pragma omp parallel num_threads(thread_count)
	Tartaruga(n, &global_result);

	printf("com n = %d\n",n);
	printf("ln(%d) = %f\n",n, global_result);
	return 0;
}

void Tartaruga (int n, double* global_result_p)
{
	int i,j,l,m,k;
	double my_result,h;
	int my_rank = omp_get_thread_num();
	int thread_count = omp_get_num_threads();
	
	my_result = 0;
	j = n/thread_count;
	if(my_rank == 0)
	{
		l = 1;
	}
	else
	{
		l = (my_rank)*j;
	}
	
	k = (my_rank+1)*j;
	m = n%thread_count;
	

	if(my_rank == thread_count-1)
	{
	 for(i = l; i<=k+m; i++)
	 {
	   h = (double)i
	   my_result = my_result+(1/h);
	 }
	}
	else
	{
	 for(i = l; i<k; i++)
	 {
	   h = (double)i
	   my_result = my_result+(1/h);
	 }
	}
      # pragma omp critical
	*global_result_p += my_result;
}
