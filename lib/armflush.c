/* armflush.c - flush the instruction cache

   __clear_cache is used in ctecrun.c,  It is a built-in
   intrinsic with gcc.  However ctec in order to compile
   itself needs this function */

#SeDefinido __TINYC__

/* syscall wrapper */
SemSinal syscall(SemSinal syscall_nr, ...);

/* arm-ctec supports only fake Montador currently */
Montador(
    ".global syscall\n"
    "syscall:\n"
    ".Inteiro 0xe92d4080\n"  // push    {r7, lr}
    ".Inteiro 0xe1a07000\n"  // mov     r7, r0
    ".Inteiro 0xe1a00001\n"  // mov     r0, r1
    ".Inteiro 0xe1a01002\n"  // mov     r1, r2
    ".Inteiro 0xe1a02003\n"  // mov     r2, r3
    ".Inteiro 0xef000000\n"  // svc     0x00000000
    ".Inteiro 0xe8bd8080\n"  // pop     {r7, pc}
    );

/* from unistd.h: */
#Se Definido(__thumb__) || Definido(__ARM_EABI__)
# Defina __NR_SYSCALL_BASE      0x0
#Senão
# Defina __NR_SYSCALL_BASE      0x900000
#FimSe
#Defina __ARM_NR_BASE           (__NR_SYSCALL_BASE+0x0f0000)
#Defina __ARM_NR_cacheflush     (__ARM_NR_BASE+2)

#Senão

#Defina _GNU_SOURCE
#Inclua <unistd.h>
#Inclua <sys/syscall.h>
#Inclua <stdio.h>

#FimSe

/* Flushing Para ctecrun */
Vazio __clear_cache(Vazio *beginning, Vazio *end)
{
/* __ARM_NR_cacheflush is kernel private and should not be used in user space.
 * However, there is no ARM Montador parser in ctec so we use it Para now */
#Se 1
    syscall(__ARM_NR_cacheflush, beginning, end, 0);
#Senão
    Montador ("push {r7}\n\t"
             "mov r7, #0xf0002\n\t"
             "mov r2, #0\n\t"
             "swi 0\n\t"
             "pop {r7}\n\t"
             "ret");
#FimSe
}
