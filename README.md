# RC4 encryption

#### Symmetric encryption

Symmetric encryption refers to an encryption algorithm that uses the same key for encryption and decryption. This is the case for the RC4 algorithm. In most symmetric algorithms, the encryption key and the decryption key are the same. Therefore the algorithm retorting to symmetric encryption can also be called a single key algorithm. It requires teh send and receiver to agree on a key before communicating securely. Besides, the security of the symmetric algorithm depends on the key. Leaking the key means that anyone can decrypt the messages they send or receive. Therefore, the condifentiality of the key is very important to the security of communication.

#### What is RC4?

Shortly put, RC4 was designed by Ron Rivest of RSA Secuirty in 1987. RC4 is a fast and simple stream cipher that uses a pseudo-random number generation algorithm the generate a keystream. The keystream can be used in a XOR operation with plaintext to generate ciphertext. The same keystream can then be used in a XOR operation against the ciphertext to generate the original plaintext.

#### RC4 encryption process

We start with an S-box array with a 256 octets length.

The user gives RC4 a key and a plain text to encode.

During the initialization process, the key is used to scramble the S-box.

Then, for each character in the plaintext, a keystream is generated. This keystream is used to perform a XOR operation on the plaintext to obtain the ciphertext. The decryption process is exactly the same.

Decryption works the same way: XORing the ciphertext with the same keystream restores the original plaintext.

# Measure password's entropy (passwordCheck)

Password's entropy is a key concept in cybersecurity. It measures the difficulty for an attacker to uess a password. The higher the entropy, the more difficult it is for an attacker to guess a password.

# Reverse Shell

In a standard remote shell attack, attackers connect a machine they control to the target’s remote network host, requesting a shell session. This tactic is known as a bind shell. Attackers can use a reverse shell if a remote host is not publicly accessible (i.e., due to firewall protection or a non-public IP). The target machine initiates the outgoing connection in a reverse shell attack and establishes the shell session with the listening network host.

It is a method attackers use to gain remote control over a target system. Unlike standard shells, where the attacker connects directly to the victim’s system, a reverse shell reverses the process. Specifically, the compromised machine initiates a connection to the attacker’s server.

#### cmd.exe

The process cmd.exe is a generic Windows process opening a console in text mode and enabling to launch applications through commands. Starts a new instance of command interpretor, cmd.exe.

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

# Entropy

Un ransomware :

- chiffre les fichiers
- rend les octets **uniformément répartis**
- provoque une **hausse brutale d’entropie**

We can use Shannon's formula to calculate entropy.

Example :

File A:

`AAAAAAAAAAA`

Very repetitive. Entropy ~ 0

File B :

`A8&xQ!Pz3@`

Entropy ~ 8

| Valeur | Signification        |
| ------ | -------------------- |
| ~0     | Very repetitive file |
| 3-5    | Text                 |
| 6-7    | Compressed data      |
| 7.5-8  | Very suspect file    |

# File Magic Numbers

Magic numbers are the first bits of a file which uniquely identify the file type. The program magicNumber.c opens a file in binary mode, reads the first 8 bytes. It compares the 8 bytes with known magic numbers, using the function memcmp. It then returns the detected type or "Unknown file type". The main function handles the input and prints the result.

| Type        | Magic Number (hex)        | ASCII |
| ----------- | ------------------------- | ----- |
| ELF (Linux) | `7F 45 4C 46`             |       |
| PNG         | `89 50 4E 47 0D 0A 1A 0A` |       |
| JPEG        | `FF D8 FF`                |       |
| PDF         | `25 50 44 46`             |       |
| ZIP         | `50 4B 03 04`             |       |
