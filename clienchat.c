//chat between server and client....cient Program
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#define serv_tcp_port 4270
#define serv_host_addr "10.10.131.132"
main()

{

int s,sid,clien,nsid;
char buff[20],rep;
struct sockaddr_in servaddr;
sid=socket(AF_INET,SOCK_STREAM,0);
if(sid>0)
printf("success");

servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);
connect(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));
while(1)
{
printf("waqnt to chat Y or N ??\n");
scanf("%s",&rep);
if(rep=='Y')
{
printf("client : enter the message\n");
scanf("%s",&buff);
send(sid,buff,20,0);
recv(sid,buff,sizeof(buff),0);
printf("server message is :%s\n",buff);
}
else if(rep=='N')
{
printf("chat ended ..  \n");
break;
}
}
close(sid);
}
