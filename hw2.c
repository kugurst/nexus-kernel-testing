#include <stdio.h>
#include "inject.h"
#include <unistd.h>

int main() {
    int i;
    char *src = "sdcard/Download/";
    char *dest = "/sdcard/Download/dest.txt";
    printf("Return: %ld\n", ext4_cowcopy(src, dest));
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        fprintf(stdout, "Current working dir: %s\n", cwd);
    else
        perror("getcwd() error");
    return 0;
}
