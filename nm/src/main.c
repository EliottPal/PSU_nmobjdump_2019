/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <string.h>
#include <elf.h>
#include "../inc/my_nm.h"

bool check_format(char *filename)
{
    Elf64_Ehdr elf;
    FILE* file = fopen(filename, "r");

    if (file) {
        fread(&elf, 1, sizeof(elf), file);
        if (memcmp(elf.e_ident, ELFMAG, SELFMAG) == 0) {
            fclose(file);
            return (true);
        }
        fclose(file);
        return (false);
    }
    return (false);
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 2) {
        fprintf(stderr, "nm: No such file\n");
        return (84);
    }
    if (check_format(av[1]) == false) {
        fprintf(stderr, "nm: %s: File format not recognized\n", av[1]);
        return (84);
    }
    nm_engine(av[1]);
    return (0);
}