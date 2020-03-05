/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** get_values
*/

#include "../../inc/my_objdump.h"

// Get architecture
char *get_archi_64(Elf64_Half elf)
{
    if (elf == EM_386)
        return ("i386");
    return ("i386:x86-64");
}

// Flags into int
int get_flags_int_64(Elf64_Half elf)
{
    if (elf == ET_REL)
        return (HAS_SYMS | HAS_RELOC);
    else if (elf == ET_EXEC)
        return (D_PAGED | HAS_SYMS | EXEC_P);
    else {
        if (elf == ET_DYN)
            return (D_PAGED | DYNAMIC | HAS_SYMS);
        else
            return (0);
    }
    return (0);
}

// Flags into char
char *get_flags_str_64(Elf64_Half elf)
{
    if (elf == ET_REL)
        return ("HAS_RELOC, HAS_SYMS");
    else if (elf == ET_EXEC)
        return ("EXEC_P, HAS_SYMS, D_PAGED");
    else {
        if (elf == ET_DYN)
            return ("HAS_SYMS | DYNAMIC | D_PAGED");
        else
            return ("");
    }
    return (0);
}