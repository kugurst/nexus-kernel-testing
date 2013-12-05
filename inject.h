#ifndef __INJECT_H_
#define __INJECT_H_

#include <sys/syscall.h>

#define __NR_ext4_cowcopy 378

inline long ext4_cowcopy(const char __user *src, const char __user *dest) {
    return syscall(__NR_ext4_cowcopy, src, dest);
}

#endif  // __INJECT_H_
