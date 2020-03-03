/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** engine_64
*/

#include "../../inc/my_objdump.h"

static void print_header(char *filename)
{
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    printf("%s:\tfile format elf64-x86-64\n", filename);
    printf("architecture: %s, flags 0x%08x\n", get_archi_64(elf.e_machine), get_flags_int_64(elf.e_type));
    printf("%s\n", get_flags_str_64(elf.e_type));
    printf("start address 0x%016lx\n\n", elf.e_entry);
}

// Print the content of sections
// static void print_section(Elf64_Shdr section)
// {
//     size_t offset = section.sh_offset;
// }

// Loop through all sections
static void loop_sections(char *filename, size_t file_size)
{
    int fd = open(filename, O_RDONLY);
    void *map = mmap(0, file_size, PROT_READ, MAP_PRIVATE, fd, 0);
    Elf64_Ehdr *elf = (Elf64_Ehdr*)map;
    Elf64_Shdr *sections = (Elf64_Shdr *)(map + elf->e_shoff);
    Elf64_Shdr *tab = &sections[elf->e_shstrndx];
    char *sections_array = map + tab->sh_offset;
    char *section_name = NULL;

    for (int i = 1; i < elf->e_shnum; i++) {
        section_name = sections_array + sections[i].sh_name;
        if (strcmp(".bss", section_name) == 0 ||
            strcmp(".symtab", section_name) == 0 ||
            strcmp(".strtab", section_name) == 0 ||
            strcmp(".shstrtab", section_name) == 0)
            continue;
        printf("Contents of section %s:\n", section_name);
        // print_section(sections[i]);
    }
}

// Engine for objdump (64 edition)
int objdump_engine_64(char *filename)
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