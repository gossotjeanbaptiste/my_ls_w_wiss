/*
** EPITECH PROJECT, 2024
** collab
** File description:
** test
*/
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

char *my_strrchr(const char *str, int c)
{
    const char *last_occurrence = NULL;

    while (*str) {
        if (*str == (char)c) {
            last_occurrence = str;
        }
        str++;
    }
    return (char *)last_occurrence;
}

static void display_file_type(mode_t mode)
{
    if (S_ISREG(mode))
        my_printf("f\n");
    if (S_ISDIR(mode))
        my_printf("d\n");
    if (S_ISCHR(mode))
        my_printf("c\n");
    if (S_ISBLK(mode))
        my_printf("b\n");
    if (S_ISFIFO(mode))
        my_printf("p\n");
    if (S_ISLNK(mode))
        my_printf("l\n");
    if (S_ISSOCK(mode))
        my_printf("s\n");
}

static void display_device_info(mode_t mode, dev_t rdev)
{
    if (S_ISCHR(mode) || S_ISBLK(mode)) {
        my_printf("Minor: %d\n", minor(rdev));
        my_printf("Major: %d\n", major(rdev));
    } else {
        my_printf("Minor: N/A\n");
        my_printf("Major: N/A\n");
    }
}

static void display_all(const char *base_name, struct stat *stats)
{
    my_printf("Name: %s\n", base_name);
    my_printf("Type: ");
    display_file_type(stats->st_mode);
    my_printf("Inode: %d\n", stats->st_ino);
    my_printf("Hard Link: %d\n", stats->st_nlink);
    my_printf("Size: %d\n", stats->st_size);
    my_printf("Allocated space: %d\n", stats->st_blocks * 512);
    display_device_info(stats->st_mode, stats->st_rdev);
    my_printf("UID: %d\n", stats->st_uid);
    my_printf("GID: %d\n", stats->st_gid);
}

void display_properties(const char *filename, struct stat *stats)
{
    char temp[1024];
    size_t len;
    const char *base_name;

    my_strncpy(temp, filename, sizeof(temp) - 1);
    temp[sizeof(temp) - 1] = '\0';
    len = my_strlen(temp);
    if (len > 1 && temp[len - 1] == '/') {
        temp[len - 1] = '\0';
    }
    base_name = my_strrchr(temp, '/');
    if (base_name != NULL) {
        base_name++;
    } else {
        base_name = temp;
    }
    display_all(base_name, stats);
}

int main(int argc, char *argv[])
{
    struct stat stats;

    if (argc != 2) {
        my_printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }
    if (stat(argv[1], &stats) == 0) {
        display_properties(argv[1], &stats);
    } else {
        my_printf("File not found\n");
        return 84;
    }
    return 0;
}
