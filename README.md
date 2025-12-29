# C Projects

This repo is dedicated to the implementation of C cybersecurity projects.

# RC4.c : implementing RC4 encryption

#### Symmetric encryption

Symmetric encryption refers to an encryption algorithm that uses the same key for encryption and decryption. This is the case for the RC4 algorithm. In most symmetric algorithms, the encryption key and the decryption key are the same. Therefore the algorithm retorting to symmetric encryption can also be called a single key algorithm. It requires the sender and receiver to agree on a key before communicating securely. Besides, the security of the symmetric algorithm depends on the key. Leaking the key means that anyone can decrypt the messages they send or receive. Therefore, the condifentiality of the key is very important to the security of communication.

#### What is RC4?

Shortly put, RC4 was designed by Ron Rivest of RSA Secuirty in 1987. RC4 is a fast and simple stream cipher that uses a pseudo-random number generation algorithm the generate a keystream. The keystream can be used in a XOR operation with plaintext to generate ciphertext. The same keystream can then be used in a XOR operation against the ciphertext to generate the original plaintext.

RC4 has been legitimately implemented in a number of areas where speed and privacy are of concern. In the past, both WEP and TLS used RC4 to protect data send across the wire.

RC4 is implemented in two main phases:

1. A Key Scheduling Algorithm is executed using a symmetric key to create an array of 256 bytes. This array is then shuffled an complexified using the symmetric key. During the initialization process, the main function of the key is to scramble the S-box.
2. This array is then used in a pseudo-random generation algorithm to generate a keystream which used in plaintext XOR operation, will produce a cipher stream that can be decoded using the same key.

#### RC4 encryption process

Steps :

- The user gives RC4 a key and a plain text to encode.
- We start with an S-box array with a 256 octets length.
- During the initialization process, the key is used to scramble the S-box.
- Then, for each character in the plaintext, a keystream is generated.
- This keystream is used to perform a XOR operation on the plaintext to obtain the ciphertext.
- Decryption works the same way: XORing the ciphertext with the same keystream restores the original plaintext.

#### The XOR bitwise operator

XOR has many uses, especially in cryptography, hashing, and in pseudo-random number generation. Since XOR is reversible, A ^B = C, then C ^B = A. The number B is essentially the 'key' to encrypt A to C and to decrypt C back to A.

# passwordCheck.c : Measuring a password's entropy

The program takes an input as a string and evaluate if it is a valid password. The password is valid if it has numbers, capital and small alphabets, and a length of at least 7 characters.

# reverseShell.c : implementing a reverse Shell

In a standard remote shell attack, attackers connect a machine they control to the target’s remote network host, requesting a shell session. This tactic is known as a bind shell. Attackers can use a reverse shell if a remote host is not publicly accessible (i.e., due to firewall protection or a non-public IP). The target machine initiates the outgoing connection in a reverse shell attack and establishes the shell session with the listening network host.

A reverseShell is a method attackers use to gain remote control over a target system. Unlike standard shells, where the attacker connects directly to the victim’s system, a reverse shell reverses the process. Specifically, the compromised machine initiates a connection to the attacker’s server.

#### Strategy

To create a Windows reverse shell, the program uses websockets.In this scenario, the program is the client. It initiates an outgoing connexion. The IP address is that of the distant host : the target machine in which the reverse Shell will be implemented. If the connexion succeeds, a bi-directional stream is opened and the two machines can now exchange data.

First, the `STARTUPINFO` structure is initialized and configured. This structure does **not** describe the process itself, but \*\*how the process must be initialized by the operating system. By setting the flag `STARTF_USESTDHANDLES`, the program explicitly tells Windows to use the custom handles provided for standard input, output, and error. Instead of being connected to the console (keyboard and screen), these standard streams are redirected to the network socket.

As a result, anything the process writes to standard output or standard error is sent through the socket.

#### cmd.exe

The process cmd.exe is a generic Windows process opening a console in text mode and enabling to launch applications through commands. It starts a new instance of command interpretor.

#### Conclusion

This illustrates a key operating system concept: **processes do not write directly to the screen or read directly from the keyboard; they interact with abstract handles, and the operating system decides where those handles are connected** .

# bufferOverflow.c : warning against Buffer overflow

A buffer overflow occurs when the volume of data exceeds the storage capacity of the memory buffer. As a result, the program attempting to write the data to the buffer overwrites adjacent memory locations.

For example, a buffer for log-in credentials may be designed to expect username and password inputs of 8 bytes. So if a transaction involves an input of 10 bytes (that is, 2 bytes more than expected), the program may write the excess data past the buffer boundary.

### Safe practice habits: using strncpy instead of scanf( ) or gets( )

The strncpy( ) function is defined in the `<string.h>` header file. It copies the first n characters from one string into the memory of another string. This does not add a null terminating character to the copied data, so it needs to be manually added afterwards.

