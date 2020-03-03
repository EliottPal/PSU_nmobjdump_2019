/*
** EPITECH PROJECT, 2020
** nm
** File description:
** nm_engine
*/

#include "../inc/my_nm.h"

void nm_engine(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);

    fclose(fd);
}