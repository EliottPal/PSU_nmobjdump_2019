/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump_engine
*/

#include "../../inc/my_objdump.h"

static void print_header(char *filename)
{
    Elf32_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    printf("%s:\tfile format elf64-x86-64\n", filename);
    printf("architecture: %s, flags 0x%08x\n", get_archi_32(elf.e_machine), get_flags_int_32(elf.e_type));
    printf("%s\n", get_flags_str_32(elf.e_type));
    printf("start address 0x%016x\n\n", elf.e_entry);
}

int objdump_engine_32(char *filename)
{
    print_header(filename);
    return (0);
}