## Syntax

```java
strncpy(char * destination, char * source, size_t n);
```

The `size_t` data type is a positive integer.

# portScanner. c: Building a simple TCP port scanner in C (portScanner)

Port scanning is a technique used to determine which ports on a target host are open. A target is defined and ports on this target are scanned.

### Using sockets as a way to scan ports on a given target address

The program uses sockets as a way to communicate with any target address and scan one by one its local ports. Sockets are a way to communicate with a target server/ target address by establishing a communication between the client and the server. The fundamental structures to indicate a target IP address and target connexion port can be found in <netinet/in.h> library. There exists one for IPv4 and one for IPv6. For an IPv4 address, the struct sockaddr_in is as follows:

struct sockaddr_in {

    sa_family_t 		sin_family;

    int_port_t		sin_port;

    struct  in_addr	sin_addr;

}

- sin_family : represents the address IP protocol family : either IPv4, or IPv6. In our case, we'll use AF_INET.
- sin_port: The port to which we wish to connect.
- sin_addr : represents tehe IPv4 address.

Preparing a socket : The module <sys/socket.h> is used to create a new socket:

    int socket(int domain, int type, int protocol)

- domain: the family of socket protocol (if using IPv4, AF_INET)
- type : the type of socket, generally SOCK_STREAM
- protocol: The protocol we want to use with the socket. Generally, there is only one valid protocol by socket type, so we can put the value 0.

# rfidskimming.c : Implementing RFID skimming

Modern payment contain a [RFID](https://en.wikipedia.org/wiki/RFID "RFID") chip to transmit card information wirelessly to enable [contactless payments](https://en.wikipedia.org/wiki/Contactless_payment "Contactless payment"), which has become increasingly common. Criminals can take advantage of this technology by using a scanner to wirelessly read a victim's payment card in the same way that a cash register scans it, when making a contactless payment.

Some security experts have voiced concerns about a phenomenon called RFID skimming, in which a thief with an RFID reader may be able to steal your credit card number or personal information simply by walking within a few feet of people.

# fileEntropy.c : Measuring a file's entropy

This project implements a file entropy calculator in C. Entropy measures the randomness of data within a file, which is a key concept in cryptography, data compression, and malware analysis. In case of a file having an unusually high entropy, it could be a malware. A ransomware is a type of malicious software that prevents the user from accessing his computer files, systems, or networks and demands he pays a ransom for their return. A Ransomware:

- encrypts files
- makes bytes evenly distributed
- causes a sudden increase in entropy

```
Ransomware:

- encrypt files
- makes bytes **evenly distributed**
- causes a **sudden increase in entropy**
```

#### Shannon's entropy

Shannon's entropy is a mathematical function which, intuitively, corresponds to the quantity of information contained in an information source. This source can be a text written in a given language, an electric signal or a random informatic file (octets). The more the source emits different informations, the bigger the entropy. For example, if a source always sends the same symbol, for example the letter 'a', then its entropy is none, or minimal.

In maths, an average is calculated with:

```
average = Σ (value * probability)
```

- value : symbol information log2 p(x)
- probability : p(x)

```
H = Σ p(x) * ( -log₂(p(x)) )
```

- H : Shannon's entropy. Unit: bits.
- x : one octet (from 0 to 255). example: x = 'A'
- p(x) : probability of x showing up. p(x) = freq[ i ] / size. Example : A file of hundred octets. 'A' appears 50 times. Therefore p( 'A' ) = 50 / 100 = 0.5
- log₂ : Answers the question how many bits are needed to describe this symbol?
- Σ : Sum for information of all available symbols.

Example :

- File A: `AAAAAAAAAAA`

Very repetitive. Entropy ~ 0

- File B : `A8&xQ!Pz3@`

Entropy ~ 8

| Value | Meaning              |
| ----- | -------------------- |
| ~0    | Very repetitive file |
| 3-5   | Text                 |
| 6-7   | Compressed data      |
| 7.5-8 | Very suspect file    |

# magicNumber.c : Reading a file's magic numbers

Magic numbers are the first bits of a file which uniquely identify the file type. The program magicNumber.c opens a file in binary mode, reads the first 8 bytes. It compares the 8 bytes with known magic numbers, using the function memcmp. It then returns the detected type or "Unknown file type". The main function handles the input and prints the result.

| Type        | Magic Number (hex)        | ASCII |
| ----------- | ------------------------- | ----- |
| ELF (Linux) | `7F 45 4C 46`             |       |
| PNG         | `89 50 4E 47 0D 0A 1A 0A` |       |
| JPEG        | `FF D8 FF`                |       |
| PDF         | `25 50 44 46`             |       |
| ZIP         | `50 4B 03 04`             |       |
