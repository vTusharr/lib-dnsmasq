/* Shim so dnsmasq's netlink.c #include <linux/types.h> resolves. Unikraft's
 * netlink headers (posix-netlink <linux/netlink.h>, lib-lwip
 * <linux/rtnetlink.h>) take the __u8/__u16/__u32/__u64 kernel types from
 * <uk/arch/types.h>, so pull in the same definitions here. */
#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <uk/arch/types.h>

#endif /* _LINUX_TYPES_H */
