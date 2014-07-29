//chat between server and client
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#define serv_tcp_port 4270
#define serv_host_addr "10.10.131.132"
main()
{


char rep;
int s,sid,pid,clien,nsid;
char buff[20];
struct sockaddr_in servaddr;
struct sockaddr_in clienaddr;
sid=socket(AF_INET,SOCK_STREAM,0);
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(serv_tcp_port);

s=bind(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));
listen(sid,1);
clien=sizeof(clienaddr);

nsid=accept(sid,(struct sockaddr *)&clienaddr,&clien);
while(1)
{
printf("want to chat..Y or N\n");
scanf("%s",&rep);
if(rep=='Y')
{
recv(nsid,buff,sizeof(buff),0);
printf("message is %s\n",buff);
printf("server enter :\n");
scanf("%s",&buff);
send(nsid,buff,20,0);
}
else if(rep=='N')
{
printf("chat ended !! Godd byeeeeeee");
break;
}
//break;
}
close(nsid);
}
