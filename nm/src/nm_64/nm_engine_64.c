/*
** EPITECH PROJECT, 2020
** nm
** File description:
** nm_engine_64
*/

#include "../../inc/my_nm.h"

// Print all section info (value type name)
static void print_all(Elf64_Shdr *sections, size_t i, void *buf)
{
    Elf64_Sym *symbol = NULL;
    char *to_print = NULL;
    char *str = NULL;

    str = (char *) sections[sections[i].sh_link].sh_offset;
    symbol = (Elf64_Sym *)(buf + sections[i].sh_offset);

    for (size_t j = 0; j < sections[i].sh_size / sections[i].sh_entsize; j++) {
        to_print = (char *) (uintptr_t)buf + (uintptr_t)str + symbol->st_name;
        if (strcmp("", to_print) != 0 && symbol->st_info != STT_FILE) {
            if (symbol->st_value == 0 && symbol->st_shndx == SHN_UNDEF)
                printf("                 ");
            else
                printf("%016lx ", symbol->st_value);
            printf("%c %s\n", get_type_64(symbol, sections), to_print);
        }
        symbol++;
    }
}

// Loop through all sections
static void loop_sections(char *filename, size_t file_size)
{
    int fd = open(filename, O_RDONLY);
    void *buf = mmap(0, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    Elf64_Ehdr *elf = (Elf64_Ehdr*)buf;
    Elf64_Shdr *sections = (Elf64_Shdr *)(buf + elf->e_shoff);

    for (size_t i = 0; i < elf->e_shnum; i++)
        if (sections[i].sh_type == SHT_SYMTAB)
            print_all(sections, i, buf);
}

// Engine for Nm (64 edition)
int nm_engine_64(char *filename)
{
    struct stat s;

    if (stat(filename, &s) != 0) {
        perror("stat");
        return (84);
    }
    loop_sections(filename, s.st_size);
    return (0);
}