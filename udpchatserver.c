//Chat betweeen server and client (UDP VERSION) SERVER PROGRAM
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define serv_tcp_port 5403
#define serv_host_addr "10.10.131.132"
main()
{


char rep;
int s,sid,pid,clien,nsid;
char buff[20];
struct sockaddr_in servaddr;
struct sockaddr_in clienaddr;
sid=socket(AF_INET,SOCK_DGRAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(serv_tcp_port);

s=bind(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));

clien=sizeof(clienaddr);
while(1)
{
printf("want to chat \n");
scanf("%c",&rep);
if(rep=='y')
{
recvfrom(sid,buff,20,0,(struct sockaddr *)&clienaddr,&clien);
printf("recv from client is :%s",buff);
printf("server enter :\n");
scanf("%s",&buff);
sendto(sid,buff,20,0,(struct sockaddr *)&clienaddr,clien);
}
else
{
printf("chat over\n");
break;
}

}
close(sid);
}
