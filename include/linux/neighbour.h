/* Shim so dnsmasq's netlink.c can compile its RTM_NEWNEIGH (ARP/neighbour
 * table) handling. lib-lwip <linux/rtnetlink.h> does not pull in
 * <linux/neighbour.h> because the lwIP route driver does not implement
 * RTM_GETNEIGH; at runtime such a dump returns no entries, which dnsmasq
 * handles. Definitions below match the Linux uapi header. */
#ifndef _LINUX_NEIGHBOUR_H
#define _LINUX_NEIGHBOUR_H

#include <linux/types.h>

struct ndmsg {
	__u8	ndm_family;
	__u8	ndm_pad1;
	__u16	ndm_pad2;
	__s32	ndm_ifindex;
	__u16	ndm_state;
	__u8	ndm_flags;
	__u8	ndm_type;
};

enum {
	NDA_UNSPEC,
	NDA_DST,
	NDA_LLADDR,
	NDA_CACHEINFO,
	NDA_PROBES,
	__NDA_MAX
};
#define NDA_MAX (__NDA_MAX - 1)

/* ndm_state */
#define NUD_INCOMPLETE	0x01
#define NUD_REACHABLE	0x02
#define NUD_STALE	0x04
#define NUD_DELAY	0x08
#define NUD_PROBE	0x10
#define NUD_FAILED	0x20
/* Dummy states */
#define NUD_NOARP	0x40
#define NUD_PERMANENT	0x80
#define NUD_NONE	0x00

#endif /* _LINUX_NEIGHBOUR_H */
