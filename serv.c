//First socket program
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
int s,sid,pid,clien,nsid;
char buff[30];
struct sockaddr_in seraddr;
struct sockaddr_in cliaddr;

sid = socket(AF_INET, SOCK_STREAM, 0);
seraddr.sin_family = AF_INET;
seraddr.sin_addr.s_addr = htonl(INADDR_ANY);
seraddr.sin_port = htons(serv_tcp_port);

s = bind(sid, (struct sockaddr *)& seraddr, sizeof(seraddr));

listen(sid,1);

clien = sizeof(cliaddr);

nsid = accept(sid,(struct sockaddr *)& cliaddr, &clien);
recv(nsid,buff,sizeof(buff),0);
printf("message is %s",buff);
close(nsid);
}
