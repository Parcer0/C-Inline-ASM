#include <stdio.h>

#define _XOPEN_SOURCE
#define _USE_GNU

char *format = "%s %s!\n";
char *hello = "Hello";
char *world = "world";

int __cdecl main()
{
    __asm (
        ".intel_syntax noprefix\n"
        "mov  eax, _world\n"
        "push eax\n"
        "mov  eax, _hello\n"
        "push eax\n"
        "mov  eax, _format\n"
        "push eax\n"
        "call _printf\n"
        // printf is in __cdecl...
        "pop  ecx\n"
    );
    return 0;
}
