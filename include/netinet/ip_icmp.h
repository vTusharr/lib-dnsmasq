/* Intentionally empty: shim so dnsmasq's #include resolves, as we do not have this header.
 * The features that would use its contents are compiled out (NO_DHCP/NO_TFTP), or the required symbols come from lwIP/musl. */
