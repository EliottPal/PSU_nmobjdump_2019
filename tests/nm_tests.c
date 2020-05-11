/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** nm_tests
*/

#include "../nm/inc/my_nm.h"
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

// Nm engine
Test(engine_64, get_header)
{
    char *filename = strdup("../tests/obj_binary");

    cr_assert(nm_engine_64(filename) == 0);
}

Test(engine_32, get_header)
{
    char *filename = strdup("../tests/33.so");

    cr_assert(nm_engine_32(filename) == 0);
}