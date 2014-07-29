//UDP ECHO - CLIENT PROGRAM
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#define serv_tcp_port 7090
#define serv_host_addr "10.10.131.132"
main()
{
int s,sid,clien,nsid;
char buff[30];
struct sockaddr_in seraddr;
sid = socket(AF_INET, SOCK_DGRAM, 0);
if(sid>0)
printf("success");
seraddr.sin_family = AF_INET;
seraddr.sin_port = htons(serv_tcp_port);
seraddr.sin_addr.s_addr = inet_addr(serv_host_addr);
printf("enter the message");
scanf("%s",&buff);

clien = sizeof(seraddr);
sendto(sid,buff,sizeof(buff),0,(struct sockaddr *)&seraddr,sizeof(seraddr));

recvfrom(sid,buff,sizeof(buff),0,(struct sockaddr *)&seraddr,&clien);
printf("echoed message %s\n",buff);
close(sid);
}
