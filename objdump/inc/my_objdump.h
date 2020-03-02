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
#include <elf.h>

// Protos
void objdump_engine(char *filename);

#endif /* !MY_OBJDUMP_H_ */
