/*
** EPITECH PROJECT, 2020
** nm
** File description:
** my_nm
*/

#ifndef MY_NM_H_
#define MY_NM_H_

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
void nm_engine_64(char *filename);

//// 32
void nm_engine_32(char *filename);

#endif /* !MY_NM_H_ */
