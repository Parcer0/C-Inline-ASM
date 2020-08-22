/*
  Name: C.vS.asM
  Copyright: NeoSecurityTeam
  Author: Parcer0
  Date: 20050507
  Description: Code that shows which language is faster C or ASM.

  Parcer0@NeoSecurityTeam:~$ pico C.vS.asM.c
  Parcer0@NeoSecurityTeam:~$ gcc -masm=intel C.vS.asM.c -o C.vS.asM
  Parcer0@NeoSecurityTeam:~$ ./C.vS.asM
  [+] C.vS.asM by Parcer0 [+]
  [+] NeoSecurityTeam       [+]

  Contaremos hasta 0xFFFFFFFF en "C"
  Ah Pasado: 12.01 segundos, se conto hasta: 0xFFFFFFFF

  Contaremos hasta 0xFFFFFFFF en "ASM"
  Ah Pasado: 4.33 segundos, se conto hasta: 0xFFFFFFFF

  [+] Damn!!! =]            [+]
  Parcer0@NeoSecurityTeam:~$

  Under GPL
  I accept no responsibilty for any damage caused by it.
  Additons and fixes always welcome.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _USE_GNU
#define _XOPEN_SOURCE

long int y=0;
unsigned int MAX = 0xFFFFFFF;

int main()
{
    	unsigned long int i;
    	clock_t r1, r2, r3, r4;

        printf("[+] C.vS.asM by HaCkZaTaN [+]");
        printf("[+] NeoSecurityTeam       [+]\n");
    	printf("Contaremos hasta 0x%X en \"C\"\n", MAX);
    	fflush(stdout);

    	r1 = clock();

        for (i=0; i < MAX; i++) i+=1;

        r2 = clock();

    	printf("Ah Pasado: %.5f segundos, se conto hasta: %ld\n\n",(((float)r2-(float)r1)/CLOCKS_PER_SEC), i);
    	printf("Contaremos hasta 0x%X en \"ASM\"\n", MAX);
    	fflush(stdout);

    	r3 = clock();

        __asm__
        (
        ".intel_syntax noprefix\n"
		       "xor edx, edx\n"
        "Start:\n"
        		"inc edx\n"
        		"cmp edx, MAX\n"
        		"jl Start\n"
        "Finish:\n"
                "mov y, edx");

        r4 = clock();

        printf("Ah Pasado: %.5f segundos, se conto hasta: %ld\n\n",((float)r4-(float)r3)/CLOCKS_PER_SEC, y);
        printf("[+] Damn!!! =]            [+]");
        fflush(stdout);

        return 0;
}

/* EOF */
