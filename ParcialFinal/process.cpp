#include "process.h"


Process::Process()
{
	int fd_start, N_sensors;

	fd_start = open(name_start, O_WRONLY);

	read(fd, N_sensors, sizeof(int));
	printf("Numero de sensores leidos: %i\n", N_sensors);
}
