//Ip address Retrieval - SERVER PROGRAM
#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<string.h>
#include<string.h>
#define serv_tcp_port 7460
#define serv_host_addr "10.10.131.132"
main()
{
int s,sid,pid,clien,nsid;
char buff[50];
struct sockaddr_in seraddr;
struct sockaddr_in cliaddr;
sid=socket(AF_INET,SOCK_STREAM,0);
seraddr.sin_family=AF_INET;
seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
seraddr.sin_port=htons(serv_tcp_port);
s=bind(sid,(struct sockaddr *) &seraddr,sizeof(seraddr));
listen(sid,1);
clien=sizeof(cliaddr);
nsid=accept(sid,(struct sockaddr *)&cliaddr,&clien);
recv(nsid,buff,sizeof(buff),0);
printf("Name is %s\n\n",buff);
close(nsid);
}
