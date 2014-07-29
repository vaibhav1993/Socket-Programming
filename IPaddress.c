////Ip address Retrieval - for any website Link
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#define serv_tcp_port 7460
#define serv_host_addr "127.0.0.1"
main()
{
char hostname[50];
struct hostent *host;
struct in_addr address;
printf("enter the website address to get the ip address\n");
scanf("%s",&hostname);
host=gethostbyname(hostname);
address.s_addr=*((unsigned long *)host->h_addr);
printf("Ip is %s\n ",inet_ntoa(address));
close(sid);
}
