/* Intentionally empty: shim so dnsmasq's #include <linux/sockios.h> resolves.
 * Unikraft does not provide <linux/sockios.h>; the SIOC* ioctl constants dnsmasq uses come from musl's <sys/ioctl.h> instead. */
