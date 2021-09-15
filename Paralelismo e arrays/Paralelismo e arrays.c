#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  printf("digite o valor para multiplicar:");
  int valor;
  scanf("%d",&valor);
  int id;
  int iCount;
  int shmid;
  int *array2;
  shmid=shmget(IPC_PRIVATE,20,IPC_CREAT| SHM_R | SHM_W);
  array2=(int *)shmat(shmid,0,0);
  int array[]={10,23,5,90,3,8,21,25,65};
  int i,metade,j;
  
  
  i = 0;
  j = 0;
  size_t n = sizeof(array)/sizeof(int);
  metade = n/2;

  int pid = fork();

  if (pid == 0) 
  {
    for(i = metade; i<n;i++)
    {
        array2[i] = array[i] * valor;
    }
  } 
  else 
  {
    for(j = 0; j<metade;j++)
    {
        array2[j] = array[j] * valor;
    }
  }
  printf("array final:");
  for(i = 0; i<n;i++)
  {
      printf("[%d] ",array2[i]);
  }
  printf("\n");
  return 0;
}
