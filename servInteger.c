//receive Integer from client
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#define serv_tcp_port 7595
#define serv_host_addr "127.0.0.1"

main()
{
int sid,s,nsid,clien,temp;
char buff[100];
struct sockaddr_in servaddr;
struct sockaddr_in clienaddr;

sid = socket(AF_INET, SOCK_STREAM, 0);

servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(serv_tcp_port);

s = bind(sid, (struct sockaddr*)& servaddr,sizeof(servaddr));

listen(sid,1);

clien = sizeof(clienaddr);

nsid = accept(sid, (struct sockaddr*)& clienaddr,&clien);

recv(nsid,buff,sizeof(buff),0);
printf("%s",buff);
temp = atoi(buff);
printf("\nthe number is %d",temp);

close(nsid);
}
