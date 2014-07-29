//UDP ECHO - SERVER PROGRAM
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define serv_tcp_port 7090
#define serv_host_addr "10.10.131.132"
main()
{
int s,sid,clien,nsid;
char buff[30];
struct sockaddr_in seraddr;
struct sockaddr_in cliaddr;

sid = socket(AF_INET, SOCK_DGRAM, 0);
seraddr.sin_family = AF_INET;
seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
seraddr.sin_port = htons(serv_tcp_port);

s = bind(sid, (struct sockaddr *)& seraddr, sizeof(seraddr));

clien = sizeof(cliaddr);

recvfrom(sid,buff,sizeof(buff),0,(struct sockaddr *)&cliaddr,&clien);
printf("message is %s",buff);
sendto(sid,buff,sizeof(buff),0,(struct sockaddr *)&cliaddr,clien);
printf("\necho back");
close(sid);
}
