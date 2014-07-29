//Chat between server and client (UDP VERSION)- CLIENT PROGRAM
#include<sys/types.h>
#include<arpa/inet.h>
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#define serv_tcp_port 5403
#define serv_host_addr "10.10.131.132"
main()

{

int s,sid,clien,nsid,serv;
char buff[20],rep;
struct sockaddr_in servaddr;
sid=socket(AF_INET,SOCK_DGRAM,0);
if(sid>0)
printf("success");

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);
while(1)
{
printf("wanttochat y or n");
scanf("%c",&rep);
if(rep=='y')
{
printf("enter the data to sent:");
scanf("%s",buff);
sendto(sid,buff,20,0,(struct sockaddr *)&servaddr,sizeof(servaddr));
printf("sent to server successfully\n");
serv=sizeof(servaddr);
recvfrom(sid,buff,20,0,(struct sockaddr *)&servaddr,&serv);
printf("recv from server :%s",buff);
}
else
{
printf("chatover");
break;
}
}
close(sid);
}
