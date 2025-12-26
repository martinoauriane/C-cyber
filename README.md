# Measure password's entropy (passwordCheck)

Password's entropy is a key concept in cybersecurity. It measures the difficulty for an attacker to uess a password. The higher the entropy, the more difficult it is for an attacker to guess a password.

# Buffer overflow

### Safe practice habits: using strncpy instead of scanf( ) or gets( )

The strncpy( ) function is defined in the `<string.h>` header file. It copies the first n characters from one string into the memory of another string. This does not add a null terminating character to the copied data, so it needs to be manually added afterwards.

## Syntax

```java
strncpy(char * destination, char * source, size_t n);
```

The `size_t` data type is a positive integer.

### Building a simple TCP port scanner in C (portScanner)

Port scanning is a technique used to determine which ports on a target host are open. A target is defined and ports on this target are scanned.

### Using sockets as a way to scan ports on a given target address

We're going to use sockets as a way to communicate with any target address and scan one by one its local ports. Indeed, sockets are a way to communicate with a target server/ target address by establishing a communication between the client and the server.

The fundamental structures to indicate a target IP address and target connexion port can be found in <netinet/in.h> library. There exists one for IPv4 and one for IPv6. For an IPv4 address, the struct sockaddr_in is as follows:

struct sockaddr_in {

    sa_family_t 		sin_family;

    int_port_t		sin_port;

    struct  in_addr	sin_addr;

}

- sin_family : represents the address IP protocol family : either IPv4, or IPv6. In our case, we'll use AF_INET.
- sin_port: The port to which we wish to connect.
- sin_addr : represents tehe IPv4 address.

Preparing a socket : We use <sys/socket.h> to create a new socket:

int socket(int domain, int type, int protocol)

- domain: the family of socket protocol (if using IPv4, AF_INET)
- type : the type of socket, generally SOCK_STREAM
- protocol: The protocol we want to use with the socket. Generally, there is only one valid protocol by socket type, so we can put the value 0.

### RFID skimming

Modern payment contain a [RFID](https://en.wikipedia.org/wiki/RFID "RFID") chip to transmit card information wirelessly to enable [contactless payments](https://en.wikipedia.org/wiki/Contactless_payment "Contactless payment"), which has become increasingly common.
Criminals can take advantage of this technology by using a scanner to wirelessly read a victim's payment card in the same way that a cash register scans it, when making a contactless payment.

Some security experts have voiced concerns about a phenomenon called RFID skimming, in which a thief with an RFID reader may be able to steal your credit card number or personal information simply by walking within a few feet of you.
