#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

const char *name_start = "/tmp/exam_3_start";
const char *name_sensor = "/tmp/exam_3_data_";

#define SIZE 4
void* read_pipe(void *param);


typedef struct {
	int i;
    double x;
    double y;
    double z;
} arg_thread;

int main(int argc, char const *argv[])
{
	int fd_start;
	char Arr1[SIZE];

	printf("Abriendo: %s\n", name_start);
	fd_start = open(name_start, O_RDONLY);
	printf("Fd: %i\n", fd_start);
	read(fd_start, Arr1, SIZE);
	int N_sensores = Arr1[0];
	printf("Numero de sensores leidos: %i\n", N_sensores);


	pthread_t threads[N_sensores];
	pthread_attr_t attr[N_sensores];
	arg_thread data[N_sensores];

	for(int i=0; i<N_sensores; i++){
	data[i].i = i;
	pthread_attr_init(&attr[i]);
	pthread_create(&threads[i], &attr[i], read_pipe, &data[i]);
	}

	for(int i=0; i<N_sensores; i++){
		pthread_join(threads[i], NULL);
	}
	return 0;
}

void* read_pipe(void *data){
	int i = ((arg_thread*)data)->i;
	int fd;
	double Read[3];
	char name[50];

	sprintf(name, "%s%i", name_sensor, i);
	printf("[%i] Abriendo: %s\n", i, name);
	

	printf("[%i] Hilo creado\n", i);
	sleep(1);

	while(1){
	fd = open(name, O_RDONLY);
	read(fd, Read, 3*sizeof(double));
	((arg_thread*)data)->x = Read[0];
	((arg_thread*)data)->y = Read[1];
	((arg_thread*)data)->z = Read[2];
	printf("[%i] X: %lf, Y: %lf, Z: %lf\n", i, ((arg_thread*)data)->x , ((arg_thread*)data)->y, ((arg_thread*)data)->z);
	close(fd);
	}
	
}