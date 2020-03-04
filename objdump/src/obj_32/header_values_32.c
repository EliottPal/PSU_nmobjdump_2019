/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** header_values_32
*/

#include "../../inc/my_objdump.h"

char *get_archi_32(Elf32_Half elf)
{
    if (elf == EM_386)
        return ("i386");
    return ("i386:x86-64");
}

int get_flags_int_32(Elf32_Half elf)
{
    if (elf == ET_REL)
        return (HAS_SYMS | HAS_RELOC);
    else if (elf == ET_EXEC)
        return (D_PAGED | HAS_SYMS | EXEC_P);
    else if (elf == ET_DYN)
        return (D_PAGED | DYNAMIC | HAS_SYMS);
    return (0);
}

char *get_flags_str_32(Elf32_Half elf)
{
    if (elf == ET_REL)
        return ("HAS_RELOC, HAS_SYMS");
    else if (elf == ET_EXEC)
        return ("EXEC_P, HAS_SYMS, D_PAGED");
    else if (elf == ET_DYN)
        return ("HAS_SYMS | DYNAMIC | D_PAGED");
    return (0);
}