/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** objdump_tests
*/

#include "../objdump/inc/my_objdump.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

// Error management
Test(error_directory, manage_error, .exit_code = 84)
{
    char *filename = strdup("../tests/");

    manage_errors(filename);
    cr_assert_stderr_eq_str("my_objdump: Warning: '../tests/' is a directory");
}

Test(error_no_file, manage_error, .exit_code = 84)
{
    char *filename = strdup("yess");

    manage_errors(filename);
    cr_assert_stderr_eq_str("my_objdump: 'yess': no such file");
}

Test(error_not_elf, manage_error, .exit_code = 84)
{
    char *filename = strdup("Makefile");

    manage_errors(filename);
    cr_assert_stderr_eq_str("my_objdump: Makefile: file format not recognized");
}

Test(error_truncated, manage_error, .exit_code = 84)
{
    char *filename = strdup("../tests/truncated");

    manage_errors(filename);
    cr_assert_stderr_eq_str("my_objdump: ../tests/truncated: file truncated");
}

// Objdump engine
Test(engine_64, get_header)
{
    char *filename = strdup("../tests/obj_binary");

    cr_assert(objdump_engine_64(filename) == 0);
}

Test(engine_32, get_header)
{
    char *filename = strdup("../tests/33.so");

    cr_assert(objdump_engine_32(filename) == 0);
}

// Header values

///// 64
Test(archi_64, get_header)
{
    char *filename = strdup("../tests/obj_binary");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_archi_64(elf.e_machine), "i386:x86-64") == 0);
}

Test(flags_str_64, get_header)
{
    char *filename = strdup("../tests/obj_binary");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_flags_str_64(elf.e_type), "EXEC_P, HAS_SYMS, D_PAGED") == 0);
}

Test(flags_str_bis_64, get_header)
{
    char *filename = strdup("../tests/engine_test");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_flags_str_64(elf.e_type), "HAS_RELOC, HAS_SYMS") == 0);
}

Test(flags_str_ter_64, get_header)
{
    char *filename = strdup("../tests/lib.so");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_flags_str_64(elf.e_type), "HAS_SYMS | DYNAMIC | D_PAGED") == 0);
}

Test(flags_int_64, get_header)
{
    char *filename = strdup("../tests/obj_binary");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(get_flags_int_64(elf.e_type) == (D_PAGED | HAS_SYMS | EXEC_P));
}

Test(flags_int_bis_64, get_header)
{
    char *filename = strdup("../tests/engine_test");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(get_flags_int_64(elf.e_type) == (HAS_SYMS | HAS_RELOC));
}

Test(flags_int_ter_64, get_header)
{
    char *filename = strdup("../tests/lib.so");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(get_flags_int_64(elf.e_type) == (D_PAGED | DYNAMIC | HAS_SYMS));
}

//// 32
Test(archi_32, get_header)
{
    char *filename = strdup("../tests/33.so");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_archi_32(elf.e_machine), "i386") == 0);
}

Test(flags_str_32, get_header)
{
    char *filename = strdup("../tests/obj_binary");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_flags_str_32(elf.e_type), "EXEC_P, HAS_SYMS, D_PAGED") == 0);
}

Test(flags_str_bis_32, get_header)
{
    char *filename = strdup("../tests/engine_test");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_flags_str_32(elf.e_type), "HAS_RELOC, HAS_SYMS") == 0);
}

Test(flags_str_ter_32, get_header)
{
    char *filename = strdup("../tests/lib.so");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(strcmp(get_flags_str_32(elf.e_type), "HAS_SYMS | DYNAMIC | D_PAGED") == 0);
}

Test(flags_int_32, get_header)
{
    char *filename = strdup("../tests/obj_binary");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(get_flags_int_32(elf.e_type) == (D_PAGED | HAS_SYMS | EXEC_P));
}

Test(flags_int_bis_32, get_header)
{
    char *filename = strdup("../tests/engine_test");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(get_flags_int_32(elf.e_type) == (HAS_SYMS | HAS_RELOC));
}

Test(flags_int_ter_32, get_header)
{
    char *filename = strdup("../tests/lib.so");
    Elf64_Ehdr elf;
    FILE* fd = fopen(filename, "r");

    fread(&elf, 1, sizeof(elf), fd);
    cr_assert(get_flags_int_32(elf.e_type) == (D_PAGED | DYNAMIC | HAS_SYMS));
}