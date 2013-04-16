#ifndef _NETINET_ETHER_H
#define _NETINET_ETHER_H

char	*ether_ntoa(const struct ether_addr *);
struct 	ether_addr *ether_aton(const char *);
int	ether_ntohost(char *, const struct ether_addr *);
int	ether_hostton(const char *, struct ether_addr *);
int	ether_line(const char *, struct ether_addr *, char *);

#endif /* !_NETINET_ETHER_H */
