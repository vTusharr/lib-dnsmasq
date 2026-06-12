/* Intentionally empty: shim so dnsmasq's #include <linux/sockios.h> resolves on
 * , as we dont have  <linux/sockios.h>. The SIOC* ioctl
 * constants dnsmasq uses come from musl's <sys/ioctl.h> instead. */
