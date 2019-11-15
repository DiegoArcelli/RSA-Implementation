# RSA-Implementation

The program works in this way:
- The client performs the operations required in order to create its public key and its private key
- The server opens the connection to the port 8080 and waits for client to connect
- The client establishes the connection and sends its public key to the server
- The server gets a string in input and uses the public key to cipher every character of the string
- The server sends the ciphered characters to the client
- The client uses its private key in order to decipher the characters and print the string
