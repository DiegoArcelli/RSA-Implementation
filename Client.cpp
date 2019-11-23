#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#include <iostream>
#include "ModularArithmetic.h"
#define PORT 8080 

using namespace std;

bool isPrime(unsigned long long int n);
bool areCoprime(unsigned long long int x, unsigned long long int y);

int main(int argc, char const *argv[]) { 

    int sock = 0; 
    struct sockaddr_in serv_addr; 

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 

    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 

    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
        printf("\nConnection Failed \n"); 
        return -1; 
    }
    
    unsigned long long int p,q,n,pn,e;

    //generation of two prime number named p and q 
    do {
        p = rand() % 1000000 + 1;
        q = rand() % 1000000 + 1;
    } while(!isPrime(p) || !isPrime(q));

    cout << "p: " << p << endl;
    cout << "q: " << q << endl;

    //calculation of n = p * q and f(n) = (p - 1) * (q - 1)
    n = p*q;
    pn = (p-1)*(q-1);

    cout << "n: " << n << endl;
    cout << "f(n): " << pn << endl;

    //generation of a number called e coprime of pn end smaller than pn
    do {
        e = rand() % (pn - 2) + 1 ;
    } while(!areCoprime(pn,e));
    cout << "e: " << e << endl;

    //generation of a number e such as e*d = 1 mod f(n)
    unsigned long long int t = 1; 
    ModularArithmetic d(pn,0);
    ModularArithmetic res;
    t = 1;
    do {
        t++;
        d.setNum(t);
        res = d * e;
    } while(res.getNum() != 1);

    cout << "d: " << d.getNum() << endl;

    cout << endl;
    cout << "Public key: (" << n << "," << e << ")" << endl;
    cout << "Pirvate key: (" << n << "," << d.getNum() << ")" << endl;

    unsigned long long int send_n;
    unsigned long long int send_e;
    send_n = htonl(n);
	write(sock,&send_n, sizeof(send_n));
    send_e = htonl(e);
	write(sock,&send_e, sizeof(send_e)); 
	printf("Public key sent to server\nWaiting for the message\n"); 

    ModularArithmetic mes;
    unsigned long long int c;
    do {
        read(sock, &c, sizeof(c));
        c = ntohl(c);
        mes = ModularArithmetic::modularPower(c,d.getNum(),n);
        printf("%c",(unsigned char)mes.getNum());
    } while(mes.getNum() != 10);


	return 0; 
}

bool isPrime(unsigned long long int n){
    unsigned long long int i;
    for(i = 2; i < n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

bool areCoprime(unsigned long long int x, unsigned long long int y){
    unsigned long long int r;
    while(y != 0) {
        r = x % y;
        x = y; 
        y = r;
    }
    if(x == 1)
        return true;
    else
        return false;
}
