/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump_engine
*/

#include "../../inc/my_objdump.h"

// Print header (-f)
static void print_header(char *filename)
{
    Elf32_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    printf("%s:\tfile format elf32-x86-32\n", filename);
    printf("architecture: %s, flags 0x%08x\n",
        get_archi_32(elf.e_machine), get_flags_int_32(elf.e_type));
    printf("%s\n", get_flags_str_32(elf.e_type));
    printf("start address 0x%016x\n\n", elf.e_entry);
}

// Loop through all sections
static void loop_sections(char *filename, size_t file_size)
{
    int fd = open(filename, O_RDONLY);
    void *buf = mmap(0, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    Elf32_Ehdr *elf = (Elf32_Ehdr*)buf;
    Elf32_Shdr *sections = (Elf32_Shdr *)(buf + elf->e_shoff);
    Elf32_Shdr *tab = &sections[elf->e_shstrndx];
    char *sections_array = buf + tab->sh_offset;
    char *section_name = NULL;

    for (int i = 1; i < elf->e_shnum; i++) {
        section_name = sections_array + sections[i].sh_name;
        if (strcmp(".bss", section_name) == 0 ||
            strcmp(".symtab", section_name) == 0 ||
            strcmp(".strtab", section_name) == 0 ||
            strcmp(".shstrtab", section_name) == 0)
            continue;
        printf("Contents of section %s:\n", section_name);
        print_section_32(sections[i], buf);
    }
}

// Engine for objdump (32 edition)
int objdump_engine_32(char *filename)
{
struct stat s;

    if (stat(filename, &s) != 0) {
        perror("stat");
        return (84);
    }
    print_header(filename);
    loop_sections(filename, s.st_size);
    return (0);
}