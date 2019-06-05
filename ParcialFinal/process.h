#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>



#define SIZE 4

class Process
{
public:
    static void main();
    Process();

private:
    static void* read_pipe(void *data);
};

#endif // PROCESS_H
