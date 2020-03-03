/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/


#include "../inc/my_nm.h"

bool check_format(char *filename)
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
    if (av[1])
        nm_engine(av[1]);
    else
        nm_engine("a.out");
    return (0);
}