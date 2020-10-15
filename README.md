# RSA-Implementation

The program works in this way:
- The client performs the operations required in order to create its public key and its private key
- The server opens the connection to the port 8080 and waits for client to connect
- The client establishes the connection and sends its public key to the server
- The server gets a string as input and uses the public key to cipher every character of the string
- The server sends the ciphered characters to the client
- The client uses its private key in order to decipher the characters and print the string

The keys are calculated in the following way:
- The program generates two random prime numbers called <i>p</i> and <i>q</i>
- It calculates <i>n = pq</i> and <i>φ(n) = (p - 1)(q - 1)</i>
- It calculates a random number <i>e</i> that is smaller than <i>φ(n)</i> and coprime of <i>φ(n)</i>
- It calculates a random number <i>d</i> such that <i>de ≡ 1 (mod φ(n))</i>
- Now the public key is <i>(n,e)</i> while the private key is <i>(n,d)</i>

The encryption and the decryption of the message work like this:
- The server gets a string as input
- Every character of the string is converted in its corresponding ASCII codification
- The characters are ciphered calculating <i>c = m<sup>e</sup> (mod n)</i>, where <i>m</i> is the ASCII conversion of the character
- When the client receives <i>c</i>, it deciphers it calculating <i>m = c<sup>d</sup> (mod n)</i>
