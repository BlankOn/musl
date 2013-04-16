#include <ctype.h>
#include <stdlib.h>
#include <netinet/if_ether.h>
#include <stdbool.h>

static inline unsigned int xdigit2int(const char c)
{
  return isdigit(c) ? (c - '0') : (c - 'a' + 10);
}

struct ether_addr *
ether_aton_r (const char *textaddr, struct ether_addr *addr)
{
  size_t count;
  const char *asc = textaddr;
  for (count = 0; count < 6; ++count)
  {
    unsigned int octet;
    char ch = _tolower(*asc++);
    if (!isxdigit(ch)) {
      return NULL;
    }
    octet = xdigit2int(ch);
    
    ch = _tolower(*asc);
    if (( count < 5 && ch != ':' ) || ( count == 5 && ch != '\0' && !isspace(ch))) {
      ++asc;
      if ( !isxdigit(ch)) {
        return 0;
      }
      octet <<= 4;
      octet += xdigit2int(ch);

      ch = *asc;
      if ( count < 5 && ch != ':' ) {
        return NULL;
      }

      addr->ether_addr_octet[count] = (unsigned char) octet;
      ++asc;
    }
  }
  return addr;
}
