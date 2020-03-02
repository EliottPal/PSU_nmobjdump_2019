/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump_engine
*/

#include "../inc/my_objdump.h"

void objdump_engine(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);

    fclose(fd);

}