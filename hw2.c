#include <stdio.h>
#include "inject.h"
#include <unistd.h>

int main() {
    int i;
    char *src = "/data/local/tmp/test.txt";
    char *dest = "/data/local/tmp/test1.txt";
    printf("Return: %ld\n", ext4_cowcopy(src, dest));
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "Current working dir: %s\n", cwd);
    else
        perror("getcwd() error");
    return 0;
}
