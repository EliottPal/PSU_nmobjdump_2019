/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm_errors
*/

#include "../inc/my_nm.h"

// Check if the file is elf
static bool check_format(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    if (fd) {
        fread(&elf, 1, sizeof(elf), fd);
        if (memcmp(elf.e_ident, ELFMAG, SELFMAG) == 0) {
            fclose(fd);
            return (true);
        }
        fclose(fd);
        return (false);
    }
    return (false);
}

// Check if file is truncated
static bool is_truncated(char *filename, struct stat st)
{
    int fd = open(filename, O_RDONLY);
    void *buf = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    Elf64_Ehdr *elf = (Elf64_Ehdr*)buf;
    unsigned int size;

    if (elf->e_ident[4] == ELFCLASS64) {
        size = elf->e_shoff + (elf->e_shentsize * elf->e_shnum);
        if (size != st.st_size)
            return (true);
    }
    return (false);
}

// Manage errors
void manage_errors(char *file)
{
    struct stat st;

    stat(file, &st);
    if (S_ISDIR(st.st_mode) == true) {
        fprintf(stderr, "my_nm: Warning: '%s' is a directory\n", file);
        exit(84);
    }
    if (access(file, F_OK) == -1) {
        fprintf(stderr, "my_nm: '%s': No such file\n", file);
        exit(84);
    }
    if (check_format(file) == false) {
        fprintf(stderr, "my_nm: %s: file format not recognized\n", file);
        exit(84);
    }
    if (is_truncated(file, st) == true) {
        fprintf(stderr, "my_nm: %s: file truncated\n", file);
        exit(84);
    }
}