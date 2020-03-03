/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "../inc/my_objdump.h"

// Check if the file is elf
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

// Check wich exec is needed (32/64)
bool is_32(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    if (elf.e_ident[4] == ELFCLASS32) {
        fclose(fd);
        return (true);
    }
    fclose(fd);
    return (false);
}

// Exec 32 or 64 objdump
void wich_exec(char *filename)
{
    if (is_32(filename) == true)
        objdump_engine_32(filename);
    else
        objdump_engine_64(filename);
}

// Execute objdump
void exec_with_args(char **av)
{
    if (av[2])
        for (size_t i = 1; av[i]; i++)
            wich_exec(av[i]);
    else if (av[1])
        wich_exec(av[1]);
    else
        wich_exec("a.out");
}

int main(int ac, char **av)
{
    (void)ac;
    if (av[1] && check_format(av[1]) == false) {
        fprintf(stderr, "objdump: %s: File format not recognized\n", av[1]);
        return (84);
    }
    exec_with_args(av);
    return (0);
}