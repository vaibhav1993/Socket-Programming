//send integer to server
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#define serv_tcp_port 7595
#define serv_host_addr "127.0.0.1"

main()
{
int sid;
char buff[100];
struct sockaddr_in servaddr;

sid = socket(AF_INET, SOCK_STREAM, 0);
if(sid>0)
printf("success\n");
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr = inet_addr(serv_host_addr);
servaddr.sin_port = htons(serv_tcp_port);
connect(sid,(struct sockaddr*) &servaddr,sizeof(servaddr));
printf("enter the number");
scanf("%s",&buff);
send(sid, buff, sizeof(buff),0);
close(sid);
}
