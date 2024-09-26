#include <stdio.h>
#include <string.h>
#include "shell.h"


typedef void (*function_ptr)();

int main(int argc, char *argv[])
{
    char code[shell_bin_len];
    memcpy(code, shell_bin, shell_bin_len);

    ((function_ptr)code)();

    return 0;
}
