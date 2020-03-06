/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/


#include "../inc/my_nm.h"

// Check wich exec is needed (32/64)
static void wich_exec(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    if (elf.e_ident[4] == ELFCLASS32) {
        fclose(fd);
        nm_engine_32(filename);
        return;
    }
    else {
        fclose(fd);
        manage_errors(filename);
        nm_engine_64(filename);
    }
    return;
}

// Execute objdump
static void exec_with_args(int ac, char **av)
{
    if (ac > 2)
    for (size_t i = 1; av[i]; i++) {
        manage_errors(av[i]);
        wich_exec(av[i]);
    }
    else if (ac == 2) {
        manage_errors(av[1]);
        wich_exec(av[1]);
    }
    else {
        manage_errors("a.out");
        wich_exec("a.out");
    }
}

int main(int ac, char **av)
{
    (void)ac;
    exec_with_args(ac, av);
    return (0);
}