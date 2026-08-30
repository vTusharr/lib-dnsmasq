dnsmasq DNS forwarder/cache for Unikraft
========================================

This is a port of [dnsmasq](https://thekelleys.org.uk/dnsmasq/doc.html) 2.91 as
an external Unikraft library. It provides a DNS forwarder and cache over UDP and
TCP. This is a **DNS-only** build: DHCP, TFTP, and scripting are disabled

When adding the library to the dependencies list, the libraries should be
ordered like this:
`...$(UK_LIBS)/musl:$(UK_LIBS)/lwip:$(UK_LIBS)/nettle:$(UK_LIBS)/dnsmasq:...`


 **DNSSEC** validation is enabled by default (`CONFIG_LIBDNSMASQ_DNSSEC`)
and pulls in [lib-nettle](https://github.com/unikraft/lib-nettle) + libhogweed
for the public-key crypto.


Interface discovery uses **netlink**: dnsmasq's own `netlink.c` runs
`RTM_GETADDR`/`RTM_GETLINK` dumps against Unikraft's `posix-netlink` + the
lwIP `NETLINK_ROUTE` driver, so the library requires **Unikraft >= 0.21.0**
(and currently `CONFIG_LWIP_IPV6=n`; the route driver does not compile).

The `patches/` directory carries the adaptations. See the
`dnsmasq` application in the catalog for build/run instructions.

Please refer to the `README.md` as well as the documentation in the `doc/`
subdirectory of the main Unikraft repository.
