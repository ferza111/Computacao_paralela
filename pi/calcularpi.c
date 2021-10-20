#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int n = 1000;
double sum = 0.0;
int thread_count;

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *thread_sum(void *rank) 
{
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n/thread_count; 
    long long my_first_i = my_n*my_rank; 
    long long my_last_i = my_first_i+my_n;
    if (my_first_i % 2 == 0)
    {
        factor = 1.0;
    }
    else
    {
        factor = -1.0;
    }
    for(i=my_first_i;i<my_last_i; i++, factor = -factor)
    {
        sum += factor/(2*i+1);
    }
    return NULL;
}

int main()
{
    int p;
	pthread_t thread_id;
	thread_count++;
	pthread_create(&thread_id, NULL, thread_sum, NULL);
	pthread_join(thread_id, NULL);

	printf("%f",4.0*sum);
	exit(0);