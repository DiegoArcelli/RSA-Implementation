#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <iostream>
#include "ModularArithmetic.h"
#define PORT 8080 

using namespace std;

int main(int argc, char const *argv[]) {

    int server_fd, new_socket; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
       
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 

    int recv_n;
    int recv_e;
    
    char text[1024];

    cout << "Waiting for the client to connect" << endl;

    read(new_socket, &recv_n, sizeof(recv_n));
    read(new_socket, &recv_e, sizeof(recv_e));

    int n = ntohl(recv_n);
    int e = ntohl(recv_e);

    cout << "Pubblic key: (" << n << "," << e << ")" << endl;
    cout << "Insert message: ";
    fgets(text, 1024, stdin);

    int int_message[strlen(text)];

    ModularArithmetic c;
    unsigned long long int i;
    int m;
    cout << "Ciphered characters:" << endl;
    for(i = 0; i < strlen(text); i++){
        m = (int)text[i];
        c = ModularArithmetic::modularPower(m,e,n);
        int_message[i] = c.getNum();
        cout << c.getNum() << endl;
    }
    for(i = 0; i < strlen(text); i++){
        m = htonl(int_message[i]);
		write(new_socket,&m, sizeof(m)); 
    }
    printf("Ciphered text sent to client\n"); 
    return 0;

}