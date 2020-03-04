/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** main
*/

#include "../inc/my_objdump.h"

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

// Manage errors
static void manage_errors(char *file)
{
    struct stat buf;

    stat(file, &buf);
    if (S_ISDIR(buf.st_mode) == true) {
        fprintf(stderr, "my_objdump: Warning: '%s' is a directory\n", file);
        exit(84);
    }
    if (access(file, F_OK) == -1) {
        fprintf(stderr, "my_objdump: '%s': No such file\n", file);
        exit(84);
    }
    if (check_format(file) == false) {
        fprintf(stderr, "my_objdump: %s: File format not recognized\n", file);
        exit(84);
    }
}

// Check wich exec is needed (32/64)
static void wich_exec(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    if (elf.e_ident[4] == ELFCLASS32) {
        fclose(fd);
        objdump_engine_32(filename);
        return;
    }
    else {
        fclose(fd);
        manage_errors(filename);
        objdump_engine_64(filename);
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