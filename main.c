#include <string.h>
#include <sys/utsname.h>

extern int dnsmasq_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
	return dnsmasq_main(argc, argv);
}

/* Unikraft does not implement the uname syscall.
   Provide a stub that returns a  Linux 5.10.0 version
   so dnsmasq's kernel_version() check succeeds. */
int uk_uname(struct utsname *buf)
{
	memset(buf, 0, sizeof(*buf));
	strcpy(buf->sysname,  "Linux");
	strcpy(buf->nodename, "unikraft");
	strcpy(buf->release,  "5.10.0");
	strcpy(buf->version,  "#1 Unikraft");
#if defined(__x86_64__)
	strcpy(buf->machine,  "x86_64");
#elif defined(__aarch64__)
	strcpy(buf->machine,  "aarch64");
#else
	strcpy(buf->machine,  "unknown"); //riscv?
#endif
	return 0;
}
