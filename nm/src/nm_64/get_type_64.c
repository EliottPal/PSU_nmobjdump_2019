/*
** EPITECH PROJECT, 2020
** nm
** File description:
** get_type_64
*/

#include "../../inc/my_nm.h"

// Get flags extended again
static char	get_flags_ter(Elf64_Sym *symbol, Elf64_Shdr *sections)
{
    if ((sections[symbol->st_shndx].sh_type == SHT_FINI_ARRAY ||
        sections[symbol->st_shndx].sh_type == SHT_INIT_ARRAY) &&
        sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return ('T');
    if (sections[symbol->st_shndx].sh_type == SHT_NOBITS
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return ('B');
    if (sections[symbol->st_shndx].sh_type == SHT_PROGBITS
        && (sections[symbol->st_shndx].sh_flags == SHF_ALLOC
        || sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_MERGE)))
        return ('R');
    return ('?');
}

// Get flags extended
static char	get_flags_bis(Elf64_Sym *symbol, Elf64_Shdr *sections)
{
    if (symbol->st_shndx == SHN_ABS)
        return ('A');
    if (symbol->st_shndx == SHN_COMMON)
        return ('C');
    if (sections[symbol->st_shndx].sh_type == SHT_PROGBITS
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
        return ('D');
    if (sections[symbol->st_shndx].sh_type == SHT_PROGBITS
        && sections[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
        return ('T');
    if (sections[symbol->st_shndx].sh_type == SHT_DYNAMIC)
        return ('D');
    return (get_flags_ter(symbol, sections));
}

// Get flags
static char	get_flags(Elf64_Sym *symbol, Elf64_Shdr *sections)
{
    if (ELF64_ST_BIND(symbol->st_info) == STB_GNU_UNIQUE)
        return ('u');
    if (ELF64_ST_BIND(symbol->st_info) == STB_WEAK &&
        ELF64_ST_TYPE(symbol->st_info) == STT_OBJECT) {
        if (symbol->st_shndx == SHN_UNDEF)
            return ('v');
        else
            return ('V');
        }
    if (ELF64_ST_BIND(symbol->st_info) == STB_WEAK) {
        if (symbol->st_shndx == SHN_UNDEF)
            return ('w');
        else
            return ('W');
    }
    if (symbol->st_shndx == SHN_UNDEF)
        return ('U');
    return (get_flags_bis(symbol, sections));
}

// Get the symbol type to print
char get_type_64(Elf64_Sym *symbol, Elf64_Shdr *sections)
{
    char c = '\0';

    c = get_flags(symbol, sections);
    if (ELF64_ST_BIND(symbol->st_info) == STB_LOCAL && c != '?')
        c += 32;
    return (c);
}