#ifndef SYSCALL_H_
#define SYSCALL_H_

#include <linux/errno.h>
#include <sys/types.h>

extern int errno;

/* Wrappers */

/* sys_call number 243 */
int is_short (pid_t pid) {
    unsigned int res;
      __asm__(
           "int $0x80;"
           : "=a" (res)
           : "0" (243) ,"b" (pid)
           : "memory"
);
     if (res>= (unsigned long)(-125))
     {
errno = -res;
res = -1;
}
return (int) res;
}

/* sys_call number 244 */
int short_remaining_time (pid_t pid) {
    unsigned int res;
      __asm__(
           "int $0x80;"
           : "=a" (res)
           : "0" (244) ,"b" (pid)
           : "memory"
);
     if (res>= (unsigned long)(-125))
     {
errno = -res;
res = -1;
}
return (int) res;
}

/* sys_call number 245 */
int was_short (pid_t pid) {
    unsigned int res;
      __asm__(
           "int $0x80;"
           : "=a" (res)
           : "0" (245) ,"b" (pid)
           : "memory"
);
     if (res>= (unsigned long)(-125))
     {
errno = -res;
res = -1;
}
return (int) res;
}

#endif
