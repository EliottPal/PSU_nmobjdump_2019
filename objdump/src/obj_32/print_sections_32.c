/*
** EPITECH PROJECT, 2020
** objdump
** File description:
** print_sections_32
*/

#include "../../inc/my_objdump.h"

// Print the good number of spaces
static void print_spaces(size_t i, bool is_end)
{
    if (is_end == true) {
        while (i % 16 != 0) {
            printf(" ");
            i++;
        }
        printf("\n");
        return;
    }
    printf(" ");
    while (i % 16 != 0) {
        printf("  ");
        i++;
        if (i % 4 == 0)
            printf(" ");
    }
}

// Print content of section (char 1 by 1)
static void print_hexa_content(Elf32_Shdr section, char *buf, size_t i)
{
    unsigned char to_print = '\0';

    while (i < section.sh_size) {
        to_print = (buf + section.sh_offset)[i];
        printf("%02x", to_print);
        i++;
        if (i % 16 == 0) {
            printf("  ");
            break;
        }
        if (i % 4 == 0)
            printf(" ");
    }
    if (i % 16 != 0 && i >= section.sh_size)
        print_spaces(i, false);
}

// Print char or '.' if ascii character
static void	print_charac(char character)
{
    if (character >= 32 && character <= 126)
        printf("%c", character);
    else
        printf(".");
}

// Print the content of sections
void print_section_32(Elf32_Shdr section, char *buf)
{
    size_t	i = 0;
    size_t	addr;
    char to_print = '\0';

    addr = section.sh_addr;
    while (i < section.sh_size) {
        if (i % 16 == 0) {
        printf(" %04lx ", addr);
        addr += 16;
        print_hexa_content(section, buf, i);
    }
    to_print = (buf + section.sh_offset)[i];
    print_charac(to_print);
    i++;
    if (i % 16 == 0)
        printf("\n");
    }
    if (i % 16 != 0 && i >= section.sh_size)
        print_spaces(i, true);
}