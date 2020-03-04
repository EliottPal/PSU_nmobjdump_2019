/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** my_objdump
*/

#ifndef MY_OBJDUMP_H_
#define MY_OBJDUMP_H_

// Includes
#include <stdio.h>
#include <sys/mman.h>
#include <stdbool.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <elf.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../flags.h"

//// 64
int objdump_engine_64(char *filename);
bool check_format_64(char *filename);

char *get_archi_64(Elf64_Half elf);
int get_flags_int_64(Elf64_Half elf);
char *get_flags_str_64(Elf64_Half elf);

void print_section_64(Elf64_Shdr section, char *buff);

//// 32
int objdump_engine_32(char *filename);

char *get_archi_32(Elf32_Half elf);
int get_flags_int_32(Elf32_Half elf);
char *get_flags_str_32(Elf32_Half elf);

void print_section_32(Elf32_Shdr section, char *buff);

#endif /* !MY_OBJDUMP_H_ */
