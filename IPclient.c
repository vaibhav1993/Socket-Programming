////Ip address Retrieval - CLIENT PROGRAM
#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<string.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#define serv_tcp_port 7460
#define serv_host_addr "10.10.131.132"
main()
{
int s,sid,clien,nsid;
char buff[20],hostname[50];
struct sockaddr_in servaddr;
struct sockaddr_in clieaddr;
struct hostent *host;
struct in_addr address;
sid=socket(AF_INET,SOCK_STREAM,0);
if(sid>0)
printf("Success\n");
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(serv_tcp_port);
servaddr.sin_addr.s_addr=inet_addr(serv_host_addr);
connect(sid,(struct sockaddr *)&servaddr,sizeof(servaddr));
gethostname(hostname,sizeof(hostname));
host=gethostbyname(hostname);
if(host==NULL)
{
send(sid,"Unknown Host",20,0);
}
else
{
address.s_addr=*((unsigned long *)host->h_addr);
printf("Ip is %s\n ",inet_ntoa(address));
send(sid,inet_ntoa(address),50,0);
}
close(sid);
}
