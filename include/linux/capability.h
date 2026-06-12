#ifndef _LINUX_CAPABILITY_H
#define _LINUX_CAPABILITY_H

typedef struct __user_cap_header_struct {
	int version;
	int pid;
} *cap_user_header_t;

typedef struct __user_cap_data_struct {
	int effective;
	int permitted;
	int inheritable;
} *cap_user_data_t;

#define CAP_CHOWN            0
#define CAP_NET_ADMIN        1
#define CAP_NET_RAW          2
#define CAP_NET_BIND_SERVICE 3
#define CAP_SETUID           4

#define LINUX_CAPABILITY_VERSION_1  0x19980330
#define LINUX_CAPABILITY_VERSION_2  0x20071026
#define LINUX_CAPABILITY_VERSION_3  0x20080522

#endif
