#include <stdio.h>
#include "inject.h"
#include <unistd.h>

#define T_RD
/*#define T_RDWR*/
/*#define T_WR*/
int main() {

    // Make the file
    int i;
    char *src = "/data/local/tmp/test.txt";
    char *dest = "/data/local/tmp/test1.txt";
    printf("Return: %ld\n", ext4_cowcopy(src, dest));
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "Current working dir: %s\n", cwd);
    else
        perror("getcwd() error");
       
    // Open the file     
    FILE *fp;    
#ifdef T_RD
    fp = fopen(dest,"r");
#elif defined T_RDWR
    fp = fopen(dest, "rw");
#elif defined T_WR
    fp = fopen(dest, "w");
#endif
    if(fp == NULL)
        printf("dest did not open\n");
    else 
    {
        printf("file opened\n");
        fclose(fp);    // Close
    }
            
    return 0;
}
