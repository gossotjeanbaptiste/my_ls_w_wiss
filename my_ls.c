/*
** EPITECH PROJECT, 2024
** collab
** File description:
** my_ls
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "test.h"

int stat(const char *path, struct stat *buf);

// int main(struct stat stats)
// {
//     struct tm dt;

//     dt = *(gmtime(&stats.st_ctime));
//     printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, dt.tm_hour, dt.tm_min, dt.tm_sec);
//     return 0;
// }