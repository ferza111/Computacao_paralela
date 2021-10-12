#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int m = 6;
int n = 6;
int y[6];
int a[6][6];
int x[6] = {3};
int thread_count;

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *Pth_mat_vect(void *rank)
{
    long my_rank = (long) rank;
    int i, j; 
    int local_m = m/thread_count; 
    int my_first_row = my_rank*local_m; 
    int my_last_row = (my_rank+1)*local_m-1;
    for (i = my_first_row; i <= my_last_row; i++)
    {
        y[i] = 0.0;
        for (j = 0; j < n; j++)
        {
            y[i]+=a[i][j]*x[j];
        }
    }
    return NULL;
}

int main()
{
    int p;
    int l;
    int g;
    int h;
    int b;
    b = 2;
	pthread_t thread_id;
	
	for(g = 0; g<6;g++)
	{
	    x[g] = 3;
	    for(h = 0; h<6;h++)
	    {
	        a[g][h] = 2;
	        b++;
	    }
	}
	
	for(p = 0; p<6; p++)
	{
	    thread_count++;
	    pthread_create(&thread_id, NULL, Pth_mat_vect, NULL);
	    pthread_join(thread_id, NULL);
	}
	for(l = 0; l<6; l++)
	{
	    printf("[%d] ",y[l]);
	}
	exit(0);
}
