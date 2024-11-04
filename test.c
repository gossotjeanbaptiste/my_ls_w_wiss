/*
** EPITECH PROJECT, 2024
** collab
** File description:
** test
*/

/**
 * C program to find file permission, size, creation and last modification date of 
 * a given file.
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

void printFileProperties(struct stat stats);

int main(int argc, char *argv[])
{
    struct stat stats;

    if (argc != 2) {
        my_printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // stat() returns 0 on successful operation,
    // otherwise returns -1 if unable to get file properties.
    if (stat(argv[1], &stats) == 0) {
        printFileProperties(stats);
    } else {
        my_printf("Unable to get file properties.\n");
        my_printf("Please check whether '%s' file exists.\n", argv[1]);
    }

    return 0;
}

/**
 * Function to print file properties.
 */
void printFileProperties(struct stat stats)
{
    struct tm dt;

    // File permissions
    my_printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        my_printf("read ");
    if (stats.st_mode & W_OK)
        my_printf("write ");
    if (stats.st_mode & X_OK)
        my_printf("execute");

    // File size
    my_printf("\nFile size: %d", stats.st_size);

    // Get file creation time in seconds and 
    // convert seconds to date and time format
    dt = *(gmtime(&stats.st_ctime));
    my_printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    my_printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
}
