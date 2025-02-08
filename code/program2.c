#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

int main()
{
    key_t key;
    int shmem_id;
    size_t memsize = 1000;
    char *shmem_addr;
    int error;

    if (ferror(stdin) != 0)
    {
        fprintf(stderr, "%s", "Error with stdin: ");
        exit(1);
    }

    if (scanf("%d", &key) != 1)
    {
        fprintf(stderr, "%s", "Key is not correct, error in the first program: ");
        exit(2);
    }
    
    shmem_id = shmget(key, memsize, 0); 
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

    if (printf("%s\n", shmem_addr) < 0)
    {
        fprintf(stderr, "%s", "Error in function printf: ");
        shmctl(shmem_id, IPC_RMID, NULL);
        exit(3);
    }

    if (shmdt(shmem_addr) == -1)
    {
        perror("Error in function shmdt");
        error = errno;
        shmctl(shmem_id, IPC_RMID, NULL);
        exit(error);
    } 
    
    if (shmctl(shmem_id, IPC_RMID, NULL) == -1)
    {
        perror("Error in function scmctl");
        exit(errno);
    }
    exit(0);
}
