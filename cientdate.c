//DATE DISPLAY - CLIENT PROGRAM
#include<netinet/in.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#define serv_tcp_port 5286
#define serv_host_addr "10.10.131.132"

main()
{
int s,sid,clien,nsid;
char buff[20];
struct sockaddr_in servaddr;
sid = socket(AF_INET, SOCK_STREAM, 0);
if(sid>0)
printf("successfully connected");
servaddr.sin_family = AF_INET;
servaddr.sin_port = htons(serv_tcp_port);
servaddr.sin_addr.s_addr = inet_addr(serv_host_addr);

connect(sid, (struct sockaddr*)& servaddr, sizeof(servaddr));

recv(sid,buff,100,0);
printf("server time and date  %s\n",buff);
close(sid);
}
