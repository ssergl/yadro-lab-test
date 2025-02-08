#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
    key_t key;
    int shmem_id;
    size_t memsize = 1000;
    char *shmem_addr;
    char *string = "Hello, world!";
    int error;

    key = ftok("file.txt", 'A');
    if (key == -1)
    {
        perror("Error in function ftok");
        exit(errno);
    }

    shmem_id = shmget(key, memsize, IPC_CREAT | S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP); 
    if (shmem_id == -1)
    {
        perror("Error in function shmget");
        exit(errno);
    }
    
    shmem_addr = (char*)shmat(shmem_id, NULL, 0);
    if (shmem_addr == (char *)(-1))
    {
        perror("Error in function shmat");
        error = errno;
        shmctl(shmem_id, IPC_RMID, NULL);
        exit(error);
    }

    if (memcpy(shmem_addr, string, sizeof(string[0]) * strlen(string)) == NULL)
    {
        fprintf(stderr, "%s", "Error in function memcpy: ");
        shmctl(shmem_id, IPC_RMID, NULL);
        exit(1);
    }
    
    if (shmdt(shmem_addr) == -1)
    {
        perror("Error in function shmdt");
        error = errno;
        shmctl(shmem_id, IPC_RMID, NULL);
        exit(error);
    }

    if (printf("%d", key) < 0)
    {
        fprintf(stderr, "%s", "Error in function printf: ");
        shmctl(shmem_id, IPC_RMID, NULL);
        exit(2);
    }
    exit(0);
}
